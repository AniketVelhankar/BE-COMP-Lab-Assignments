#include<iostream>

#define A 7687
#define B 6899
#define C 4909
#define D 997


using namespace std;

int HighLevel(const char* s)
{
    unsigned h = D;

    while(*s)
    {
        h = (h*A) ^ (s[0] * B);
        s++;
    }
    return h%D; 
}

int hashIT(string q)
{
    int sum = 0;
    for(int k = 0;k<q.length();k++)
    {
        sum = sum + int(q[k]);
    }

    return sum%512;
}

int HashNew(string q)
{
    int seed = 131;

    unsigned long hashnum = 0;

    for(int i = 0;i<q.length();i++)
    {
        hashnum = (hashnum*seed) + q[i];
    }

    return hashnum%26;
}


int main()
{
    cout<<HashNew("ARD");
    return 1;
}