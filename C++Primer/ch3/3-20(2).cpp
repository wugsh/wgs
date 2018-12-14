#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;
    int iVal;
    cout << "please input a line numbers: " << endl;
    while (cin >> iVal)
    {
        vInt.push_back(iVal);
    }
    if (vInt.size() == 0)
    {
        return -1;
    }
    cout << "首尾两项的和依次为： " << endl;
    for (decltype(vInt.size()) i = 0; i < vInt.size() / 2; i++)
    {
        cout << vInt[i] + vInt[vInt.size() - i - 1] << " ";
        if ((i + 1) % 5 == 0)
            cout << endl;
    }
    if (vInt.size() % 2 != 0)
        cout << vInt[vInt.size() / 2];

    return 0;
}