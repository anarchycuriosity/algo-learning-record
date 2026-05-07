#include <iostream>

//这里必须写引用，否则就是未初始化参数就传入，在主函数中会有warning
//get_score确实进行了赋值，但是main函数中的那个地址并没有发生变化，在get_score作用完了之后依然是老样子
void get_score(double &cchi,double &mmat,double &pphi,double &eeng,double &cche,double &aall,double &aave)
{
    std::cin >> cchi >> mmat >> pphi >> eeng >> cche;
    aall = cchi + mmat + pphi + eeng + cche;
    aave = aall / 5.0;
    std::cout << aall << std::endl;
    std::cout << aave << std::endl;
}

int main()
{
    double chi,mat,phi,eng,che,all,ave;
    get_score(chi,mat,phi,eng,che,all,ave);
    return 0;
}