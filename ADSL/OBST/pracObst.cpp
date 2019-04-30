#include <iostream>

using namespace std;

float C[20][20];
int R[20][20];

class node
{
    int data;
    node *lchild;
    node *rchild;

  public:
    node()
    {
        lchild = rchild = NULL;
        data = -1;
    }

    friend class OBST;
};

class OBST
{
    node *root;
    int n;

  public:
    OBST(int s)
    {
        n = s;
        root = NULL;
    }

    float optimal(int K[], float P[], float Q[])
    {
        float W[n + 1][n + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                W[i][j] = C[i][j] = R[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            W[i][i] = Q[i - 1] + Q[i] + P[i];
            C[i][i] = W[i][i];
            R[i][i] = i;
        }

        for (int step = 2; step <= n; step++)
        {
            for (int i = 1; i <= n - step + 1; i++)
            {
                int j = i + step - 1;

                W[i][j] = W[i][j - 1] + Q[j] + P[j];
                int k = find(i, j);
                R[i][j] = k;
                C[i][j] = C[i][k - 1] + C[k + 1][j] + W[i][j];
            }
        }

        root = construct(K, 1, n);
        return C[1][n];
    }

    int find(int i, int j)
    {
        float min = 9999.00;
        int l, k;

        for (k = i; k <= j; k++)
        {
            if (C[i][k - 1] + C[k + 1][j] < min)
            {
                min = C[i][k - 1] + C[k + 1][j];
                l = k;
            }
        }
        return l;
    }

    node *construct(int K[], int i, int j)
    {
        node *p;

        if (R[i][j] == 0)
        {
            return NULL;
        }
        else
        {
            p = new node;
            p->data = K[R[i][j]];
            p->lchild = construct(K, i, R[i][j] - 1);
            p->rchild = construct(K, R[i][j] + 1, j);

            return p;
        }
    }

    void inorder(node *t)
    {
        if (t != NULL)
        {
            inorder(t->lchild);
            cout << t->data << "\t";
            inorder(t->rchild);
        }
    }

    node *getroot()
    {
        return this->root;
    }
};

int main()
{
    int n;
    cout << "Enter number of keys" << endl;
    cin >> n;

    OBST obj(n);

    int K[n + 1];
    float P[n + 1];
    float Q[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cout << "\nEnter keys in sorted order";
        cin >> K[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "\nEnter success probability (pi)";
        cin >> P[i];
        while (P[i] < 0 || P[i] > 1)
        {
            cout << "\nInvalid Probability. Enter Again: ";
            cin >> P[i];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << "\nEnter failure probability (qi)";
        cin >> Q[i];
        while (Q[i] < 0 || Q[i] > 1)
        {
            cout << "\nInvalid Probability. Enter Again: ";
            cin >> Q[i];
        }
    }


    float cost = obj.optimal(K, P, Q);

    cout<<"Optimal binary search tree created"<<endl;

    cout<<"Minimal cost is : "<<cost<<endl;

    cout<<"inorder traversal - "<<endl;
    
    obj.inorder(obj.getroot());

    cout<<"\n";

    return 0;
}