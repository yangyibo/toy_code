#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>

std::map<std::string, std::vector<std::string> > mapStrLib;
int AddSentence(char* sentence);

void Init()
{
	mapStrLib.clear();
}


int ReadFile(char* filename)
{

    char buffer[2048] = {0};
    std::ifstream inf(filename);
    if (!inf.is_open())
    {
        std::cout << "Error opening file";
        exit(1);
    }

    while (!inf.eof() )
    {
        inf.getline(buffer,100);
        std::cout << buffer << std::endl;
        AddSentence(buffer);
    }

    return 0;  
}


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

	return 0;
}


void Fini()
{
	mapStrLib.clear();
}


int Search(char* keyword, int* count, char result[100][100])
{
	std::map<std::string, std::vector<std::string> >::iterator it;
	std::string strKeyword = keyword;
	int indexRet = 0;

	for (it = mapStrLib.begin(); it != mapStrLib.end(); ++it)
	{
		std::cout << "key: " << it->first << std::endl;
		for (int i = 0; i < it->second.size(); i++)
		{
			//std::cout << i << std::endl;
			//std::cout << it->second[i] << std::endl;

			if (0 == strKeyword.compare(it->second[i]))
			{
				(*count)++;
				//printf("count: %d\n", *count);

				strcpy(result[indexRet], (it->first).c_str());
				break;
			}
		}
	}

	return 0;
}


int main(int argc, char const *argv[])
{
    ReadFile("D:\\myfile.txt");
    std::map<std::string, std::vector<std::string> >::iterator it;

	//std::cout << mapStrLib.size() << std::endl;

    //for (it = mapStrLib.begin(); it != mapStrLib.end(); ++it)
    //{
    //    std::cout << "key: " << it->first << std::endl;
    //    for (int i = 0; i < it->second.size(); i++)
    //    {
    //        std::cout << i << std::endl;
    //        std::cout << it->second[i] << std::endl;
    //    }
    //}

	int count = 0;
	char result[100][100] = { 0 };

	Search("xxx", &count, result);

	std::cout << count << std::endl;
	std::cout << result[0] << std::endl;
        

    return 0;
}