#include<stdio.h>
#include <vector>
#include <algorithm>
#pragma warning(disable: 4996)
/*
    功能: 计算两个整数的最大公约数
    参数:
        a: 第一个整数
        b: 第二个整数
    返回值:
        两个整数的最大公约数
*/
int gcd(int a, int b) {
    //在这里写函数实现
    std::vector<int> facs_a;
    std::vector<int> facs_b;
    for (int i = 1; i <= a; i++)
    {
        if (a % i == 0)
        {
            facs_a.emplace_back(i);
        }
    }
    for (int i = 1; i <= b; i++)
    {
        if (b % i == 0)
        {
            facs_b.emplace_back(i);
        }
    }
    std::vector<int> facs_two;
    for (int i = 0; i < facs_a.size(); i++)
    {
        for (int j = 0; j < facs_b.size(); j++)
        {
            if (facs_a[i] == facs_b[j])
            {
                facs_two.emplace_back(facs_b[j]);
            }
        }
    }
    //这里没有根据主函数的判定做非空判定
    if (facs_two.empty())
    {
        return std::max(a, b);
    }
    int max = facs_two[0];
    for (int fac : facs_two)
    {
        if (fac > max)
        {
            max = fac;
        }
    }
    return max;
    
}

/*
    功能: 计算斐波那契数列的第k个数
    参数:
        k: 在斐波那契数列中的位置(从1开始), k的值不大于40
    返回值:
        斐波那契数列的第k个数的值
*/
int fibonacci(int k) {
    //在这里写函数实现
    std::vector<int> fib = { 1,1 };
    for (int i = 2; i <= k; i++)
    {
        int num_fib = fib[i - 1] + fib[i - 2];
        fib.emplace_back(num_fib);
    }
    return fib[k -1 ];
}

/*
    功能: 查找数组中第k大的元素
    参数:
        arr: 整数数组
        size: 数组的大小
        k: 需要查找的位置(从1开始)
    返回值:
        数组中第k大的元素
*/
void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int n = r - l + 1;
    int* tmp = new int[n];
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= m)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for (int t = 0; t < n; t++)
    {
        arr[l + t] = tmp[t];
    }
    delete[] tmp;
}
void merge_sort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);
    merge(arr, l, m, r);
}
int getKthLargest(int arr[], int size, int k) {
    //在这里写函数实现
    int complete = size - k;
    merge_sort(arr, 0, size - 1);
    return arr[complete];
}

/*
    功能: 登录验证
        检查输入的账号和密码是否与存储的数据匹配
    参数:
        accounts: 存储的账号数组
        passwords: 存储的密码数组(与账号对应)
        size: 传入数组的长度
        inputAccount: 用户输入的账号
        inputPassword: 用户输入的密码
    返回值:
        1: 登录成功
        0: 登录失败
*/
int login(int accounts[], int passwords[], int size, int inputAccount, int inputPassword) {
    //在这里写函数实现
    for (int i = 0; i < size; i++)
    {
        if (inputAccount == accounts[i] && inputPassword == passwords[i])
        {
            return 1;
        }
    }
    return 0;
}

/*
    功能: 日期验证
        传入年,月,日三个整数参数,判断这个日期是否合法.
        注意处理闰年的天数问题.
        闰年判断规则:
          1. 年份是4的倍数 -> 是闰年
          2. 但是,年份是100的倍数 -> 不是闰年
          3. 但是,年份是400的倍数 -> 是闰年
    参数:
        year: 年
        month: 月
        day: 日
    返回值:
        0: 日期错误
        1: 日期正确
*/
bool is_leap(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 4 == 0)
    {
        return true;
    }
    return false;
}
int isValidDate(int year, int month, int day) {
    //在这里写函数实现
    if (year < 0)
    {
        return 0;
    }
    if (month > 12 || month < 1)
    {
        return 0;
    }
    int real_day = 0;
    std::vector<int> max_months = { 1,3,5,7,8,10,12 };
    std::vector<int> min_months = { 4,6,9,11 };
    if (month == 2)
    {
        if (is_leap(year))
        {
            real_day = 29;
        }
        else
        {
            real_day = 28;
        }
    }
    if (real_day == 0)
    {
        for (int Month : max_months)
        {
            if (month == Month)
            {
                real_day = 31;
            }
        }
    }
    if (real_day == 0)
    {
        for (int Month : min_months)
        {
            if (Month == month)
            {
                real_day = 30;
            }
        }
    }
    if (real_day == day)
    {
        return 1;
    }
    return 0;
}

int main() {
    printf("测试gcd函数:\n");
    int gcd_test_cases[][3] = {
        {48, 18, 6},
        {7, 13, 1},
        {0, 5, 5},       // 边界情况:一个数字为零
        {12, 12, 12},    // 边界情况:相同数字
        {1071, 462, 21}, // 更大数字:1071和462
        {270, 192, 6}    // 附加测试用例
    };

    for (int i = 0; i < sizeof(gcd_test_cases) / sizeof(gcd_test_cases[0]); i++) {
        int result = gcd(gcd_test_cases[i][0], gcd_test_cases[i][1]);
        printf("gcd(%d, %d) = %d [%s]\n",
            gcd_test_cases[i][0], gcd_test_cases[i][1], result,
            result == gcd_test_cases[i][2] ? "通过" : "失败");
    }
    printf("\n");

    printf("测试fibonacci函数:\n");
    int fib_test_cases[][2] = {
        {1, 1},
        {2, 1},
        {5, 5},
        {10, 55},      // 第10个斐波那契数
        {15, 610},     // 第15个斐波那契数
        {20, 6765}     // 第20个斐波那契数
    };

    for (int i = 0; i < sizeof(fib_test_cases) / sizeof(fib_test_cases[0]); i++) {
        int result = fibonacci(fib_test_cases[i][0]);
        printf("fibonacci(%d) = %d [%s]\n",
            fib_test_cases[i][0], result,
            result == fib_test_cases[i][1] ? "通过" : "失败");
    }
    printf("\n");

    printf("测试getKthLargest函数:\n");
    int arr1[] = { 4, 2, 7, 1, 3, 9, 5, 8, 6 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int kth_test_cases[][3] = {
        {1, 9},  // 第1大
        {2, 8},  // 第2大
        {5, 5},  // 第5大
        {9, 1}   // 第9大(最小)
    };

    for (int i = 0; i < sizeof(kth_test_cases) / sizeof(kth_test_cases[0]); i++) {
        int result = getKthLargest(arr1, size1, kth_test_cases[i][0]);
        printf("getKthLargest(arr1, %d, %d) = %d [%s]\n",
            size1, kth_test_cases[i][0], result,
            result == kth_test_cases[i][1] ? "通过" : "失败");
    }


    printf("测试login函数:\n");
    int accounts[10] = { 1001, 1002, 1003, 1004, 0, 0, 0, 0, 0, 0 };
    int passwords[10] = { 1234, 5678, 9012, 3456, 0, 0, 0, 0, 0, 0 };

    int login_test_cases[][4] = {
        {1001, 1234, 1},  // 正确
        {1002, 5678, 1},  // 正确
        {1001, 9999, 0},  // 错误密码
        {9999, 1234, 0},  // 不存在的账号
        {1003, 9012, 1},  // 正确
        {1004, 0000, 0}   // 错误密码
    };

    for (int i = 0; i < sizeof(login_test_cases) / sizeof(login_test_cases[0]); i++) {
        int result = login(accounts, passwords, 10, login_test_cases[i][0], login_test_cases[i][1]);
        printf("login(%d, %d) = %d [%s]\n",
            login_test_cases[i][0], login_test_cases[i][1], result,
            result == login_test_cases[i][2] ? "通过" : "失败");
    }
    printf("\n");

    printf("测试isValidDate函数:\n");
    // 日期验证测试用例
    int date_test_cases[][4] = {
        {2023, 2, 28, 1},  // 有效日期:平年2月28日
        {2020, 2, 29, 1},  // 有效日期:闰年2月29日
        {2000, 2, 29, 1},  // 有效日期:世纪闰年2月29日
        {2023, 2, 29, 0},  // 无效日期:平年2月29日
        {2023, 4, 31, 0},  // 无效日期:4月31日
        {2023, 13, 1, 0},  // 无效日期:13月
        {0, 1, 1, 0},      // 无效日期:0年
        {2023, 0, 1, 0},   // 无效日期:0月
        {2023, 1, 0, 0},   // 无效日期:0日
        {2023, 12, 31, 1}, // 有效日期:12月31日
        {2023, 11, 30, 1}, // 有效日期:11月30日
        {2023, 10, 31, 1}  // 有效日期:10月31日
    };

    for (int i = 0; i < sizeof(date_test_cases) / sizeof(date_test_cases[0]); i++) {
        int result = isValidDate(date_test_cases[i][0], date_test_cases[i][1], date_test_cases[i][2]);
        printf("isValidDate(%d, %d, %d) = %d [%s]\n",
            date_test_cases[i][0], date_test_cases[i][1], date_test_cases[i][2], result,
            result == date_test_cases[i][3] ? "通过" : "失败");
    }

    return 0;
    system("pause");
}