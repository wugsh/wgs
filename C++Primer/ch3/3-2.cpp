#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    cout << "please input a line can with a null: " << endl;
    while(getline(cin, line))
         cout << line << endl;
    return 0;
}
