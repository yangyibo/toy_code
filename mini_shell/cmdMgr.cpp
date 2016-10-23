#include <vector>
#include "cmdMgr.hh"


bool inValidCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    std::cout << "invalid cmd!" << std::endl;
    return true;
}


void split(std::string& s, const std::string& delim, std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);

    while (index!=std::string::npos)
    {
        if (!(s.substr(last,index-last)).empty())
        {
            ret->push_back(s.substr(last,index-last));
        }
        last=index+1;
        index=s.find_first_of(delim,last);
    }

    if ( (index-last>0) && (!(s.substr(last,index-last)).empty()) )
    {
        ret->push_back(s.substr(last,index-last));
    }
}

std::string CmdMgr::prompt = "HiShell@";


CmdMgr::CmdMgr(std::map<std::string, CmdBase *> mapValidCmd)
{
    this->mapValidCmd = mapValidCmd;
    this->mapValidCmd.insert(std::pair<std::string, CmdBase *>("invalid", new inValidCmd()));
}


CmdBase* CmdMgr::selectCmd(std::string& cmdStr, std::vector<std::string>& cmdVec)
{
    split(cmdStr, " ", &cmdVec);

    if (mapValidCmd.find(cmdVec[0]) != mapValidCmd.end())
    {
        return mapValidCmd[cmdVec[0]];
    }
    else
    {
        return mapValidCmd["invalid"];
    }
}


void CmdMgr::setPrompt(std::string newPrompt)
{
    prompt = newPrompt;
}


std::string CmdMgr::getPrompt()
{
    return prompt;
}


void CmdMgr::printVaildCmds()
{
    std::cout << "valid commands:" << std::endl;
    for (std::map<std::string, CmdBase *>::iterator it=mapValidCmd.begin(); it!=mapValidCmd.end(); ++it)
    {
        std::cout << it->first << std::endl;
    }
}


void CmdMgr::run()
{
    while (true)
    {
        std::cout << getPrompt() << " ";

        char input[1024 + 1] = {0};
        std::cin.getline(input, 1024);

        if (input[0] == 0)
        {
            continue;
        }

        std::string inputStr = input;

        std::vector<std::string> cmdVec;
        CmdBase* vd = selectCmd(inputStr, cmdVec);
        if (!vd->run(inputStr, cmdVec))
        {
            vd->usage(cmdVec);
        }
    }
}