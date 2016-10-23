#ifndef __CMD__
#define __CMD__

#include <iostream>
#include <string>


class CmdBase
{
public:
    CmdBase(){};
    virtual ~CmdBase(){};
    
public:
    std::string cmdStr;

    virtual bool run(std::string& cmdStr, std::vector<std::string>& mdVec) = 0;
    virtual void usage(std::vector<std::string>& mdVec)
    {
        std::cout << mdVec[0] << " <option>" << std::endl;
    }
};


class versionCmd: public CmdBase
{
public:
    versionCmd(){};
    ~versionCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


class quitCmd: public CmdBase
{
public:
    quitCmd(){};
    ~quitCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


class helpCmd: public CmdBase
{
public:
    helpCmd(){};
    ~helpCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


class rmCmd: public CmdBase
{
public:
    rmCmd(){};
    ~rmCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    void usage(std::vector<std::string>& mdVec);
};


class echoCmd: public CmdBase
{
public:
    echoCmd(){};
    ~echoCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    void usage(std::vector<std::string>& mdVec);
};


class pwdCmd: public CmdBase
{
public:
    pwdCmd(){};
    ~pwdCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


class calcCmd: public CmdBase
{
public:
    calcCmd(){};
    ~calcCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


class promptCmd: public CmdBase
{
public:
    promptCmd(){};
    ~promptCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
};


#endif