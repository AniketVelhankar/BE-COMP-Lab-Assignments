/*
 * STL.cpp
 *
 *  Created on: Sep 28, 2018
 *      Author: SE
 */


#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class STL
{
public:

	void dispStack(stack <int>temp)
	{
		while (!temp.empty())
		{
			cout << '\t' << temp.top();
			temp.pop();
		}
		cout << '\n';
	}

	void dispQueue(queue <int> gq)
	{
		queue <int> g = gq;
		while (!g.empty())
		{
			cout << '\t' << g.front();
			g.pop();
		}
		cout << '\n';
	}
};

int main()
{
	stack<int> s;
	queue<int> q;
	STL obj;
	int ch, choice;
	char cont, cont2;
	int n;

	do
	{

		cout<<"Select 1. Queue 2.Stack";
		cin>>ch;

		if(ch==1)
		{
			do
			{
				cout<<"Select the operation you want to perform\n";
				cout<<"1. Insert \n2. Delete \n3.Display queue \n4.Size of the stack\n";
				cin>>choice;

				switch(choice)
				{
				case 1:
					cout<<"enter the number you want to insert\n";
					cin>>n;
					q.push(n);
					break;
				case 2:
					q.pop();
					break;
				case 3:
					obj.dispQueue(q);
					break;
				case 4:
					cout<<"Size of queue is :"<<q.size()<<endl;
				}

				cout<<"Continue ? (y/n)"<<endl;
				cin>>cont;
			}while(cont == 'y');
		}


		if(ch==2)
		{
			do
			{
				cout<<"Select the operation you want to perform\n";
				cout<<"1. Insert \n2. Delete \n3. Display top \n4. Display stack \n5. Size of the stack\n";
				cin>>choice;

				switch(choice)
				{
				case 1:
					cout<<"enter the number you want to insert\n";
					cin>>n;
					s.push(n);
					break;
				case 2:
					s.pop();
					break;
				case 3:
					cout<<"Stack top is :"<<s.top()<<endl;
					break;
				case 4:
					obj.dispStack(s);
					break;
				case 5:
					cout<<"Size of stack is :"<<s.size()<<endl;
				}

				cout<<"Continue ? (y/n)"<<endl;
				cin>>cont;
			}while(cont == 'y');
		}
		cout<<"Change data structure  ? (y/n)"<<endl;
		cin>>cont2;
	}while(cont2=='y');

		cout<<"\n\nProgram terminated successfully\n";
	return 0;
}
