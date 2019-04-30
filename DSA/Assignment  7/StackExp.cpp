/*
 * StackExp.cpp
 *
 *  Created on: Sep 26, 2018
 *      Author: student
 */


#include <iostream>
using namespace std;

class StackExp
{
	int top;
	char stk[20];
public:

	StackExp()
{
		top=-1;
}

	void push(char ch)
	{
		top=top+1;
		stk[top]=ch;
	}

	char pop()
	{
		char temp;
		temp=stk[top];
		top=top-1;
		return temp;
	}

	int isfull()
	{
		if(top==20)
			return 1;
		else
			return 0;
	}

	int isempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}

	bool ChkPar(string expr)
	{
		char x;

		for (int i=0; i<expr.length(); i++)
		{
			if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
			{
				// Push the element in the stack
				push(expr[i]);
				continue;
			}

			// IF current character is not opening
			// bracket, then it must be closing. So stack
			// cannot be empty at this point.
			if (isempty())
				return false;

			switch (expr[i])
			{
			case ')':

				// Store the top element in a
				x = pop();

				if (x=='{' || x=='[')
					return false;
				break;

			case '}':

				// Store the top element in b
				x = pop();
				if (x=='(' || x=='[')
					return false;
				break;

			case ']':

				// Store the top element in c
				x = pop();

				if (x =='(' || x == '{')
					return false;
				break;
			}
		}
		// Check Empty Stack
		return (isempty());
	}
};

int main()
{
	StackExp s1;
	char choice;
	string exp;

	do
	{

		cout<<"\nEnter the expression to check whether it is in well form or not :  ";
		cin>>exp;

		if(s1.ChkPar(exp))
		{
			cout<<"Balanced\n";
		}
		else
		{
			cout<<"Not balanced\n";
		}

		cout<<"Do you want to continue ? (y/n)\n";
		cin>>choice;

	}while(choice=='y');

	cout<<"\nThanks ! Program terminated successfully...";

	return 0;
}


