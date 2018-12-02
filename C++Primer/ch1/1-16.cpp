#include <iostream>
using namespace std;

int main()
{
    cout << " 输入一组数据求和：" << endl;
    int v, sum = 0;
    while (cin >> v)
    {
        sum += v;
        //cout << "sum = " << sum << endl;
    }
    cout << sum << endl;
    return 0;
}
