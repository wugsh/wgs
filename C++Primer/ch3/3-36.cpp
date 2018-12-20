#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 5;
    int a[sz], b[sz], i;
    srand((unsigned)time(NULL));
    for (i = 0; i < sz; i++)
    {
        a[i] = rand() % 10;
    }
    cout << "请输入5个数组（0~9），可以重复： " << endl;
    int uVal;
    for (i = 0; i < sz; i++)
    {
        if (cin >> uVal)
            b[i] = uVal;
    }
    cout << "系统生成的数据是： " << endl;
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    cout << "猜的数据是： " << endl;
    for (auto val : b)
        cout << val << " ";
    cout << endl;
    int *p = begin(a), *q = begin(b);
    while (p != end(a) && q != end(b))
    {
        if (*p != *q)
        {
            cout << "猜测错误，两个数组不相等" << endl;
            return -1;
        }
        p++;
        q++;
    }
    cout << "猜对了！" << endl;
    return 0;
}