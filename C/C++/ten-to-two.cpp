/*************************************************************************
	> File Name: ten-to-two.cpp
	> Created Time: Wed 06 Sep 2017 11:35:25 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void printbinary(const unsigned int val)
{
	for (int i = 16; i >= 0; i--){
		if (val & (1 << i))
			cout << "1";
		else
			cout << "0";
	}
}
int main()
{
	printbinary(1024);
	return 0;
}
