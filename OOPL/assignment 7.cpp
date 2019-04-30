#include<iostream>
#include<string.h>
using namespace std;

class UserDefinedExcep
{
public:
 char vehicle;
 int salary,age;
 string city;

  UserDefinedExcep()
  {
   age=0;
   vehicle=0;
   salary=0;

  }

  void getdata()
  {

     cout<<"Enter Age Of Person:- ";
     cin>>age;
     if(age<18 || age>55)
      {
       throw 1;
      }

     cout<<"Enter Salary For Permonth:- ";
     cin>>salary;

      if(salary<50000 || salary>100000)
      {
       throw 2;
      }



     cout<<"Do u have four wheeler(y/n):-  ";
     cin>>vehicle;
     if(vehicle=='n')
      {
       throw 3;
      }

     cout<<"Enter the City name User stay:-  :- ";
     cin>>city;
     if(city=="pune" || city=="mumbai" || city=="bangalore" || city=="chennai")
     {}

     else
     {
      throw 4;
     }
  }

  void putdata()
  {
    cout<<age<<endl;
    cout<<salary<<endl;
    cout<<vehicle<<endl;
    cout<<city;
  }
};

int main()
{
 UserDefinedExcep u;
 try
 {
  u.getdata();
 }

 catch(int i)
 {
  switch(i)
  {
   case 1:
    cout<<"\nInvalid....Please enter age between(18-55)";
    break;

   case 2:
    cout<<"\n Invalid...Please enter salary between(50000-100000)";
    break;

   case 3:
    cout<<"\nUser Donot have four vehicle";
    break;

   case 4:
    cout<<"\nInvalid city";
    break;
  }
 }
 u.putdata();
 return 0;
}
