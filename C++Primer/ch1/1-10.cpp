#include <iostream>
using namespace std;

int main()
{
    int sum;
    int i = 1000;
    cout << "1000+999+998+...+1 = ";
    while (i > 0)
    {
        sum += i;
        i--;
    }
    cout << sum << endl;
    return 0;
}