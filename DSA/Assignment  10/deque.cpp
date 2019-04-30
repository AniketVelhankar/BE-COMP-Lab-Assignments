#include <iostream>
using namespace std;

#define SIZE 5
class dequeue
{
	int x[20],front,rear;
public:
	dequeue()
{
		front=rear=-1;
}
	void addBegin(int);
	void addEnd(int);
	void deleteFront();
	void deleteRear();
	void display();
};
void dequeue::addEnd(int item)
{
if(front==-1 && rear==-1)
{

rear++;

x[rear]=item;

front=0;

}

else
{

rear++;

x[rear]=item;

}
}

void dequeue::addBegin(int item)
{
		
if(front==-1 && rear==-1)

{

addEnd(item);

}

else{

rear++;

int a[rear]={0,};

for(int i=front;i<=rear;++i)

{

a[i+1]=x[i];

}

a[front]=item;

for(int i=0;i<=rear;++i)

{

x[i]=a[i];

}
}
 }

 void dequeue::display()
 {
	 cout<<"Elements in Deque : ";

	for(int i=front;i<=rear;++i)
	{
	cout<<x[i]<<" " ;

	}
	cout<<endl;
}
	 void dequeue::deleteFront()
	 {
		if(front==rear+1)

		{

			cout<<"Underflow !, can,t delete more !\n";

			return;
		}

		else
		{

			int k=x[front];

			cout<<"Front : "<<k<<endl;

			front++;
		}

 	}
 void dequeue::deleteRear()
 {
		if(rear==-1)
		{

		cout<<"Underflow !, can,t delete more !\n";

		front=-1;

		return;

		}

		else{

		int k=x[rear];

		cout<<"Rear : "<<k<<endl;

		rear--;

		}

}
int main()
{
	int c,item;
	dequeue dl;
	do
	{
		cout<<"\n DEQUEUE:\n 1.Insert At Beginning \n 2.Insert At End \n 3.Display \n 4.Deletion From Front \n 5.Deletion from Rear \n 6.Exit \n Option:";
		cin>>c;
		switch(c)
		{
		case 1:
			cout<<"\n Enter Element:";
			cin>>item;
			dl.addBegin(item);
			break;
		case 2:
			cout<<"\n Enter Element:";
			cin>>item;
			dl.addEnd(item);
			break;
		case 3:
			dl.display();
			break;
		case 4:
			dl.deleteFront();
			break;
		case 5:
			dl.deleteRear();
			break;
		case 6:
			return 0;
		}
	}while(c!=7);
	return 0;
}
