#include <iostream>
#include <string>
using namespace std;

class MyInt {
private:
    int value;
public:
    // 无参构造函数
    MyInt() {
      cout << "无参构造函数被调用" << endl;
    }

    // 有参构造函数
    MyInt(int val) {
	value = val;
      cout << "有参构造函数被调用" << endl;
    }

    // 拷贝构造函数
    MyInt(const MyInt& other) {
	    value = other.value;
      cout << "拷贝构造函数被调用" << endl;
    }

    // 析构函数
    ~MyInt() {
	cout << "析构函数被调用" << endl;
    }

    // 给整型数赋值
    void setValue(int val) {
	value = val;
    }

    // 读取整型数
    int getValue() {
	    return value;
    }

    // 质数判断
    bool isPrime() {
	for(int i = 2;i < value;i++)
    {
        if(value % i == 0)
        {
            return false;
        }
    }
    return true;
    }

    // 回文数判断
    // 回文数判断
    bool isPalindrome() {
    string str = to_string(value);
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}


    // 计算位数
    int countDigits() {
	string str = to_string(value);
    return str.size();
    }
};

int main() {
    int n;
	cin >> n;

	MyInt a;
    a.setValue(n);
    MyInt b(a);
    cout << "值：" << b.getValue() << endl;
    cout << "是否质数：" << (b.isPrime() ? "是" : "否") << endl;
    cout << "是否回文数：" << (b.isPalindrome() ? "是" : "否") << endl;
    cout << "位数：" << b.countDigits() << endl;
	 
    return 0;
}