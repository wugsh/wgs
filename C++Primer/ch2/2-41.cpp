#include <iostream>
#include <string>
using namespace std;

class Sales_data
{
    //友元函数
    friend istream &operator>>(istream &, Sales_data &);
    friend ostream &operator>>(ostream &, const Sales_data &);
    friend bool operator<(const Sales_data &, const Sales_data &);
    friend bool operator==(const Sales_data &, const Sales_data &);

  public: //构造函数的3种形式
    Sales_data() = default;
    Sales_data(const string &book) : bookNo(book) {}
    Sales_data(istream &is) { is >> *this; }

  public:
    Sales_data &operator+=(const Sales_data &);
    string isbn() const { return bookNo; }
};

int main()
{
    return 0;
}