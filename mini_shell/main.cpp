#include <iostream>
#include "cmdMgr.hh"

//std::string CmdBase::prompt = "HiShell@";

int main(int argc, char const *argv[])
{
    CmdMgr cmdMgr;

    while (true)
    {
        std::cout << cmdMgr.getPrompt() << " ";

        char input[1024 + 1] = {0};
        std::cin.getline(input, 1024);
        //std::cout << "inputStr: " << inputStr << std::endl;

        if (input[0] == 0)
        {
            continue;
        }

        std::string inputStr = input;

        std::vector<std::string> cmdVec;
        CmdBase* vd = cmdMgr.selectCmd(inputStr, cmdVec);
        if (!vd->run(inputStr, cmdVec))
        {
            vd->usage();
        }
    }

    return 0;
}