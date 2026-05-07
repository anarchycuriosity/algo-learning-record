#include <iostream>
using namespace std;
bool isreturn(int &id,char cstr[])
    {
        for(int i = 0;i < (id - 1) / 2;i++)
        {
            if(cstr[i] != cstr[id - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
int main()
{
    char str[100];
    char cstr[100];
    cin.getline(str,100);
    int idm = 0;
    int id = 0;
    while(true)
    {
        if(str[idm] >='A' && str[idm] <= 'Z')
        {
            cstr[id++] = str[idm++] + 32;
        }
        else if(str[idm] >= 'a' && str[idm] <= 'z')
        {
            cstr[id++] = str[idm++];
        }
        else
        {
            idm++;
        }

        if(str[idm] == '\0')
        {
            break;
        }
    }
    cstr[id] = '\0';
    

    if(isreturn(id,cstr))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}