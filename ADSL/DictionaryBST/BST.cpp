/*
 * BST.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: student
 */

#include<iostream>

using namespace std;

class node
{
	string key,meaning;
	node *lchild;
	node *rchild;

public:

	friend class BST;
	friend class Stack_BST;

	node(string k, string m)
	{
		key = k;
		meaning = m;
		lchild = rchild = NULL;
	}
};

class BST
{
public:

	node *root;

	BST()
	{
		root = NULL;
	}

	node *insert(node *t, string k, string m)
	{
		node *p;

		if(root == NULL)
		{
			root = new node(k,m);

			cout<<"Root node added"<<endl;
			return root;
		}

		else
		{
			if(t == NULL)
			{
				p = new node(k,m);
				return p;
			}
			else
			{
				if(k>t->key)
				{
					t->rchild = insert(t->rchild,k,m);
				}
				else
				{
					t->lchild = insert(t->lchild,k,m);
				}
			}

			return t;
		}
	}

	void inorder(node *t)
	{
		if(t!=NULL)
		{
			inorder(t->lchild);
			cout<<t->key<<" ";
			cout<<t->meaning<<endl;
			inorder(t->rchild);
		}
	}

	void revinorder(node *t)
	{
		if(t!=NULL)
		{
			revinorder(t->rchild);
			cout<<t->key<<" ";
			cout<<t->meaning<<endl;
			revinorder(t->lchild);
		}
	}

	BST* operator = (BST *t)
	{
		BST *lt, *rt, *t1, *t2;

		if(t != NULL)
		{
			this->root = t->root;
			lt->root = t->root->lchild;
			rt->root = t->root->rchild;

			t1 = lt;
			t2 = rt;

			this->root->lchild = lt->root;
			this->root->rchild = rt->root;

			return this;
		}

		else
			return NULL;
	}

	node *searchParent(node *t,string k)
	{
		while(t != NULL)
		{
			if(t->lchild->key==k)
				return t;
			else if(t->rchild->key==k)
				return t;
			else
			{
				if(k<t->key)
					t = searchbst(t->lchild,k);
				else
					t = searchbst(t->rchild,k);
			}
		}
		return t;
	}


	/*	node *delbst(node *t, string k)
	{

		node *p;

		if(t == NULL)
		{
			return NULL;
		}

		else if(k<t->key)
		{
			t->lchild = delbst(t->lchild,k);
			return t;
		}

		else if(k>t->key)
		{
			t->rchild = delbst(t->rchild,k);
			return t;
		}

		else if(t->lchild == NULL && t->rchild == NULL)
		{
			p = t;
			delete(p);
		}

		else if(t->lchild != NULL)
		{
			p = t->lchild;

			while(p->rchild != NULL)
			{
				p = p->rchild;
			}
			t->key = p->key;
			t->meaning = p->meaning;
			return(delbst(p,p->key));
		}

		else
		{
			p = t->rchild;

			while(p->lchild != NULL)
			{
				p = p->lchild;
			}
			t->key = p->key;
			t->meaning = p->meaning;
			return(delbst(p,p->key));
		}
		return 0;
	}*/


	void delbst(node *t, string k)
	{
		node *p,*c;

		p = searchParent(t,k);

		if(p != NULL)
		{
			if(p->lchild->key == k)
				c = p->lchild;
			else
				c = p->rchild;
		}

		if(c->lchild != NULL && c->rchild != NULL)
		{
			p = c;

			node *c_s = c->rchild;

			while(c_s->lchild != NULL)
			{
				p = c_s;
				c_s = c_s->lchild;
			}

			c->key = c_s->key;
			c->meaning = c_s->meaning;
			c = c_s;
		}

		if(c->lchild == NULL && c->rchild != NULL)
		{
			if(p->rchild == c)
				p->rchild = c->rchild;
			else
				p->lchild = c->rchild;

			cout<<"Deleting node "<<c->key<<endl;
			delete(c);
		}

		if(c->lchild != NULL && c->rchild == NULL)
		{
			if(p->lchild == c)
				p->lchild = c->lchild;
			else
				p->rchild = c->lchild;

			cout<<"Deleting node "<<c->key<<endl;
			delete(c);
		}

		if(c->lchild == NULL && c->rchild == NULL)
		{
			if(p->rchild == c)
				p->rchild = NULL;
			else
				p->lchild = NULL;

			cout<<"Deleting node "<<c->key<<endl;
			delete(c);
		}
	}

	node *searchbst(node *t, string k)
	{
		while(t != NULL)
		{
			if(k==t->key)
				return t;
			else
			{
				if(k<t->key)
					t = searchbst(t->lchild,k);
				else
					t = searchbst(t->rchild,k);
			}
		}
		return t;
	}

	void updatebst(node *t, string k)
	{
		node *updt;
		string newm;
		updt = searchbst(t,k);

		if(updt != NULL)
		{
			cout<<"Enter the new meaning"<<endl;
			cin>>newm;
			updt->meaning = newm;
			cout<<"updated successfully"<<endl;;
		}
	}
};

int main()
{
	BST d,d_copy;
	node *addr;
	node *searchval;
	node *del;

	int choice;
	string keyw,meanw;
	char ch;

	do
	{

		cout<<"Enter the operation you want to perform"<<endl;
		cout<<"1. Insert a node recursively"<<endl;
		cout<<"2. Ascending order"<<endl;
		cout<<"3. Copy tree"<<endl;
		cout<<"4. Search a key in the tree"<<endl;
		cout<<"5. Delete a key from tree"<<endl;
		cout<<"6. Update a key"<<endl;
		cout<<"7. Descending order"<<endl;



		cin>>choice;


		switch(choice)
		{
		case 1:
			cout<<"Enter the keyword"<<endl;
			cin>>keyw;
			cout<<"Enter the meaning"<<endl;
			cin>>meanw;

			addr = d.insert(addr,keyw,meanw);;
			cout<<"Node added successfully"<<endl;
			break;

		case 2:
			d.inorder(d.root);
			break;

		case 3:
			d_copy = d;
			cout<<"Tree copied successfully"<<endl;
			cout<<"Elements of copied tree in ascending order are "<<endl;
			d_copy.inorder(d_copy.root);
			break;

		case 4:
			cout<<"Enter the keyword that you want to search "<<endl;
			cin>>keyw;
			searchval = d.searchbst(d.root,keyw);
			if(searchval)
				cout<<"Search successful"<<endl;
			else
				cout<<"Search unsuccessful"<<endl;
			break;

		case 5:
			cout<<"Enter the keyword that you want to delete "<<endl;
			cin>>keyw;
			d.delbst(d.root,keyw);
			cout<<"Deleted node"<<endl;
			/*if(del == 0)
				cout<<"Last Node deleted, Tree is empty now"<<endl;
			else
				cout<<"Node deleted"<<endl;*/
			break;

		case 6:
			cout<<"enter the key you want to update"<<endl;
			cin>>keyw;
			d.updatebst(d.root,keyw);
			break;

		case 7:
			d.revinorder(d.root);
			break;


		}

		cout<<"\n\nDo you want to continue (y/n) ?"<<endl;
		cin>>ch;

	}while(ch =='y' || ch== 'Y' );

	cout<<"Thanks !! Program terminated successfully"<<endl;

	return 0;
}
