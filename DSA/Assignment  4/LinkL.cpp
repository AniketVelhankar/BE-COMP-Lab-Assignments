#include <iostream>

using namespace std;

struct node
{
    int data;
    string name;
    node *next;
};

class Linkedlist
{
public:
    node *head;

    Linkedlist()
    {
        head = NULL;
    }

    void create(int d,string n)
    {
        node *temp = new node;
        temp->data = d;
        temp->name = n;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            node *t = head;
            while(t->next != NULL)
            {
                t = t->next;
            }
            t->next = temp;
        }
    }

    void insertStart(int d, string n)
    {
        node *temp = new node;
        temp->data = d;
        temp->name = n;

        temp->next = head;
        head = temp;
    }

    void insertPos(int d, string n, int pos)
    {
        node *pre=new node;
        node *cur=new node;
        node *temp=new node;
        cur=head;
        for(int i=0;i<pos;i++)
        {
          pre=cur;
          cur=cur->next;
        }
        temp->data=d;
        temp->name=n;
        pre->next=temp;
        temp->next=cur;
    }

    void deleteStart()
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last()
    {
        node *t,*prev;
        t=head;
        if(head==NULL)
            cout<<"\nClub is Empty..";
        else
        {
            while(t->next!=NULL)
            {
                prev=t;
                t=t->next;
            }
        prev->next=NULL;
        delete t;
        }
    }

    void delete_position(int pos)
    {
        node *current=new node;
        node *previous=new node;

        current=head;

        for(int i=0;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }

        previous->next=current->next;
        delete current;
    }

    void display()
    {
        node *temp = new node;
        temp = head;

        cout<<"\nThe member information of pinnacle club is as follows :\n";

        while(temp != NULL)
        {
            cout<<temp->data<<" "<<temp->name<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }

    void displayreverse(node *head)
    {
        if(head == NULL)
            return;
        displayreverse(head->next);
        cout<<head->data<<" "<<head->name<<"\t";
    }

    void concat(node *h1,node *h2)
    {
        node *temp = h1;
        node *temp2 = h2;

        while(temp != NULL)
        {
            create(temp->data,temp->name);
            temp = temp->next;
        }

        while(temp2 != NULL)
        {
            create(temp2->data,temp2->name);
            temp2 = temp2->next;
        }

    }

    void compute()
    {
        node *temp = new node;
        temp = head;
        int count =0;

        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout<<"total number of members are : " <<count<<endl;
    }
};

int main()
{
    Linkedlist l2,l3,l4,seniors;
    int year, prn, selectOP;
    int position;
    string name;
    char ch;

    cout<<"Welcome to Pinnacle club !!!\n\n";

    do
    {

        cout<<"Enter your class : \n1. SE\t 2. TE\t3. BE\t"<<endl<<endl;
        cin>>year;

        if(year == 1)
        {
            selectOP = 0;
            do
            {
                cout<<"Enter the operation you want to perform\n";
                cout<<"1. Insert president information\n";
                cout<<"2. Insert secretary information\n";
                cout<<"3. Insert member information\n";
                cout<<"4. Delete president information\n";
                cout<<"5. Delete secretary information\n";
                cout<<"6. Delete member information\n";
                cout<<"7. Compute total members of club\n";
                cout<<"8. Display information\n";
                cout<<"9. Display information in reverse order\n";
                cout<<"10. Exit\n";


                cin>>selectOP;

                switch(selectOP)
                {
                case 1:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    l2.insertStart(prn, name);
                    break;
                case 2:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    l2.create(prn,name);
                    break;
                case 3:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    cout<<"Enter the position after which you want to insert :\n";
                    cin>>position;
                    l2.insertPos(prn,name,position);
                    break;
                case 4:
                    l2.deleteStart();
                    break;
                case 5:
                    l2.delete_last();
                    break;
                case 6:
                    int p;
                    cout<<"enter the position where you want to delete";
                    cin>>p;
                    l2.delete_position(p);
                    break;
                case 7:
                    l2.compute();
                    break;
                case 8:
                    l2.display();
                    break;
                case 9:
                    l2.displayreverse(l2.head);
                    break;
                case 10:
                    break;
                default:
                    cout<<"wrong choice ! enter again...";
                }
            }while(selectOP != 10);
        }
        if(year == 2)
        {
            selectOP = 0;
            do
            {
                cout<<"Enter the operation you want to perform\n";
                cout<<"1. Insert president information\n";
                cout<<"2. Insert secretary information\n";
                cout<<"3. Insert member information\n";
                cout<<"4. Delete president information\n";
                cout<<"5. Delete secretary information\n";
                cout<<"6. Delete member information\n";
                cout<<"7. Compute total members of club\n";
                cout<<"8. Display information\n";
                cout<<"9. Display information in reverse order\n";
                cout<<"10. Exit\n";


                cin>>selectOP;

                switch(selectOP)
                {
                case 1:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    l3.insertStart(prn, name);
                    break;
                case 2:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    l3.create(prn,name);
                    break;
                case 3:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    cout<<"Enter the position after which you want to insert :\n";
                    cin>>position;
                    l2.insertPos(prn,name,position);
                    break;
                case 4:
                    l3.deleteStart();
                    break;
                case 5:
                    l3.delete_last();
                    break;
                case 6:
                    int p;
                    cout<<"enter the position where you want to delete";
                    cin>>p;
                    l3.delete_position(p);
                    break;
                case 7:
                    l3.compute();
                    break;
                case 8:
                    l3.display();
                    break;
                case 9:
                    l3.displayreverse(l3.head);
                    break;
                case 10:
                    break;
                default:
                    cout<<"wrong choice ! enter again...";
                }
            }while(selectOP != 10);
        }
        if(year == 3)
        {
            selectOP = 0;
            do
            {
                cout<<"Enter the operation you want to perform\n";
                cout<<"1. Insert president information\n";
                cout<<"2. Insert secretary information\n";
                cout<<"3. Insert member information\n";
                cout<<"4. Delete president information\n";
                cout<<"5. Delete secretary information\n";
                cout<<"6. Delete member information\n";
                cout<<"7. Compute total members of club\n";
                cout<<"8. Display information\n";
                cout<<"9. Display information in reverse order\n";
                cout<<"10. Exit\n";


                cin>>selectOP;

                switch(selectOP)
                {
                case 1:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    l4.insertStart(prn, name);
                    break;
                case 2:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    l4.create(prn, name);
                    break;
                case 3:
                    cout<<"Enter your PRN and name";
                    cin>>prn>>name;
                    cout<<"Enter the position after which you want to insert :\n";
                    cin>>position;
                    l2.insertPos(prn,name,position);
                    break;
                case 4:
                    l4.deleteStart();
                    break;
                case 5:
                    l4.delete_last();
                    break;
                case 6:
                    int p;
                    cout<<"enter the position where you want to delete";
                    cin>>p;
                    l4.delete_position(p);
                    break;
                case 7:
                    l4.compute();
                    break;
                case 8:
                    l4.display();
                    break;
                case 9:
                    l4.displayreverse(l4.head);
                    break;
                case 10:
                    break;
                default:
                    cout<<"wrong choice ! enter again...";
                }
            }while(selectOP != 10);
        }

        cout<<"Change class and continue ? (y/n)";
        cin>>ch;
    }while(ch=='y');

    cout<<"\n\nThanks ! Program terminate successfully\n";
    return 0;
}
