#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    cout << "please input a word:" << endl;
    while (cin >> word)
        cout << word << endl;
    return 0;
}