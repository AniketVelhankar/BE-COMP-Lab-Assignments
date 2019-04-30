/*
 * Files.cpp
 *
 *  Created on: Sep 7, 2018
 *      Author: SE
 */



#include<iostream>
#include<fstream>

using namespace std;

class Files
{
	int rollno, marks;

public:

	void getdata()
	{
		cout<<"Enter your roll no"<<endl;
		cin>>rollno;
		cout<<"Enter your total marks"<<endl;
		cin>>marks;
	}

	void putdata()
	{
		cout<<"Roll no - "<<rollno<<endl;
		cout<<"Marks - "<<marks<<endl;
	}

};

int main()
{
	Files f[5];
	char ch;

	for(int i=0;i<5;i++)
	{
		f[i].getdata();

		ofstream os("Stud.txt");
		os.write((char*) &f[i], sizeof(f[i]));

		cout<<"Data written onto file successfully"<<endl;
	}

	ifstream is("Stud.txt");
	is.seekg(0);

	for(int i=0;i<5;i++)
	{
		is.read((char*) &f[i], sizeof(f[i]));
		f[i].putdata();
	}

	return 0;
};
