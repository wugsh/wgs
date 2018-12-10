#include <iostream>
using namespace std;

int main()
{
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci;
    auto c = cr;
    auto d = &i;
    auto e = &ci;
    auto &g = ci;
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << endl;

    a = 42;
    b = 42;
    c = 42;
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << g << endl;

    return 0;
}