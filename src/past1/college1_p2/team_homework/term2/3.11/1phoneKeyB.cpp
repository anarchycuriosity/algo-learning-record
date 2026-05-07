#include <iostream>
#include <vector>

int main()
{
    std::string s;
    std::vector<int> keyB;
    // 如果cin后使用getline要注意写std::cin.ignore()来清空缓存区的换行符否则getline无法读入
    // getline可以选择从文件读也可以选择从键盘读，所以会有一个参数cin
    std::getline(std::cin, s);
    int count = 0;
    for (int i = 1; i <= 15; i++)
    {
        if (i % 3 == 0)
        {
            keyB.emplace_back(3);
        }
        else
        {
            keyB.emplace_back(i % 3);
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        keyB.emplace_back(i);
    }
    for (int i = 1; i <= 3; i++)
    {
        keyB.emplace_back(i);
    }
    for (int i = 1; i <= 4; i++)
    {
        keyB.emplace_back(i);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            count++;
        }
        else
        {
            count += keyB[s[i] - 'a'];
        }
    }
    std::cout << count;
}
/*# P1765 手机
tag:string
simulation
枚举

## 题目描述

一般的手机的键盘是这样的：

![](https://cdn.luogu.com.cn/upload/image_hosting/yq2orii6.png)

要按出英文字母就必须要按数字键多下。例如要按出 $\tt x$ 就得按 $9$ 两下，第一下会出 $\tt w$，而第二下会把 $\tt w$ 变成 $\tt x$。$0$ 键按一下会出一个空格。

你的任务是读取若干句只包含英文小写字母和空格的句子，求出要在手机上打出这个句子至少需要按多少下键盘。

## 输入格式

一行句子，只包含英文小写字母和空格，且不超过 200 个字符。

## 输出格式

一行一个整数，表示按键盘的总次数。

## 输入输出样例 #1

### 输入 #1

```
i have a dream
```

### 输出 #1

```
23
```

## 说明/提示

NOI 导刊 2010 普及（10）*/