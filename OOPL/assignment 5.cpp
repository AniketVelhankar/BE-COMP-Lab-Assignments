/*
 * Quad.cpp

 *
 *  Created on: Aug 31, 2018
 *      Author: SE
 */

#include<iostream>
#include<math.h>

using namespace std;

class Quadratic
{
	int a,b,c;

public:

	Quadratic()
{
		a = 0;
		b = 0;
		c = 0;
}

	Quadratic(int n1, int n2, int n3)
	{
		a=n1;
		b=n2;
		c=n3;
	}

	Quadratic operator +(Quadratic &no2)
	{
		Quadratic t;
		t.a = a + no2.a;
		t.b = b + no2.b;
		t.c = c + no2.c;

		return t;
	}

	friend istream & operator >> (istream &in, Quadratic &p)
	{
		cout<<"enter coefficient of x^2";
		in>>p.a;
		cout<<"enter coefficient of x^1";
		in>>p.b;
		cout<<"enter coefficient of x^0";
		cin>>p.c;
		return in;
	}

	friend ostream & operator << (ostream &out, Quadratic &p)
	{
		out<<p.a<<" x^2 + "<<p.b<<"x^1 + "<<p.c<<" x^0";
		return out;
	}

	int eval(int no)
	{
		int sum = 0;

		sum = a * (pow(no,2)) + b * (pow(no,1)) + c;

		return sum;

	}

	void solve()
	{
		int desc = (pow(b,2)) - (4*(a*c));
		cout<<"The value of determinant is : "<<desc;

		if(desc == 0)
			cout<<"\nEquation will have one real solution";
		else if(desc>0)
			cout<<"\nEquation will have two real solutions";
		else
			cout<<"\nEquation will have a pair complex solutions";

		float x1= ((0-b) + sqrt(desc))/(2*a);
		float x2= ((0-b) - sqrt(desc))/(2*a);

		cout<<endl<<x1<<" or "<<x2;

	}

};


int main()
{
	Quadratic num1,num2(5,6,1), num3;

	int choice;
	char ch;

	do
	{
		cout<<"Enter the operation you want to perform :\n1. Add quadratic equation\n2. Evaluate quadratic equation\n3. Solve quadratic equation\n" ;

		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"enter the quadratic equation to be added\n";
			cin>>num1;

			num3 = num1+num2;

			cout<<"\nThe resultant polynomial is\n";
			cout<<num3;
			break;

		case 2:
			int x;
			cout<<"\n\nEnter x for which you want to evaluate the value of polynomial";
			cin>>x;
			cout<<"For x = "<<x<<", Value of polynomial is : "<< num2.eval(x);
			break;

		case 3:
			cout<<"\nSolving quadratic equations-\n\n";
			num2.solve();
			break;
		}

		cout<<"\nContinue ? (y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');

	cout<<"Program terminated successfully, Thanks..";

	return 0;
}

