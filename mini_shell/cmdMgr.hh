#ifndef __CMDMGR__
#define __CMDMGR__

#include <map>
#include <vector>
#include "cmd.hh"


class CmdMgr
{
public:
    CmdMgr();
    ~CmdMgr(){};

    CmdBase* selectCmd(std::string& cmdStr, std::vector<std::string>& mdVec);
    void printVaildCmds();
    void setPrompt(std::string prompt);
    std::string getPrompt();

private:
    std::map<std::string, CmdBase *> mapValidCmd;
    static std::string prompt;
};

#endif