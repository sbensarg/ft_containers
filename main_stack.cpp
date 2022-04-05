#include <iostream>     // std::cout
#if STACK == 1 //CREATE A REAL STL EXAMPLE
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "stack.hpp"
	#include "vector.hpp"
#endif

int main()
{
	{
		std::cout << "constructing stacks\n";
		ft::vector<int> myvector (2,200);        // vector with 2 elements

		ft::stack<int> first;                    // empty stack

		ft::stack<int,ft::vector<int> > third;  // empty stack using vector
		ft::stack<int,ft::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}

	{
		std::cout << "\nstack::empty\n";
		ft::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}

	{
		std::cout << "\nstack::size\n";
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}

	{
		std::cout << "\nstack::top\n";
		ft::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}

	{
		std::cout << "\nstack::push/pop\n";
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
}