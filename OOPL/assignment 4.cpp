/*
 * operOV.cpp

 *
 *  Created on: Aug 24, 2018
 *      Author: SE
 *
 *
 */

#include<iostream>

using namespace std;

class Add
{
	public:

	int realN;
	int imagN;

	Add operator +(Add &a)
	{
		Add t;
		t. realN = realN + a.realN;
		t.imagN = imagN + a.imagN;

		return t;

	}

	Add operator -(Add &a)
	{
		Add t;
		t. realN = realN - a.realN;
		t.imagN = imagN - a.imagN;
		return t;
	}

	Add operator *(Add &a)
	{
		Add t;
		t. realN = (realN * a.realN) - (imagN * a.imagN);
		t.imagN = (realN * a.imagN) + (imagN * a.realN);
		return t;
	}

	Add operator /(Add &a)
	{
		Add t;
		t.realN=((realN*a.realN)+(imagN*a.imagN))/((a.realN*a.realN)+(a.imagN*a.imagN));
		t.imagN=((imagN*a.realN)-(realN*a.imagN))/((a.realN*a.realN)+(a.imagN*a.imagN));
		return t;
	}


	friend istream & operator >> (istream &in, Add &p)
	{
		in>>p.realN>>p.imagN;
		return in;
	}

	friend ostream & operator << (ostream &out, Add &p)
	{
		out<<p.realN<<" + "<<p.imagN<<" j";
		return out;
	}
};


int main()
{
	Add obj1,obj2,obj3;

	cout<<"enter real and imaginary number for obj1";
	cin>>obj1;
	cout<<"enter real and imaginary number for obj2";
	cin>>obj2;

	char cont;

	do
	{
		cout<<"Choose the operation you want to perform on complex numbers\n\n1. ADDITION\n2. SUBTRACTION\n3. MULTIPLICATION\n4. DIVISION\n";

		int choice;
		cin>>choice;


		switch(choice)
		{
		case 1:
			cout<<"Result is\n\n";
			obj3 = obj1 + obj2;
			cout<<obj3;
			break;

		case 2:
			cout<<"Result is\n\n";
			obj3 = obj1 - obj2;
			cout<<obj3;
			break;

		case 3:
			cout<<"Result is\n\n";
			obj3 = obj1 * obj2;
			cout<<obj3;
			break;

		case 4:
			cout<<"Result is\n\n";
			obj3 = obj1 / obj2;
			cout<<obj3;
			break;
		}

		cout<<"\n\nDO you want to continue ? (y/n)\n\n";
		cin>>cont;

	}while(cont=='y'|| cont=='Y');



	return 0;
}



