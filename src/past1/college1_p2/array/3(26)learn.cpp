/*
断言assert在<cassert>中用法如下
1   assert(expression)
2   assert(hint,expression)
如果表达式为1（true）则程序继续，否则终止。这是调试的手段

// 捕获外部变量 threshold
int threshold = 10;
std::sort(nums.begin(), nums.end(),
          [threshold](int a, int b) { return (a % threshold) < (b % threshold); });

当类型复杂一些的时候，就开始使用const 和 &引用
std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) { return a.score < b.score; });
*/