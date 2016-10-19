#include <vector>
#include "cmdMgr.hh"


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


CmdMgr::CmdMgr()
{
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("version", new versionCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("prompt", new promptCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("quit", new quitCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("help", new helpCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("rm", new rmCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("echo", new echoCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("pwd", new pwdCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("calc", new calcCmd()));
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
        return new inValidCmd();
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
