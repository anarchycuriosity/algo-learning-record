#include <iostream>
using namespace std;

int main()
{
    string str1;
    cin >> str1;

    string insstr;
    cin >> insstr;

    int insposi;
    cin >> insposi;

    char str2[100];

    int idm = 0;
    for(idm;idm < insposi - 1;idm++)
    {
        str2[idm] = str1[idm];
    }

    int insdigit = 0;
    for(insdigit;insdigit < insstr.size();idm++,insdigit++)
    {
        str2[idm] = insstr[insdigit];
    } 
    
    for(int restdigit = insposi - 1;restdigit < str1.size();idm++,restdigit++)
    {
        str2[idm] = str1[restdigit];
    }

    str2[idm] = '\0';
    
    cout << str2;
    return 0;
}
