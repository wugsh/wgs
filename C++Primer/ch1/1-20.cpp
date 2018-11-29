#include <iostream>
#include "/home/wgs/Git/wgs/C++Primer/GCC_pre_C11/1/Sales_item.h"

using namespace std;

int main()
{
    Sales_item book;
    cout << "请输入销售记录： " << endl;
    while (cin >> book) {
        cout << "ISBN、 输出本数、销售额和平均售价为： " << book << endl;
    }    
    return 0;
}