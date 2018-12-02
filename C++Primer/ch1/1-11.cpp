#include <iostream>

using namespace std;

int main()
{
    int v1, v2;
    cout << "请输入两个整数：" << endl;

    cin >> v1 >> v2;
    if (v1 > v2)
    {
        while (v1 >= v2)
        {
            cout << v1-- << " ";
        }
        cout << endl;
    }
    else if (v1 < v2)
    {
        while (v1 <= v2)
        {
            cout << v1++ << " ";
        }
        cout << endl;
    }
    else
    {
        cout << v1 << endl;
    }

    return 0;
}