#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	Stack stack;
	stack.Print();
<<<<<<< HEAD
	/*
=======

>>>>>>> acc667a887da156786acb560135fc60907e94b56
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
<<<<<<< HEAD
	*/
	for (int i = 0; i < 10240000; i++)
=======
	/*
	for (int i = 0; i < 100; i++)
>>>>>>> acc667a887da156786acb560135fc60907e94b56
	{
		stack.Push(i);
	}
*/
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

	Stack *s = new Stack;
	s->Push(100);
	s->Print();
	s->Pop();
	s->Print();

	return 0;
}
