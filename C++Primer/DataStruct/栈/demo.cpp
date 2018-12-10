#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack stack;
	stack.Print();
	/*
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	*/
	for (int i = 0; i < 10240000; i++)
	{
		stack.Push(i);
	}
	stack.Print();

	cout << "****************" << endl;
	stack.Pop();
	stack.Print();
	cout << "****************" << endl;
	stack.Pop();
	stack.Print();
	cout << "****************" << endl;
	stack.Pop();
	stack.Print();
	cout << "****************" << endl;
	stack.Pop();
	stack.Print();
	cout << "****************" << endl;

	return 0;
}
