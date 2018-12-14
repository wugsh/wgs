#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "输入一个字符串： " << endl;
    getline(cin, s);
    for (char &c : s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}