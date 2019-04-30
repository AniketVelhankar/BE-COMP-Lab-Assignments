/*
 * stdmarks.cpp

 *
 *  Created on: Aug 25, 2018
 *      Author: student
 */


//write cpp program to store marks of student for first test of subject 'DS' fo rN sudents.
//
//Compute
//1. Average score of class
//2. Highest score and lowest score
//3. Marks scored by most of students
//4. List of student who were absent



#include <iostream>

using namespace std;

class student
{
public:
	int marks;
	int roll_no;

	void getdata(void)
	{
		cout<<"Enter your roll number\n";
		cin>>roll_no;
		cout<<"Enter your marks\n";
		cin>>marks;
	}
};


void average(student s[], int n)
{
	int sum=0,average;
	int k=0;

	for(int i=0;i<n;i++)
	{
		if(s[i].marks > 0)
		{
			sum = sum + s[i].marks;
			k++;
		}
	}

	average= sum/k;

	cout<<"\nAverage score of class is : "<<average;
}

void max(student s[], int n)
{
	int maxval=0;

	maxval= s[0].marks;

	for(int i=0;i<n;i++)
	{
		if(maxval<=s[i].marks)
		{
			maxval=s[i].marks;
		}
	}

	cout<<"\nMaximum number of marks is "<<maxval;
}

void min(student s[], int n)
{
	int minval=0;

	minval= s[0].marks;

	for(int i=0;i<n;i++)
	{
		if(minval>=s[i].marks)
		{
			minval=s[i].marks;
		}
	}

	cout<<"\nMinimum number of marks is "<<minval;
}

void absent(student s[],int n)
{
	int count=0;

	for(int i=0;i<n;i++)
	{
		if(s[i].marks==0 || s[i].marks=='\0')
		{
			count++;
		}
	}

	cout<<"\nAbsent students are : "<<count;
}

void frequency(student s[],int n)
{
	int f[20];
	int m = f[0];
	int x = 0;

	for(int i=0; i<n; i++)
	{
		if(s[i].marks>=0)
			f[i] = 1;
		else
			f[i]= 0;
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(s[i].marks == s[j].marks)
				f[i] = f[i] + 1;;
		}
	}

	for(int i=0; i<n; i++)
	{
		if(m<f[i] && f[i]>0)
		{
			m = f[i];
		}
	}

	cout<<"\nMost frequent marks are : "<<s[x].marks<<"\n";
}

int main()
{
	int n;
	student s[20];

	cout<< "Enter number of student in your class\n";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		s[i].getdata();
	}

	average(s,n);
	max(s,n);
	min(s,n);
	absent(s,n);
	frequency(s,n);

	return 1;
}



