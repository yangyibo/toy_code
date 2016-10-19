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
    virtual void usage();

};


class inValidCmd: public CmdBase
{
public:
    inValidCmd(){};
    ~inValidCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class versionCmd: public CmdBase
{
public:
    versionCmd(){};
    ~versionCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class quitCmd: public CmdBase
{
public:
    quitCmd(){};
    ~quitCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class helpCmd: public CmdBase
{
public:
    helpCmd(){};
    ~helpCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class rmCmd: public CmdBase
{
public:
    rmCmd(){};
    ~rmCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class echoCmd: public CmdBase
{
public:
    echoCmd(){};
    ~echoCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class pwdCmd: public CmdBase
{
public:
    pwdCmd(){};
    ~pwdCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class calcCmd: public CmdBase
{
public:
    calcCmd(){};
    ~calcCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


class promptCmd: public CmdBase
{
public:
    promptCmd(){};
    ~promptCmd(){};

    bool run(std::string& cmdStr, std::vector<std::string>& mdVec);
    // void usage();
};


#endif