#ifndef __CMDMGR__
#define __CMDMGR__

#include <map>
#include <vector>
#include "cmd.hh"


class inValidCmd: public CmdBase
{
public:
    inValidCmd(){};
    virtual ~inValidCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


class CmdMgr
{
public:
    CmdMgr(){};
    CmdMgr(std::map<std::string, CmdBase *> mapValidCmd);
    virtual ~CmdMgr(){};

    virtual CmdBase* selectCmd(std::string& cmdStr, std::vector<std::string>& mdVec);
    void printVaildCmds();
    void setPrompt(std::string prompt);
    std::string getPrompt();
    void run();

private:
    std::map<std::string, CmdBase *> mapValidCmd;
    static std::string prompt;
};

#endif