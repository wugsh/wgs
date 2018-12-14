#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vInt;
    int i;
    char cont = 'y';
    while (cin >> i)
    {
        vInt.push_back(i);
        cout << "是否继续（y or n)? " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto mem : vInt)
    {
        cout << mem << " ";
    }
    cout << endl;

    return 0;
}