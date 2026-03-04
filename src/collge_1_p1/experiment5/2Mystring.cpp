#include <iostream>
#include <cstring>
using namespace std;
class MyString
{
    private:
       char *p;
       int len;
    public:
     MyString()
     {
      len = 0;
      p = new char[1];
      p[0] = '\0';
     }
     MyString(const char* s)
     {
      if(s)
      {
         len = strlen(s);//这里返回的不包括'\0'
         p = new char[len + 1];
         strcpy(p,s);//将后面的复制到前面的,都是指针类型
      }
      else
      {
         len = 0;
         p = new char[1];
         p[0] = '\0';
      }
     }

     MyString(MyString & mystr2)
     {
        len = mystr2.len;
        p = new char[len + 1];
        strcpy(p,mystr2.p);
     }
     void show()
     {
        cout << p << endl;
     }
     ~MyString()
     {//必须用[]
        delete[] p;
     };
};

int main()
{
   //char *s;
   char s[100];
   cout << "输入字符串s" << endl;
   cin.getline(s,100);

   MyString mystring(s);
   cout << "输出mystring" << endl;
   mystring.show();

   cout << "复制输出字符串mystring2" << endl;
   MyString mystring2 = mystring;
   mystring2.show();
   return 0;
}