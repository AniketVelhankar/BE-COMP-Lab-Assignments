#include<iostream>

using namespace std;

class node
{
    node *right;
    node *left;
    int data;

    public:
    node()
    {
        right = NULL;
        left = NULL;
        data = 0;
    }

    friend class btree;
};

class ST
{
    int top;
	node *s[20];

public:

	friend class btree;

	ST()
	{
		top = -1;
	}

	void push(node *p)
	{
		if(is_full())
			cout<<"stack is full"<<endl;
		else
		{
			top++;
			s[top] = p;
		}
	}

	node* pop()
	{
		node *x;

		if(is_empty())
		{
			cout<<"stack is empty"<<endl;
		}

		else
		{
			x = s[top];
			top--;
			return (x);
		}
	}

	int is_full()
	{
		if(top == 19)
			return 1;
		else
			return 0;
	}

	int is_empty()
	{
		if(top == -1)
			return 1;
		else
			return 0;
	}

    /*node *top()
    {
        return s[top];
    }*/
};

class btree
{
    node *root;
    //QT q;

    public:

    btree()
    {
        root = NULL;
    }

    void create()
    {
        ST s;

        if(root == NULL)
        {
            cout<<"enter data for root"<<endl;
            int item;
            cin>>item;

            node *new1 = new node;
            new1->data = item;

            root = new1;
            s.push(new1);
        }

        while(!s.is_empty())
        {
            char op;
            int item;
            node *t = s.pop();
            cout<<"Consider element "<<t->data<<endl;
            cout<<"Does it have left child ?"<<endl;
            cin>>op;
            if(op == 'y')
            {
                cout<<"Enter data for left child"<<endl;
                cin >>item;
                node *new1 = new node;
                new1->data = item;
                t->left = new1;
                s.push(new1);
            }

            cout<<"Does it have right child ?"<<endl;
            cin>>op;
            if(op == 'y')
            {
                cout<<"Enter data for right child"<<endl;
                cin >>item;
                node *new1 = new node;
                new1->data = item;
                t->right = new1;
                s.push(new1);
            }
        }
    }

    node* createR()
    {
        int item;
        char ch;

        cout<<"Enter node data"<<endl;
        cin>>item;

        if(item == -1)
            return NULL;
        else
        {
            node *p = new node;
            p->data = item;

            cout<<"Does "<<p->data<<" have left child"<<endl;
            cin>>ch;

            if(ch=='y')
            {
                p->left = createR();
            }

            cout<<"Does "<<p->data<<" have right child"<<endl;
            cin>>ch;

            if(ch=='y')
            {
                p->right = createR();
            }

            return p;
        }
    }

    void inorder(node *t)
    {
        if(t!=NULL)
        {
            inorder(t->left);
            cout<<t->data<<"\t";
            inorder(t->right);
        }
    }

    void inordernonrec()
    {
        node *ptr = root;
        ST s1;

        while(1)
        {
            while(ptr!=NULL)
            {
                s1.push(ptr);
                ptr=ptr->left;
            }
            if(s1.is_empty())
                return;

            ptr= s1.pop();
            cout<<ptr->data<<"\t";
            ptr = ptr->right;
        }
    }

    void postorder(node *t)
    {        
        if(t!=NULL)
        {
            postorder(t->left);
            postorder(t->right);
            cout<<t->data<<"\t";
        }
    }

    void postordernonrec()
    {
        ST s1,s2;

        s1.push(root);

        while(!s1.is_empty())
        {
            node *temp;;
            temp = s1.pop();

            s2.push(temp);

            if(temp->left!=NULL)
                s1.push(temp->left);
            if(temp->right!=NULL)
                s1.push(temp->right);
        }

        while(!s2.is_empty())
        {
            node *temp;

            temp = s2.pop();
            cout<<temp->data<<"\t";
        }
    }

    void preorder(node *t)
    {
        if(t!=NULL)
        {
            cout<<t->data<<"\t";
            preorder(t->left);
            preorder(t->right);
        }
    }

    void preordernonrec()
    {
        ST s1;
        node *ptr = root;

        while(1)
        {
            while(ptr!=NULL)
            {
                cout<<ptr->data<<"\t";
                s1.push(ptr);
                ptr = ptr->left;
            }

            if(s1.is_empty())
                return;
            
            ptr = s1.pop();
            ptr = ptr->right;
        }
    }

    int height(node *t)
    {
        if(t==NULL)
            return -1;
        return(max(height(t->left),height(t->right))+ 1);
    }

    void leafinteriornode()
    {
        int l=0,in =0;

        ST s1;

        node *temp;
        s1.push(root);

        while(!s1.is_empty())
        {
            temp = s1.pop();

            if(temp->left == NULL && temp->right == NULL)
                l++;
            else
                in++;

            if(temp->right!=NULL)
                s1.push(temp->right);

            if(temp->left!=NULL)
                s1.push(temp->left);
        }

        cout<<"\nTotal internal nodes are : "<<in<<endl<<"Total leaf nodes are : "<<l<<endl;
    }

    void del(node *ptr)
    {
        if(ptr !=NULL)
        {
            del(ptr->left);
            del(ptr->right);
            delete ptr;
        }
    }

    void setroot(node *r)
    {
        root = r;
    }

    node* getroot()
    {
        return root;
    }

    node* mirror(node *r)
    {
        node *m_root = NULL;

        if(r == NULL)
            return NULL;
        
        m_root = new node;
        m_root->data = r->data;
        m_root->left = mirror(r->right);
        m_root->right = mirror(r->left);

        return m_root;
    }

    btree* operator = (btree *t)
	{
		btree *lt, *rt, *t1, *t2;

		if(t != NULL)
		{
			this->root = t->root;
			lt->root = t->root->left;
			rt->root = t->root->right;

			t1 = lt;
			t2 = rt;

			this->root->left = lt->root;
			this->root->right = rt->root;

			return this;
		}

		else
			return NULL;
	}

};
int main()
{
    btree bt,bt_copy,b_mirror;

    // node *r;
    // r = bt.createR();
    // bt.setroot(r);

    bt.create();

    cout<<"\nInorder :"<<endl;
    bt.inorder(bt.getroot());
    bt.inordernonrec();

    cout<<"\nPreorder :"<<endl;
    bt.preorder(bt.getroot());
    bt.preordernonrec();

    cout<<"\nPostorder :"<<endl;
    bt.postorder(bt.getroot());
    bt.postordernonrec();

    cout<<"\nHeight is : "<<bt.height(bt.getroot());

    bt.leafinteriornode();

    node *mirror;
    mirror = bt.mirror(bt.getroot());
    b_mirror.setroot(mirror);

    cout<<"\nTree mirrored"<<endl;

    cout<<"Inorder :"<<endl;
    b_mirror.inorder(b_mirror.getroot());

    bt_copy = bt;

    cout<<"\nTree copied"<<endl;
    cout<<"Inorder :"<<endl;
    bt_copy.inorder(bt_copy.getroot());

    cout<<"\n";
}