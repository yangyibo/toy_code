#include "cmdMgr.hh"


int main(int argc, char const *argv[])
{
    std::map<std::string, CmdBase *> mapValidCmd;
    
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("version", new versionCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("prompt", new promptCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("quit", new quitCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("help", new helpCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("rm", new rmCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("echo", new echoCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("pwd", new pwdCmd()));
    mapValidCmd.insert(std::pair<std::string, CmdBase *>("calc", new calcCmd()));

    CmdMgr cmdMgr(mapValidCmd);
    cmdMgr.run();

    return 0;
}