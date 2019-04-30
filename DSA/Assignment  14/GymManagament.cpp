/*
 * GymManagament.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: student
 */


#include <iostream>
#include<fstream>

using namespace std;

#define MAX 5

ofstream os("GYM.txt",ios::app);

struct node
{
	string name;
	int no;
	int age;
	float height,weight;
	int duration;
	node *next;
};

class Linkedlist
{
public:
	node *head, *tail;

	Linkedlist()
	{
		head = NULL;
		tail = NULL;
	}

	void create()
	{
		string nameU;
		int noU;
		int ageU;
		float heightU,weightU;
		int durationU;

		node *temp = new node;

		cout<<"\n Enter your Name : ";
		cin>>nameU;
		cout<<"\n Enter your Contact Number : ";
		cin>>noU;
		cout<<"\n Enter your Age : ";
		cin>>ageU;
		cout<<"\n Enter your Height & Weight :";
		cin>>heightU>>weightU;
		cout<<"\n Enter your Duration(in months) :";
		cin>>durationU;

		temp->age = ageU;
		temp->name = nameU;
		temp->duration = durationU;
		temp->height = heightU;
		temp->weight = weightU;
		temp->no = noU;

		if(head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}

		os<<ageU<<" ";
		os<<nameU<<" ";
		os<<durationU<<" ";
		os<<heightU<<" ";
		os<<weightU<<" ";
		os<<noU<<" ";
		os<<"\n";
	}

	void display()
	{
		node *temp = new node;
		temp = head;

		cout<<"\nThe member information of pinnacle club is as follows :\n";

		while(temp != NULL)
		{
			cout<<temp->age<<" "<<temp->name<<" "<<temp->duration<<" "<<temp->no<<" "<<temp->height<<" "<<temp->weight<<"\t";
			temp = temp->next;
		}
		cout<<"\n";
	}

	bool getSearchLinear(int key)
	{
		node *temp = head;

		while(temp != NULL)
		{
			if(temp->no==key)
			{
				//				cout<<"\n Welcome !! "<<temp->no<<"\n";
				return true;
				break;
			}
			else
				temp = temp->next;
		}
		//		cout<<"Not a registered user ! Please register yourself\n";
		return false;
	}
};

class QueueStack
{
	int front,rear;
	int data[MAX];
public:
	QueueStack()
{
		front=rear=-1;
}
	int isempty()
	{
		return(front==rear)?1:0;
	}
	int isfull()
	{
		return(rear==MAX-1)?1:0;
	}
	void enqueue(int x)
	{
		if(!isfull())
		{
			data[++rear]=x;
		}
		else
		{
			cout<<"\n GYM is full for now, come sometime later, we regret for your inconvenience:(";
		}
	}
	int delqueue()
	{
		return data[++front];
	}
	void display()
	{
		int i;
		cout<<"\n";
		for(i=front+1;i<=rear;i++)
			cout<<data[i]<<" ";
	}
};

class StkGYm
{
public:
	int stk[MAX];
	int top;
	StkGYm()
	{
		top = -1;
	}
	void push1(int x1)
	{
		top++;
		stk[top]=x1;
	}
	int pop1()
	{
		int s1;
		s1=stk[top];
		top=top-1;
		return s1;
	}
	int isFull()
	{
		if(top==MAX)
			return 1;
		else
			return 0;
	}
	int isEmpty()
	{
		if(top==-1)
			return -1;
		else
			return 1;
	}
	void stkDisplay()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<"\n"<<stk[i];
		}
	}
	int count()
	{
		return top+1;
	}
};

int main()
{
	Linkedlist l;
	QueueStack qsD, qsT, qsB;
	StkGYm s;
	char cont;

	int opt, optQ;

	int num;

	cout<<"\n\n************ Welcome to $H$ GYM *************\n\n ";

	cout<<"Enter your registered number\n";
	cin>>num;

	if(l.getSearchLinear(num))
	{
		cout<<"\n Welcome !! "<<num<<"\n";
		s.push1(num);
	}
	else
	{
		cout<<"Not a registered user ! Please register yourself\n";
		l.create();
	}
	do
	{
		cout<<"1.Enter GYM \n 2. Select equipment\n3. Get Gym Count\n 4. Display current gym members\n 5. Leave equipment \n 6. Display Queue \n 7. Add another memebr \n 8. Exit\n" ;
		cin>>opt;

		switch(opt)
		{
		case 1:
			cout<<"Enter your registered number\n";
			cin>>num;
			if(l.getSearchLinear(num))
			{
				cout<<"\n Welcome !! "<<num<<"\n";
				s.push1(num);
			}
			break;
		case 2:
			cout<<"1. Dumbles\n 2. Treadmill\n 3. Benchpress\n";
			cin>>optQ;
			switch(optQ)
			{
			case 1:
				qsD.enqueue(num);
				break;
			case 2:
				qsT.enqueue(num);
				break;
			case 3:
				qsB.enqueue(num);
				break;
			}
			break;
			case 3:
				cout<<"Total number of members present are :"<<s.count();
				break;
			case 4:
				s.stkDisplay();
				break;
			case 5:
				cout<<"1. Dumbles\n 2. Treadmill\n 3. Benchpress\n";
				cin>>optQ;
				switch(optQ)
				{
				case 1:
					qsD.delqueue();
					break;
				case 2:
					qsT.delqueue();
					break;
				case 3:
					qsB.delqueue();
					break;
				}
				break;
				case 6:
					cout<<"1. Dumbles\n 2. Treadmill\n 3. Benchpress\n";
					cin>>optQ;
					switch(optQ)
					{
					case 1:
						qsD.display();
						break;
					case 2:
						qsD.display();
						break;
					case 3:
						qsD.display();
						break;
					}
					break;
					case 7:
						cout<<"Enter your registered number\n";
						cin>>num;

						if(l.getSearchLinear(num))
						{
							cout<<"\n Welcome !! "<<num<<"\n";
							s.push1(num);
						}
						else
						{
							cout<<"Not a registered user ! Please register yourself\n";
							l.create();
						}
						break;					
					case 8:
						exit(0);
		}			
		cout<<"\nContinue ? (y/n)";
		cin>>cont;
	}while(cont=='y');
	cout<<"Thanks ! Come again !";

	return 0;
}
