#include <stdlib.h>
#include <vector>
#include "cmdMgr.hh"


void CmdBase::usage()
{
    std::cout << "cmd <option>" << std::endl;
}


bool inValidCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    std::cout << "invalid cmd!" << std::endl;
    return true;
}


bool versionCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    std::cout << "simuShell V1R1C00, yangyibo 00318985, 20161016" << std::endl;
    return true;
}


bool quitCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    std::cout << "bye bye" << std::endl;
    exit(0);
}


bool helpCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    CmdMgr cm;
    cm.printVaildCmds();
    return true;
}


bool pwdCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    system("pwd");
    return true;
}


bool calcCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    system("calc");
    return true;
}


bool promptCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    std::cout << "please input new prompt: ";

    char newPrompt[1024 + 1];
    std::cin.getline(newPrompt, 1024);

    CmdMgr cm;
    cm.setPrompt(newPrompt);

    return true;
}


bool echoCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    std::cout << cmdStr.substr(cmdStr.find_first_of(" ") + 1) << std::endl;
    return true;
}


bool rmCmd::run(std::string& cmdStr, std::vector<std::string>& mdVec)
{
    system(cmdStr.c_str());

    return true;
}