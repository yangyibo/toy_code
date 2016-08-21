#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

void translateCharToInt(char* s)
{
    while (0 != *s)
    {
        if ('0' <= *s && *s <= '9')
        {
            *s -= '0';
        }
        else if ('a' <= *s && *s <= 'z')
        {
            *s -= ('a' - 10);
        }
        s++;
    }
}


void translateIntToChar(char* s, int len)
{
    //cout << "len" << len << endl;
    while (len >= 0)
    {
        //cout << "len: " << (int)s[len] << endl;
        if (0 <= s[len] && s[len] <= 9)
        {
            s[len] += '0';
            //cout << "---len: " << (int)s[len] << endl;
        }
        else if (10 <= s[len] && s[len] <= 35)
        {
            s[len] += ('a' - 10);
            
        }
        len--;
    }
}


void handleCarry(int n, char* result)
{
    int num = strlen(result) - 1;

    while (num > 0)
    {
        if (result[num] >= n)
        {
            result[num - 1] += 1;
            result[num] -= n;
        }

        num--;
    }

    if (result[0] >= n)
    {
        cout << "1";
        result[0] -= n;
    }
}


int Calc(int n, const char* num1, const char* num2, char* result)
{
    char *tmpNum1 = (char *)malloc(strlen(num1) + 1);
    char *tmpNum2 = (char *)malloc(strlen(num2) + 1);

    strcpy(tmpNum1, num1);
    strcpy(tmpNum2, num2);

    translateCharToInt(tmpNum1);
    translateCharToInt(tmpNum2);

    int i = strlen(tmpNum1) - 1;
    int j = strlen(tmpNum2) - 1;
    int k = i > j ? i : j;
    int len = k;

    while (k >= 0)
    {

        if (i < 0)
        {
            result[k] = tmpNum2[j];
        }
        else if (j < 0)
        {
            result[k] = tmpNum1[i];
        }
        else
        {
            result[k] = tmpNum1[i] + tmpNum2[j];
        }

        cout << (int)result[k] << endl;
        
        k--;
        i--;
        j--;
    }

    handleCarry(n, result);
    translateIntToChar(result, len);

    return 0;
}


int main(int argc, char const *argv[])
{
    char result[10] = {0};
    Calc(20, "b23", "b11", result);

    cout << result << endl;

    return 0;
}