#include <iostream>
using namespace std;

int main()
{
    cout << "1+2+3+...+100 = " ;
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }
    cout << sum <<endl;
    return 0;
}