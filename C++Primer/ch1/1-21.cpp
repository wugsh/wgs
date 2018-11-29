#include <iostream>
#include "/home/wgs/Git/wgs/C++Primer/GCC_pre_C11/1/Sales_item.h"

using namespace std;

int main()
{
    Sales_item trans1, trans2;
    cout << "输入两条ISBN相同的销售记录: " << endl;
    cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        cout << "汇总信息：　ISBN、售出本数、销售额和平均售价为　" << trans1 + trans2 << endl;
    }
    else
    {
        cout << "两条销售记录的ISBN不同" << endl;
    }

    return 0;
}