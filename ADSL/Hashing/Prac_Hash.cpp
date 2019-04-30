#include <iostream>

using namespace std;

class Node
{
    string key, meaning;

  public:
    Node()
    {
        key = meaning = "";
    }

    friend class Dictionary;
};

class Dictionary
{
    Node *hashtable, *HashtableWR;
    int count, countWR, size;

  public:
    Dictionary(int s)
    {
        count = countWR = 0;
        size = s;

        hashtable = new Node[size];
        HashtableWR = new Node[size];
    }

    void insert()
    {
        if (count < size)
        {
            Node *t = new Node;

            cout << "Enter key" << endl;
            cin >> t->key;
            cout << "Enter meaning" << endl;
            cin >> t->meaning;

            int h = HashFun(t->key);

            cout << "Hash value is : " << h << endl;

            if (hashtable[h].key == "")
            {
                hashtable[h].key = t->key;
                hashtable[h].meaning = t->meaning;
            }
            else
            {
                for (int i = 0; i < size; i++, h = (h+1)%size)
                {
                    if (hashtable[h].key != "")
                        continue;

                    hashtable[h].key = t->key;
                    hashtable[h].meaning = t->meaning;
                    break;
                }
            }
            count++;
        }
        else
        {
            cout << "Hashtable is Full " << endl;
        }
    }

    void insertWR()
    {
        if (countWR < size)
        {
            Node *t = new Node;

            cout << "Enter the key" << endl;
            cin >> t->key;
            cout << "Enter the meaning" << endl;
            cin >> t->meaning;

            int h = HashFun(t->key);

            cout << "Hash value is : " << h << endl;

            if (HashtableWR[h].key == "")
            {
                HashtableWR[h].key = t->key;
                HashtableWR[h].meaning = t->meaning;
            }
            else if (HashFun(HashtableWR[h].key) == h)
            {
                for (int i = 0; i < size; i++, h=(h+1)%size)
                {
                    if (HashtableWR[h].key != "")
                        continue;

                    HashtableWR[h].key = t->key;
                    HashtableWR[h].meaning = t->meaning;

                    break;
                }
            }
            else
            {
                Node *temp = new Node;

                temp->key = HashtableWR[h].key;
                temp->meaning = HashtableWR[h].meaning;

                HashtableWR[h].key = t->key;
                HashtableWR[h].meaning = t->meaning;

                for (int i = 0; i < size; i++, h++)
                {
                    if (HashtableWR[h].key != "")
                        continue;

                    HashtableWR[h].key = temp->key;
                    HashtableWR[h].meaning = temp->meaning;
                    break;
                }
            }
            countWR++;
        }
        else
        {
            cout << "Hashtable is full" << endl;
        }
    }

    void search(string k)
    {
        int h = HashFun(k);

        for (int i = 0; i < size; i++, h=(h+1)%size)
        {
            if (hashtable[h].key != k)
                continue;
            else
            {
                cout << i << "\t";
                cout << hashtable[h].key << "\t";
                cout << hashtable[h].meaning << "\t";
                cout << "Record retrieved successfully";
                cout << "\n\n";
                break;
            }
        }
    }

    void deleteRec(string k)
    {
        int h = HashFun(k);
        for (int i = 0; i < size; i++, h++)
        {
            if (hashtable[h].key != k)
                continue;
            else
            {
                hashtable[h].key = "";
                hashtable[h].meaning = "";
                cout << "Record deleted successfully"<<endl;
                break;
            }
        }
    }

    void deleteRecWR(string k)
    {
        int h = HashFun(k);
        for (int i = 0; i < size; i++, h++)
        {
            if (HashtableWR[h].key != k)
                continue;
            else
            {
                HashtableWR[h].key = "";
                HashtableWR[h].meaning = "";
                cout << "Record deleted successfully"<<endl;
                break;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
            cout << hashtable[i].key << "\t";
            cout << hashtable[i].meaning << "\t";
            cout << "\n\n";
        }
    }

    void displayWR()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
            cout << HashtableWR[i].key << "\t";
            cout << HashtableWR[i].meaning << "\t";
            cout << "\n\n";
        }
    }

    int HashFun(string q)
    {
        int seed = 131;

        unsigned long hashnum = 0;

        for (int i = 0; i < q.length(); i++)
        {
            hashnum = (hashnum * seed) + q[i];
        }

        return hashnum % size;
    }
};

int main()
{
    Dictionary d(26);
    int ch;
    char cont;
    string key;
    do
    {
        cout << "Enter the operation you want to perform\n1.Insert\n2.Insert WR\n3.Search\n4.Delete\n5.DeleteWR\n6.Display\n7.DisplayWR\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            d.insert();
            break;
        case 2:
            d.insertWR();
            break;
        case 3:
            cout << "Enter the key that you want to search" << endl;
            cin >> key;
            d.search(key);
            break;
        case 4:
            cout << "Enter the key that you want to search" << endl;
            cin >> key;
            d.deleteRec(key);
            break;
        case 5:
            cout << "Enter the key that you want to search" << endl;
            cin >> key;
            d.deleteRecWR(key);
            break;
        case 6:
            d.display();
            break;
        case 7:
            d.displayWR();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << "Continue ?(y/n)" << endl;
        cin >> cont;
    } while (cont == 'y');

    return 1;
}