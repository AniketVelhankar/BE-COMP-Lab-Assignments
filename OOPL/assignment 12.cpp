#include<deque>
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
 deque <int>dq;
 deque <int>::iterator p;
        char cc;
        int val,ch;
 do
{
  cout<<"\n\nMENU:";
  cout<<"\n1. Enter element at front\n";
  cout<<"\n2. Enter element at Rear \n";
  cout<<"\n3. Delet element at front\n";
  cout<<"\n4. Delet element at Rear\n";
  cout<<"\n5. Display front element\n";
  cout<<"\n6. Display back element\n";
  cout<<"\n7. Display the element of Deque\n\n";
  cout<<"\nEnter choice:";
  cin>>ch;
    switch(ch)
{
     case 1:
 cout<<"\n\nEnter the element to be inserted:";
 cin>>val;
 dq.push_front(val);
 cout<<"\nElement inserted at front:"<<dq.front();
      break;

     case 2:
        cout<<"\n\nEnter the element to be inserted:";
 cin>>val;
        dq.push_back(val);
 cout<<"\nElement inserted at rear end:"<<dq.back();
      break;

     case 3:
 cout<<"\nElement to be deleted at front:"<<dq.front();
 dq.pop_front();
      break;

     case 4:
 cout<<"\nElement to be deleted at rear:"<<dq.back();
 dq.pop_back();
      break;

     case 5:
 cout<<"\nElement at front:"<<dq.front();
      break;

     case 6:
 cout<<"\nElement at rear:"<<dq.back();
      break;

     case 7:
      if(dq.empty()==1)
        cout<<"\n\nDEQUE is EMPTY..";
   else
{
 cout<<"\n\nDisplaying the elements of DEQUE...\n";
   for(p=dq.begin();p<dq.end();p++)
 cout<<" "<<*p<<"\t";
}
    break;
}
 cout<<"\n\ncontinue ? (y/n)";
 cin>>cc;
}while(cc=='y');

cout<<"\n\nProgram terminated successfully";
return 0;
}
