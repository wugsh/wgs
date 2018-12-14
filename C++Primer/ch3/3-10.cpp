#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cout << "input a line string: " << endl;
    getline(cin, s);
    for (auto c : s)
    {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
    
    return 0;
}