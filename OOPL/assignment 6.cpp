/*
 * StudentDatabase.cpp
 *
 *  Created on: Sep 21, 2018
 *      Author: SE
 */

#include<iostream>

using namespace std;

class StudentDatabase
{
	string *name, division, batch, email, blood_group, address;
	int roll_number, dob;
	static int count;
	long *tel, license;

public:

	StudentDatabase()
{
		name = new string;
		tel = new long;
		updatecount();
}

	StudentDatabase(int roll_number)
	{
		this->roll_number = roll_number;
	}

	StudentDatabase(StudentDatabase &c)
	{
		roll_number = c.roll_number;
	}

	~StudentDatabase()
	{
		delete name;
		delete tel;
	}

	inline void getdata()
	{
		cout<<"enter your name";
		cin>>*name;
		cout<<"Enter your date of birth";
		cin>>dob;
		cout<<"Enter your division and batch\n";
		cin>>division;
		cin>>batch;
		cout<<"Enter your Blood group\n";
		cin>>blood_group;
		cout<<"Enter your permanent address\n";
		cin>>address;
		cout<<"enter your telephone number";
		cin>>*tel;
		cout<<"Enter your license number";
		cin>>license;

	}

	void putdata()
	{
		cout<<"\n\nDetails are are as follows\n";
		cout<<"Name: "<<*name<<endl;
		cout<<"Date of birth : "<<dob<<endl;
		cout<<"Blood group is :"<<blood_group<<endl;
		cout<<"Division : "<<division<<endl;
		cout<<"Batch : "<<batch<<endl;
		cout<<"Email is : "<<email<<endl;
		cout<<"Your address is : "<<address<<endl;
		cout<<"Your telephone number is :"<<*tel<<endl;
		cout<<"Your License number is :"<<license<<endl;

	}

	static void updatecount()
	{
		count++;
	}

	static int retCount()
	{
		return count;
	}

	friend class StudentDB;
};

int  StudentDatabase:: count = 0;

class StudentDB
{
	StudentDatabase sdb;
	string mail;
	public:

	void setEmail()
	{
		cout<<"Enter your mail";
		cin>>sdb.email;
	}

};


int main()
{
	StudentDatabase s1 ,s2(2), s3(3),s4(s3);
	StudentDB sd;

	int no;


	cout<<"Enter student 1 information\n";
	s1.getdata();
	sd.setEmail();
	s1.putdata();

/*
	cout<<"Enter student 2 information\n";
	s2.getdata();

	cout<<"Enter student 3 information\n";
	s3.getdata();


	cout<<"\nStudent 1 details are:\n";
	s1.putdata();

	cout<<"Student 2 details are:\n";
	s2.putdata();

	cout<<"Student 3 details are:\n";
	s3.putdata();

	cout<<"Student 4 details are:\n";
	s4.putdata();
*/


	no = s1.retCount();

	cout<<"Number of students is : "<<no;

	return 0;

}
