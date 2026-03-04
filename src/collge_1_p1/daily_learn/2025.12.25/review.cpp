#include <map>
/*
不要混淆&的含义，这可以是取地址，也可以是变量的别名。比如写=&[变量名]表示取地址，而在参数列表中，则是变量别名

聊聊一些特殊的遍历的方法
for (类型 变量 : 容器或数组) {
    // 使用变量进行操作
}
for(char  ch : string(str))这里str的前身是一个char*需要进行转化，string相当于一个容器，当然最好是用vector那些
for(int &num : vector<int> nums)如果要进行更改一定要写引用，否则这里的 num 是 值拷贝，也就是说每次循环都会把容器里的元素复制一份到 n，你修改的是副本，原始容器里的数据不会变。

现在聊聊stl容器的一些特殊的for循环遍历手法
1(auto &it:[stl容器])
2以map举例  for(std::map<std::string,int>::iterator it = mp.begin(); it != mp.end();it++)
3 std::map<std::string,int>::iterator 把这一串改成auto& 然后同上
*/
