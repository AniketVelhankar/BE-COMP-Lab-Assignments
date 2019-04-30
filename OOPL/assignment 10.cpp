/*
 * SelectionSort.cpp

 *
 *  Created on: Sep 7, 2018
 *      Author: SE
 */

#include<iostream>

using namespace std;

template <class T>
void selectionS(T x[], int n)
{
	int temp;

	cout<<"\nArray before sorting \n";

	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<"\t";
	}

	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(x[j]<x[i])
			{
				temp=x[j];
				x[j] = x[i];
				x[i]=temp;
			}
		}
	}

	cout<<"\nSorted array is \n";

	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<"\t";
	}
}


int main()
{
	int size=0, arr[100];
	float arr2[100];

		cout<<"enter the size of array"<<endl;
		cin>>size;

		cout<<"enter the array elements"<<endl;
		for(int i=0;i<size;i++)
		{
			cin>>arr[i];
		}
		selectionS(arr,size);

		cout<<"\n"<<"enter the size of array"<<endl;
		cin>>size;

		cout<<"enter the array elements"<<endl;
		for(int i=0;i<size;i++)
		{
			cin>>arr2[i];
		}
		selectionS(arr2,size);


	return 0;
}


