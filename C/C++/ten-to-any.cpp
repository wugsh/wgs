/*************************************************************************
	> File Name: ten-to-any.cpp
	> Author: Gaosheng Wu
	> Mail: wugsh15@gmail.com 
	> Created Time: Thu 07 Sep 2017 10:08:33 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main()
{
	long n;
	int p, c, m = 0, s[100];
	cout << "please input a nummber which you want translate: " << endl;
	cin >> n;
	cout << "please input 进制: " << endl;
	cin >> p;

	cout << "(" << n << ")10 = " << "(";

	while (n != 0){
		c = n % p;
		n = n / p;
		s[m++] = c;
	}
	for (int k = m; k >= 0; k--){
		if(s[k] >= 10)
			cout << (char)(s[k] + 55);
		else
			cout << s[k];
	}
	cout << ")" << p << endl;

	return 0;
}
