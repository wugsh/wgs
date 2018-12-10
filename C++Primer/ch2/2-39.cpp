#include <iostream>
#include <typeinfo>
using namespace std;

struct book
{
    string boolNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

int main()
{
    cout << typeid(book).name() << endl;

    return 0;
}