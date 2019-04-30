/*
 * calc.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: SE
 */

#include <iostream>

using namespace std;

void add()
{
	cout<<"Enter number one"<<endl;
	int fno;
	cin>>fno;
	cout<<"enter number two"<<endl;
	int sno;
	cin>>sno;
	int result = fno+sno;
	cout<<fno<<" + "<<sno<<" = "<<result;
}

void subs()
{
	cout<<"Enter number one"<<endl;
	int fno;
	cin>>fno;
	cout<<"enter number two"<<endl;
	int sno;
	cin>>sno;
	int result = fno-sno;
	cout<<fno<<" - "<<sno<<" = "<<result;

}

void mult()
{
	cout<<"Enter number one"<<endl;
	int fno;
	cin>>fno;
	cout<<"enter number two"<<endl;
	int sno;
	cin>>sno;
	int result = fno*sno;
	cout<<fno<<" * "<<sno<<" = "<<result;
}

void divd()
{
	cout<<"Enter number one"<<endl;
	int fno;
	cin>>fno;
	cout<<"enter number two"<<endl;
	int sno;
	cin>>sno;
	int result = fno/sno;
	cout<<fno<<" / "<<sno<<" = "<<result;
}


int main()
{
  cout<<"Enter type of operation you want to perform"<<endl;
  cout<<"1. Addition"<<endl<<"2. Subtraction"<<endl<<"3. Multiplication"<<endl<<"4. Division"<<endl;
  int choice ;
  cin>>choice;
  char cont;
  do
  {
	  switch(choice)
	    {
	    case 1:
	  	add();
	  	break;
	    case 2:
	  	  subs();
	  	  break;
	    case 3:
	  	  mult();
	  	  break;
	    case 4:
	  	  divd();
	  	  break;
	    }
	cout<<"\n\nContinue ? (y/n)";
	cin>>cont;
  }while(cont=='y'|| cont=='Y');

  return 0;
}



