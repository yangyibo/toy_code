#include <vector>
#include <iostream>
#include <string>


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


std::string& trim(std::string &s) 
{
    if (s.empty()) 
    {
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}


int main(int argc, char const *argv[])
{
    std::string str = " abc def   rrr       ";

    std::vector<std::string> vec;
    split(str, " ", &vec);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i]<< std::endl;
    }

    return 0;
}