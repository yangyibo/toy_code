#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
#include <vector>

std::map<std::string, std::vector<std::string> > mapStrLib;


int AddSentence(char* sentence)
{
    std::string strSentence = sentence;
    std::vector<std::string> vecStr;

    int iBegin = 0;
    int iEnd = 0;

    while (0 != sentence[iBegin])
    {
        while ( ('a' <= sentence[iEnd] && sentence[iEnd] <= 'z') || ('A' <= sentence[iEnd] && sentence[iEnd] <= 'Z') )
        {
            //std::cout << sentence[iEnd] << std::endl;
            //printf("%c\n", sentence[iEnd]);
            //std::cout << "111" << std::endl;
            iEnd++;
        }

        //std::cout << "iBegin: " << iBegin << std::endl;
        //std::cout << "iEnd: " << iEnd << std::endl;

        std::string strTmp;
        strTmp.assign(sentence, iBegin, iEnd - iBegin);
        //std::cout << "strTmp: " << strTmp << std::endl;
        vecStr.push_back(strTmp);

        while ( (sentence[iEnd] < 'A') || ((sentence[iEnd] > 'Z') && (sentence[iEnd] < 'a')) || (sentence[iEnd] > 'z') )
        {
            if (0 == sentence[iEnd])
            {
                break;
            }
            //std::cout <<"222" << std::endl;
           // printf("%c\n", sentence[iEnd]);
            iEnd++;
        }
        iBegin = iEnd;
    }

    mapStrLib.insert(std::pair<std::string, std::vector<std::string> >(strSentence, vecStr));
}


int main(int argc, char const *argv[])
{
    char sentence[100] = "aaa bbb, ccc ddd.";

    AddSentence(sentence);

    for (int i = 0; i < mapStrLib[sentence].size(); i++)
    {
        std::cout << i << std::endl;
        std::cout << mapStrLib[sentence][i] << std::endl;
    }


    
    return 0;
}