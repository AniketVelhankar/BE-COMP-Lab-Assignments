/*

 * TBT.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: student


#include<iostream>

using namespace std;

class tbt_node
{
	int data;
	bool lbit,rbit;
	tbt_node *rc,*lc;

public:
	friend class TBT;
	friend class Q_TBT;
	tbt_node(int x)
	{
		data = x;
		lc = rc = NULL;
		lbit = rbit = 1;
	}
};

class Q_TBT
{
	int f,r;
	tbt_node *q[20];

public:
	Q_TBT()
{
		f = r = -1;
}
	void push(tbt_node* item)
	{
		if(isfull())
			cout<<"Queue is full"<<endl;
		else if(isempty())
		{
			r++;
			f++;
			q[r] = item;
		}
		else
		{
			r++;
			q[r] = item;
		}
	}
	tbt_node *pop()
	{
		if(isempty())
			cout<<"Queue is empty"<<endl;
		else if(f == r)
			f = -1;
		else
			return q[f++];
	}
	int isfull()
	{
		if(r == 19 || f == r+1)
			return 1;
		else
			return 0;
	}

	int isempty()
	{
		if(f==-1)
			return 1;
		else
			return 0;
	}
};

class TBT
{
	tbt_node *root;

public:
	TBT()
{
		root = NULL;
}

	void insert(int x)
	{
		tbt_node *temp, *p;
		Q_TBT q1;

		if(root == NULL)
		{
			p = new tbt_node(x);
			root = p;
			p->lc = p->rc = p;
			p->lbit = 0;
			p->rbit= 0;

			cout<<"Root is created"<<endl;
		}
		else
		{
			q1.push(root);
			char ch;

			while(!q1.isempty())
			{
				temp = q1.pop();

				cout<<"Do you want to insert on lc of "<<temp->data;
				cin>>ch;

				if(ch == 'y' || ch == 'Y')
				{
					p = new tbt_node(x);
					linsert(temp,p);
					q1.push(p);
				}

				if(temp != root)
				{
					cout<<"Do you want to insert on rc of "<<temp->data;
					cin>>ch;

					if(ch == 'y' || ch == 'Y')
					{
						p = new tbt_node(x);
						rinsert(temp,p);
						q1.push(p);
					}
				}
			}

		}
	}

	void linsert(tbt_node *s, tbt_node *t)
	{
		t->lbit = 0;
		t->rbit = 0;
		t->lc = s->lc;
		t->rc = s;
		s->lc = t;
		s->lbit = 1;
	}

	void rinsert(tbt_node *s,tbt_node *t)
	{
		t->lbit = 0;
		t->rbit = 0;
		t->lc = s;
		t->rc = s->rc;
		s->rc = t;
		s->rbit = 1;
	}

	void preorder()
	{
		tbt_node *t;

		t = root->lc;

		while(1)
		{
			if(t == root)
				return;

			cout<<t->data<<endl;

			if(t->lbit == 1)
				t = t->lc;
			else
			{
				if(t->rbit == 1)
					t = t->rc;
				else
				{
					while(t->rbit!=1)
						t =t->rc;
				}
			}
		}
	}
};

int main()
{
	TBT t1;

	t1.insert(10);
	cout<<"Node added"<<endl;
	t1.insert(20);
	cout<<"Node added"<<endl;
	t1.insert(20);
	cout<<"Node added"<<endl;

	t1.preorder();
	return 0;
}
*/


#include <iostream>

using namespace std;

class TBT;

class Node
{
	Node *lc,*rc;
	int data;
	bool rbit,lbit;
public:
	Node()
{
		lc=NULL;
		rc=NULL;
		data=0;
		rbit=lbit=0;
}
	Node(int d)
	{
		lc=NULL;
		rc=NULL;
		rbit=lbit=0;
		data=d;
	}
	friend class TBT;
};

class TBT
{
	Node *root;
public:
	TBT()
{
		root=new Node(9999);
		root->lc=root;
		root->rbit=1;
		root->lbit=0;
		root->rc=root;
}
	void preorder()
	{
		Node *c=root->lc;
		while(c!=root)
		{
			cout<<" "<<c->data;
			c=preorderS(c);//Call to Preorder Successor
		}
	}
	void inorder()
	{
		Node *c=root->lc;
		while(c->lbit==1)
			c=c->lc;
		while(c!=root)
		{
			cout<<" "<<c->data;
			c=inorderS(c);//Call to Inorder Successor
		}
	}
	Node *inorderS(Node *c)
	{
		if(c->rbit==0)
			return c->rc;
		else
			c=c->rc;
		while(c->lbit==1)
		{
			c=c->lc;
		}
		return c;
	}
	Node *preorderS(Node *c)
	{
		if(c->lbit==1)
		{
			return c->lc;
		}
		while(c->rbit==0)
		{
			c=c->rc;
		}
		return c->rc;
	}
	void create()
	{
		int n;
		cout<<"\nEnter number of nodes:";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int info;
			cout<<"\nEnter data: ";
			cin>>info;
			this->insert(info);
		}
	}
	void insert(int data)
	{

		if(root->lc==root&&root->rc==root)
		{
			Node *p=new Node(data);
			p->lc=root->lc;
			p->lbit=root->lbit;
			p->rbit=0;
			p->rc=root->rc;
			root->lc=p;
			root->lbit=1;
			cout<<"\nInsertion Started->"<<data;
			return;
		}
		Node *cur=new Node;
		cur=root->lc;
		while(1)
		{

			if(cur->data<data)   //insert rc
			{
				Node *p=new Node(data);
				if(cur->rbit==0)
				{
					p->rc=cur->rc;
					p->rbit=cur->rbit;
					p->lbit=0;
					p->lc=cur;
					cur->rbit=1;
					cur->rc=p;
					cout<<"\nInserted rc:"<<data;
					return;
				}
				else
					cur=cur->rc;
			}
			if(cur->data>data) //insert lc
			{
				Node *p=new Node(data);
				if(cur->lbit==0)
				{
					p->lc=cur->lc;
					p->lbit=cur->lbit;
					p->rbit=0;
					p->rc=cur; //successor
					cur->lbit=1;
					cur->lc=p;
					cout<<"\nInserted lc:"<<data;
					return;
				}
				else
					cur=cur->lc;
			}
		}

	}
	void delTBT(){}
};
int main()
{
	TBT t1;
	int value;
	int choice;
	do
	{
		cout<<"\nThreaded Binary Tree:- \n1.Create Tree\n2.Insert into tree\n3.Pre-order\n4.Inorder\n5.Delete\n6.Exit\nEnter your choice:";
		cin>>choice;
		if(choice>5)
			return 0;
		switch(choice)
		{
		case 1:
			t1.create();
			break;
		case 2:
			cout<<"\nEnter Number:";
			cin>>value;
			t1.insert(value);
			break;
		case 3:
			cout<<"\nPreorder traversal of TBT:\n";
			t1.preorder();
			break;
		case 4:
			cout<<"\nInoder Traversal of TBT:\n";
			t1.inorder();
			break;
		case 5:
			cout<<"\n Deletion:";
			t1.delTBT();
			break;
		}

	}while(choice!=0);

	return 0;
}

