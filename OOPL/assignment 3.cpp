/*
 * EmployeeData.cpp

 *
 *  Created on: Sep 21, 2018
 *      Author: SE
 */

#include<iostream>
using namespace std;

class Personal
{
	string name;
	int aadhar_id;

public:
	void getdata()
	{
		cout<<"Enter your name\n";
		cin>>name;
		cout<<"Enter your aadhar id\n";
		cin>>aadhar_id;
	}

	void putdata()
	{
		cout<<"Personal Information is :\n";
		cout<<name<<endl<<aadhar_id<<endl;
	}
};

class Professional
{
	string dept;
	int experience;

public:
	void getdata()
	{
		cout<<"Enter your department\n";
		cin>>dept;
		cout<<"Enter your work experience in years\n";
		cin>>experience;
	}

	void putdata()
	{
		cout<<"Professional Information is :\n";
		cout<<dept<<endl<<experience<<" years"<<endl;
	}
};

class Academic
{
	int marks;
	string classinfo;

public:
	void getdata()
	{
		cout<<"Enter your class info\n";
		cin>>classinfo;
		cout<<"Enter your marks\n";
		cin>>marks;
	}

	void putdata()
	{
		cout<<"Academic Information is :\n";
		cout<<classinfo<<endl<<marks<<endl;
	}
};

class Emp_info: public Personal, public Professional, public Academic
{
public:
	void getdata()
	{
		Personal::getdata();
		Professional::getdata();
		Academic::getdata();
	}

	void putdata()
	{
		Personal::putdata();
		Professional::putdata();
		Academic::putdata();
	}
};


int main()
{

	Emp_info e;

	e.getdata();
	e.putdata();
	return 0;
}
