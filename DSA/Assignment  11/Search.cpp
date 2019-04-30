/*
 * Search.cpp
 *
 *  Created on: Aug 29, 2018
 *      Author: student
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void linearS(int p, int arr[], int n)
{
	int i;
	for(i=0;i<p;i++)
	{
		if(n==arr[i])
		{
			cout<<"Element found at index "<<i<<endl;
			break;
		}
		else
			continue;
	}
	if(i==p)
		cout<<"Element not found";
}

void sentinalS(int p,int arr[],int n)
{
	arr[p] = n;
	int i;

	for(i=0;;i++)
	{
		if(arr[i] == n )
			break;
	}
	if(i==p)
		cout<<"Element not found !";
	else
		cout<<"Element found at index "<<i<<endl;
}

int main()
{
//	srand(time(NULL));
//
//	for(int i=0;i<10;i++)
//	{
//		int num =  1 + (rand() % (int) (10-1)+1);
//		cout<<num<<endl;
//	}

	int present[100], count, choice, number;
	char ch;

	cout<<"enter number of present students"<<endl;
	cin>>count;

	cout<<"enter the roll numbers of present students"<<endl;

	for(int i=0;i<count;i++)
	{
		cin>>present[i];
	}

	do
	{
		cout<<"Select operation you want to perform\n1. Linear Search\n2. Sentinal search\n";
		cin>>choice;

		switch (choice)
		{
		case 1:
			cout<<"enter the number that you want to search";
			cin>>number;
			linearS(count,present,number);
			break;
		case 2:
			cout<<"enter the number that you want to search";
			cin>>number;
			sentinalS(count,present,number);
			break;
		}

		cout<<"\nContinue ? (y/n)";
		cin>>ch;
	}while(ch=='y'|| ch=='Y');

	cout<<"Program terminated successfully !";

	return 0;
}



