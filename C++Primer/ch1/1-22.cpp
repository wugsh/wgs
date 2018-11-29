#include <iostream>
#include "/home/wgs/Git/wgs/C++Primer/GCC_pre_C11/1/Sales_item.h"

using namespace std;

int main()
{
    Sales_item total, trans;
    cout << "输入几条ＩＳＢＮ　相同的销售记录：　" << endl;
    if (cin >> total)
    {
        while (cin >> trans)
        {
            if (compareIsbn(total, trans))
            {
                total += trans;
            }
            else
            {
                cout << "ISBN不同" << endl;
                return -1;
            }
        }
        cout << "汇总信息：　ＩＳＢＮ、售出本数、销售额和平均售价为　" << total << endl;
    }
    else
    {
        cout << "没有数据" << endl;
        return -1;
    }
    return 0;
}