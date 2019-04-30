#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Student
{
    int rollno;
    char name[10];

  public:
    Student()
    {
        rollno = -1;
        name[0] = '\0';
    }

    void getdata()
    {
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter roll number : ";
        cin >> rollno;
    }

    void display()
    {
        cout << "Name : "<<name<<"  Roll no : "<<rollno << endl;
    }

    friend class HashFile;
};

class HashFile
{
    Student sg, sp;
    int size;

  public:
    HashFile(int n)
    {
        size = n;
    }

    void init()
    {
        fstream fout;

        fout.open("data.txt", ios::in | ios::out | ios::binary);

        for (int i = 0; i < size; i++)
        {
            fout.write((char *)&sp, sizeof(sp));
        }

        fout.close();
    }

    void create()
    {
        fstream fout;

        fout.open("data.txt", ios::in | ios::out | ios::binary);

        int rp, rg;

        sp = Student();
        sg = Student();

        sp.getdata();
        rp = sp.rollno;

        rp = rp % size;

        int r = rp;

        fout.seekg(sizeof(sg) * rp, ios::beg);
        fout.read((char *)&sg, sizeof(sg));
        rg = sg.rollno;

        while (rg != -1)
        {
            r = (r + 1) % size;
            fout.seekg(sizeof(sg) * r, ios::beg);
            fout.read((char *)&sg, sizeof(sg));
            rg = sg.rollno;
        }

        fout.seekp(sizeof(sp) * r, ios::beg);
        fout.write((char *)&sp, sizeof(sp));

        fout.close();
    }

    void display1()
    {
        fstream fout;

        fout.open("data.txt", ios::in | ios::out | ios::binary);
        int r = 0;
        for (int i = 0; i < size; i++)
        {
            fout.seekg(sizeof(sg) * i, ios::beg);
            fout.read((char *)&sg, sizeof(sg));
            sg.display();
            //				r=(r+1)%MAX;
        }
        fout.close();
    }

    void find()
    {
        int r;
        cout << "Enter the roll no of the student : ";
        cin >> r;
        int r1 = r % size;
        int flag = 0;
        fstream fout;
        fout.open("data.txt", ios::in | ios::out | ios::binary);
        int i = 0;
        while (i < size)
        {
            fout.seekg(sizeof(sg) * r1, ios::beg);
            fout.read((char *)&sg, sizeof(sg));

            if (sg.rollno == r)
            {
                flag = 1;
                break;
            }
            r1 = (r1 + 1) % size;
            i++;
        }
        if (flag == 1)
        {
            cout << "Found\n";
            sg.display();
        }
        else
        {
            cout << "Not found.\n";
        }
        fout.close();
    }

    void update()
    {
        int r;
        cout << "Enter the roll no of the student : ";
        cin >> r;
        int r1 = r % size;
        int flag = 0;
        fstream fout;
        fout.open("data.txt", ios::in | ios::out | ios::binary);
        int i = 0;
        while (i < size)
        {
            fout.seekg(sizeof(sg) * r1, ios::beg);
            fout.read((char *)&sg, sizeof(sg));

            if (sg.rollno == r)
            {
                flag = 1;
                break;
            }
            r1 = (r1 + 1) % size;
            i++;
        }
        if (flag == 1)
        {
            cout << "Found\n";
            sg.display();
            cout << "Enter new name : ";
            cin >> sg.name;
            fout.seekp(sizeof(sg) * r1, ios::beg);
            fout.write((char *)&sg, sizeof(sg));
        }
        else
        {
            cout << "Not found.\n";
        }
        fout.close();
    }

    void del()
    {
        int r;
        cout << "Enter the roll no of the student : ";
        cin >> r;
        int r1 = r % size;
        int flag = 0;
        fstream fout;
        fout.open("data.txt", ios::in | ios::out | ios::binary);
        int i = 0;
        while (i < size)
        {
            fout.seekg(sizeof(sg) * r1, ios::beg);
            fout.read((char *)&sg, sizeof(sg));

            if (sg.rollno == r)
            {
                flag = 1;
                break;
            }
            r1 = (r1 + 1) % size;
            i++;
        }
        if (flag == 1)
        {
            cout << "Deleted.\n";
            sg = Student();
            fout.seekp(sizeof(sg) * r1, ios::beg);
            fout.write((char *)&sg, sizeof(sg));
        }
        else
        {
            cout << "Not found.\n";
        }
        fout.close();
    }
};

int main()
{
    HashFile H(26);
    H.init();
    int ch;
    char yes = 'y';

    do
    {
        cout << "1.Create.\n2.Add.\n3.Update.\n4.Remove\n5.Display\n6.Find.\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {

            int n;
            cout << "Enter the no entries to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++)
                H.create();
            break;
        }
        case 2:
            H.create();
            break;
        case 3:
            H.update();
            break;
        case 4:
            H.del();
            break;
        case 5:
            H.display1();
            break;
        case 6:
            H.find();
            break;
        default:
            cout << "Wrong choice";
        }
        cout << "Continue?(y/n)\n";
        cin >> yes;
    } while (yes == 'y');
    return 0;
}
