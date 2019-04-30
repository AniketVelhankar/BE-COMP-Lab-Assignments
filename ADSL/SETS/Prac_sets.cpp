#include <iostream>
using namespace std;

const int MAX = 30;

template<class T>
class iter;

template <class T>
class Set
{
    T data[MAX];
    int n;

  public:

    Set()
    {
        n = -1;
    }

    void input(int num)
    {
        T item;

        for (int i = 0; i < num; i++)
        {
            cout << "Enter item" << endl;
            cin >> item;
            add(item);
        }
    }

    bool add(T item)
    {
        if (n == MAX - 1)
        {
            cout << "Overflow !";
            return false;
        }

        data[++n] = item;
        return true;
    }

    bool del(T item)
    {
        if (n == -1)
        {
            cout << "Empty set" << endl;
            return false;
        }

        for (int i = 0; i <= n; i++)
        {
            if (data[i] == item)
            {
                for (int j = i; j <= (n - 1); j++)
                {
                    data[j] = data[j + 1];
                }
                n--;
                return true;
            }
        }
    }

    bool contains(T item)
    {
        for (int i = 0; i <= n; i++)
        {
            if (data[i] == item)
                return true;
        }
        return false;
    }

    int size()
    {
        return n + 1;
    }

    void print()
    {
        iter<T>obj(*this);
        for (int i = obj.begin(); i <= obj.end(); i++)
            cout << " " << data[i];
    }


    /*main operations*/

    Set<T> setUnion(Set<T> s1, Set<T> s2)
    {
        Set<T> s3;

        int flag = 0;

        for (int i = 0; i <= s1.n; i++)
        {
            s3.add(s1.data[i]);
        }

        for (int j = 0; j <= s2.n; j++)
        {
            flag = 0;
            for (int i = 0; i <= s1.n; i++)
            {
                if (s1.data[i] == s2.data[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                s3.add(s2.data[j]);
            }
        }

        return s3;
    }

    Set<T> setDiff(Set<T> s1, Set<T> s2)
    {
        Set<T> s3;

        int flag = 0;

        for (int i = 0; i <= s1.n; i++)
        {
            for (int j = 0; j <= s2.n; j++)
            {
                if (s1.data[i] == s2.data[j])
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            if (flag == 0)
            {
                s3.add(s1.data[i]);
            }
        }

        return s3;
    }

    Set<T> setIntersect(Set<T> s1, Set<T> s2)
    {
        Set<T> s3;

        for (int i = 0; i <= s1.n; i++)
        {
            for (int j = 0; j <= s2.n; j++)
            {
                if (s1.data[i] == s2.data[j])
                {
                    s3.add(s1.data[i]);
                    break;
                }
            }
        }

        return s3;
    }

    bool subset(Set<T> s2)
    {
        int count = 0;
        int size = s2.size();

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s2.n; j++)
            {
                if (data[i] == s2.data[j])
                {
                    count++;
                    break;
                }
            }
        }

        if (count == size)
            return true;
        else
            return false;
    }
};

template <class T>
class iter
{
    int last;

  public:

    iter(Set<T> &obj)
    {
        last = obj.n;
    }
    int begin()
    {
        return 0;
    }
    int end()
    {
        return last;
    }

    friend class Set;
};

int main()
{
    Set<int> s1, s2, s3;

    int choice, item;

    cout << "Enter number of elements in set 1 : " << endl;
    cin >> item;
    s1.input(item);

    cout << "Enter number of elements in set 2 : " << endl;
    cin >> item;
    s2.input(item);

    do
    {
        cout << "\n\n\nEnter the operation you want to perform -" << endl;
        cout << "1. Add an element\n2. Delete element\n3. Search\n4. Size of set\n5. Set intersection";
        cout << "\n6. Set union\n7. Set difference\n8. Subset ?\n9. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter item : " << endl;
            cin >> item;

            if (s1.add(item))
            {
                cout << item << " added" << endl;
            }
            else
            {
                cout << "Insertion Failed" << endl;
            }
            break;

        case 2:
            cout << "Enter item : " << endl;
            cin >> item;

            if (s1.del(item))
            {
                cout << item << " deleted" << endl;
            }
            else
            {
                cout << "Deletion Failed" << endl;
            }

            break;

        case 3:
            cout << "Enter item : " << endl;
            cin >> item;

            if (s1.contains(item))
            {
                cout << item << " is present in set" << endl;
            }
            else
            {
                cout << item << " is not  present" << endl;
            }

            break;

        case 4:
            cout << "Size of set is : " << s1.size() << endl;
            break;

        case 5:
            s3 = s1.setIntersect(s1, s2);

            cout << "\nSet 1 : ";
            s1.print();
            cout << "\nSet 2 : ";
            s2.print();

            cout << "\nIntersection : ";
            s3.print();
            break;

        case 6:
            s3 = s1.setUnion(s1, s2);

            cout << "\nSet 1 : ";
            s1.print();
            cout << "\nSet 2 : ";
            s2.print();

            cout << "\nUnion : ";
            s3.print();
            break;

        case 7:

            s3 = s1.setDiff(s1, s2);

            cout << "\nSet 1 : ";
            s1.print();
            cout << "\nSet 2 : ";
            s2.print();

            cout << "\nDifference :";
            s3.print();
            break;

        case 8:

            if (s1.subset(s2))
            {
                cout << "\nSet 2 is subset of Set 1" << endl;
            }
            else
            {
                cout << "\nSet 2 is not a subset of Set 1" << endl;
            }
            break;
        }
    } while (choice <= 8);

    cout << "Program terminated succcessfully ." << endl;
    return 0;
}