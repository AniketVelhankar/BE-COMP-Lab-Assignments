#include <iostream>
using namespace std;
class Sorting
{
public:
	void bubbleSort(float a[])
	{
		int i,n = 10,j;
		float value=0;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					value=a[j+1];
					a[j+1]=a[j];
					a[j]=value;
				}
			}
		}
	}
	void selectionSort(float a[])
	{
		int i,j;
		float t;
		for(i=0;i<10;i++)
		{
			for(j=i+1;j<10;j++)
			{
				if(a[j]<a[i])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
	}
	void insertionSort(float a[])
	{
		int i, j, b;
		float t;
		for (i = 1; i < 10; i++)
		{
			t = a[i];
			j = i - 1;
			while (j >= 0 && a[j] > t)
			{
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = t;
			cout<<"\n Iteration:"<<i;
			for (b = 0; b < 10; b++)
			{
				cout<<a[b];
			}
		}
	}

	void display(float x[])
	{
		cout<<"\n Sorted Data:";
		for(int i=0;i<10;i++)
		{
			cout<<"\n"<<x[i];
		}
	}
};
int main()
{
	Sorting a;
	int N=10;
	float x[N];
	cout<<"\n Enter Student Data:";
	for(int i=0;i<N;i++)
	{
		cin>>x[i];
	}
	char ch;
	int opt;
	do
	{
		cout<<"\n Options: \n 1.Bubble Sort \n 2.Insertion Sort \n 3.Selection Sort \n Enter Your Option:)";
		cin>>opt;
		if(opt>4)
		{
			cout<<"\n Invalid Option:(";
			break;
		}
		switch(opt)
		{
		case 1:
			a.bubbleSort(x);
			a.display(x);
			break;
		case 2:
			a.insertionSort(x);
			a.display(x);
			break;
		case 3:
			a.selectionSort(x);
			a.display(x);
			break;
		}
		cout<<"\n Do You Want to Continue?";
		cin>>ch;
	}while(ch=='y');
	return 0;
}




