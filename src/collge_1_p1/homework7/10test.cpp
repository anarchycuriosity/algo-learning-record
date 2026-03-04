#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void ftoa(double f, char s[]) {
    // 处理特殊情况：0
    if (f == 0.0) {
        s[0] = '0';
        s[1] = '\0';
        return;
    }
    
    // 处理负数
    int index = 0;
    if (f < 0) {
        s[index++] = '-';
        f = -f;
    }
    
    // 分离整数部分和小数部分
    long long intPart = (long long)f;
    double fracPart = f - intPart;
    
    // 转换整数部分
    char intBuffer[50];
    int intIndex = 0;
    
    if (intPart == 0) {
        intBuffer[intIndex++] = '0';
    } else {
        // 临时存储整数位的数字（逆序）
        char temp[50];
        int tempIndex = 0;
        
        while (intPart > 0) {
            temp[tempIndex++] = '0' + (intPart % 10);
            intPart /= 10;
        }
        
        // 反转得到正确的顺序
        for (int i = tempIndex - 1; i >= 0; i--) {
            intBuffer[intIndex++] = temp[i];
        }
    }
    intBuffer[intIndex] = '\0';
    
    // 复制整数部分到结果字符串
    for (int i = 0; i < intIndex; i++) {
        s[index++] = intBuffer[i];
    }
    
    // 处理小数部分
    if (fracPart > 1e-10) {  // 避免浮点精度问题
        s[index++] = '.';
        
        // 转换小数部分（最多6位）
        int maxDecimalPlaces = 6;
        int decimalCount = 0;
        
        while (fracPart > 1e-10 && decimalCount < maxDecimalPlaces) {
            fracPart *= 10;
            int digit = (int)fracPart;
            s[index++] = '0' + digit;
            fracPart -= digit;
            decimalCount++;
        }
    }
    
    s[index] = '\0';
}

int main() {
    double number;
    char buffer[100];
    
    cin >> number;
    
    // 调用转换函数
    ftoa(number, buffer);
    
    // 逐个字符输出，用空格隔开
    int len = strlen(buffer);
    for (int i = 0; i < len; i++) {
        cout << buffer[i];
        if (i < len - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}