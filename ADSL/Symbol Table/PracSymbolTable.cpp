#include <iostream>

using namespace std;

class node
{
    string key, type, ival;
    int chain;

  public:
    node()
    {
        key = type = ival = "";
        chain = -1;
    }

    friend class symtab;
};

class symtab
{
    node *symboltable, *symboltableWR;
    int size;

  public:
    symtab(int s)
    {
        size = s;
        symboltable = new node[size];
        symboltableWR = new node[size];
    }

    void insert()
    {
        node *t = new node;

        cout << "Enter keyword" << endl;
        cin >> t->key;
        cout << "Enter data type" << endl;
        cin >> t->type;
        cout << "Enter initial value" << endl;
        cin >> t->ival;

        int h = HashFun(t->key);

        int u, v;

        cout << "hash value is " << h << endl;

        if (symboltable[h].key == "")
        {
            symboltable[h].key = t->key;
            symboltable[h].type = t->type;
            symboltable[h].ival = t->ival;
            symboltable[h].chain = -1;
        }
        else
        {
            v = h;
            u = symboltable[h].chain;

            while (u != -1)
            {
                v = u;
                u = symboltable[v].chain;
            }

            int i;
            for (i = (h + 1) % size; symboltable[i].key != ""; i = (i + 1) % size)
                ;

            symboltable[i].key = t->key;
            symboltable[i].type = t->type;
            symboltable[i].ival = t->ival;

            symboltable[v].chain = i;
            symboltable[i].chain = -1;
        }

        cout<<"\nRecord Inserted "<<endl;
    }

    void insertWR()
    {
        node *t = new node;

        cout << "Enter keyword" << endl;
        cin >> t->key;
        cout << "Enter data type" << endl;
        cin >> t->type;
        cout << "Enter initial value" << endl;
        cin >> t->ival;

        int h = HashFun(t->key);

        cout<<"Hash value is : "<<h<<endl;

        if(symboltableWR[h].key == "")
        {
            symboltableWR[h].key = t->key;
            symboltableWR[h].type = t->type;
            symboltableWR[h].ival = t->ival;
            symboltableWR[h].chain = -1;
        }
        else
        {
            if(HashFun(symboltableWR[h].key)==h)
            {
                int v,u;

                v = h;
                u = symboltableWR[h].chain;

                while(u!=-1)
                {
                    v = u;
                    u = symboltableWR[v].chain;
                }

                int i;

                for(i = (h+1)%size;symboltableWR[i].key!="";i=(i+1)%size)
                ;
                symboltableWR[i].key = t->key;
                symboltableWR[i].type = t->type;
                symboltableWR[i].ival = t->ival;
                symboltableWR[i].chain = -1;

                symboltableWR[v].chain = i;
            }

            else
            {
                node *temp;

                temp->key = symboltableWR[h].key;
                temp->type = symboltableWR[h].type;
                temp->ival = symboltableWR[h].ival;
                temp->chain = symboltableWR[h].chain;

                symboltableWR[h].key = t->key;
                symboltableWR[h].key = t->type;
                symboltableWR[h].key = t->ival;
                symboltableWR[h].chain = -1;

                int i;

                for(i = (h+1)%size;symboltableWR[i].key!="";i=(i+1)%size)
                ;

                symboltableWR[i].key = temp->key;
                symboltableWR[i].type = temp->type;
                symboltableWR[i].ival = temp->ival;
                symboltableWR[i].chain = temp->chain;

                int k;
                for (k = 0; symboltableWR[k].chain != h; k = (k + 1) % size)
                    ;
                symboltableWR[k].chain = i;
                symboltableWR[i].chain = -1;
            }
        }

        cout<<"\nRecord inserted"<<endl;
    }

    int HashFun(string k)
    {
        int seed = 131;

        unsigned long hashnum = 0;

        for (int i = 0; i < k.length(); i++)
        {
            hashnum = (hashnum * seed) + k[i];
        }

        return hashnum % size;
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<symboltableWR[i].key<<"\t"<<symboltableWR[i].chain;
            cout<<"\n";
        }
    }
};

int main()
{
    symtab t1(10);

    t1.insertWR();
    t1.insertWR();
    t1.insertWR();

    t1.display();

    return 0;
}