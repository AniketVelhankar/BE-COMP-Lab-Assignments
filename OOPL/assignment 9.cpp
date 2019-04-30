/*
 * FindAndReplace.cpp
 *
 *  Created on: Sep 21, 2018
 *      Author: SE
 */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string data="";
	cout<<argc;
	ifstream is(argv[1]);

	if(!is)
	{
		cout<<"\n File not found !";
		return 0;
	}

	if(argc != 4)
	{
		cout<<"invalid arguments";
		return 0;
	}

	//	unsigned int found;
	string s2 = argv[2];
	string replace_data;
	while(is)
	{

		getline(is,data);
		//		found = data.find(s2);

		while(data.find(s2) < string::npos)
		{
			data.replace(data.find(s2), s2.size(), argv[3]);
			//			found = data.find(s2);
		}
		replace_data = replace_data + data + "\n";
	}
	is.close();

	ofstream os(argv[1]);
	os<<replace_data;
	os.close();
}



