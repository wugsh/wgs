#include <iostream>
#include "/home/wgs/Git/wgs/C++Primer/GCC_pre_C11/1/Sales_item.h"
using namespace std;

int main()
{
    Sales_item trans1, trans2;
    int num = 1;
    cout << "请输入若干销售记录: " << endl;

    if (cin >> trans1)
    {
        while (cin >> trans2)
        {
            if (compareIsbn(trans1, trans2))
            {
                num++;
            }
            else
            {
                cout << trans1.isbn() << "共有" << num << "条销售记录" << endl;
                trans1 = trans2;
                num = 1;
            }
        }
        cout << trans1.isbn() << "共有" << num << "条销售记录" << endl;
    }
    else
    {
        cout << "没有数据" << endl;
        return -1;
    }
    return 0;
}
