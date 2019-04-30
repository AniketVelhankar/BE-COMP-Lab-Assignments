/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

#define MAX 3
class sparse
{
    public:
void readsparse(int b[MAX][3])
{
    
    int i,v;
    cout<<"enter the no of non-zero values";
    cin>>v;
    b[0][2]=v;
    for(i=1;i<=v;i++)
    {
        cout<<"enter the next triplet(rows,coloumns,value)";
        cin>>b[i][0]>>b[i][1]>>b[i][2];
    }
   
}
 void printsparse(int b2[MAX][3])
{
    int i,n;
    n=b2[0][2];
    cout<<"rows="<<b2[0][0]<<"coloums="<<b2[0][1]<<endl;
    for(i=0;i<=n;i++)
    {
        cout<<b2[i][0]<<" "<<b2[i][1]<<" "<<b2[i][2]<<endl;
    }
}
 void addsparse(int b1[MAX][3],int b2[MAX][3],int b3[MAX][3])
{
   
int t1,t2,i,j,k;
   
if(b1[0][0]!=b2[0][0]||b1[0][1]!=b2[0][1])
    {
       
cout<<"\nYou have entered invalid matrix!!Size must be equal";
       
exit(0);
    }
   
t1=b1[0][2];
   
t2=b2[0][2];
   
i=j=k=0;
   
b3[0][0]=b1[0][0];
   
b3[0][1]=b1[0][1];
   
while(i<=t1&&j<=t2)
    {
       
if(b1[i][0]<b2[j][0])      
//row numbers are not equal
       
{
           
b3[k][0]=b1[i][0];
           
b3[k][1]=b1[i][1];
           
b3[k][2]=b1[i][2];
           
k++;
           
i++;
       
}
       
else if(b2[j][0]<b1[i][0])      
//row numbers are not equal
       
{
           
b3[k][0]=b2[j][0];
           
b3[k][1]=b2[j][1];
           
b3[k][2]=b2[j][2];
       
    k++;
           
j++;
       
}
       
else if(b1[i][1]<b2[j][1])      
//row numbers are equal, compare column
       
{
           
b3[k][0]=b1[i][0];
           
b3[k][1]=b1[i][1];
           
b3[k][2]=b1[i][2];
           
k++;
           
i++;
        }
       
else if(b2[j][1]<b1[i][1])      
//row numbers are equal, compare column
       
{
           
b3[k][0]=b2[j][0];
           
b3[k][1]=b2[j][1];
           
b3[k][2]=b2[j][2];
           
k++;
           
j++;
       
}
       
else
       
{
           
b3[k][0]=b1[i][0];      //row and column numbers are equal
           
b3[k][1]=b1[i][1];
           
b3[k][2]=b1[i][2]+b2[j][2];
           
k++;
           
i++;
           
j++;
       
}
    }
   
while(i<=t1)        //copy remaining terms from b1
    {
       
b3[k][0]=b1[i][0];
       
b3[k][1]=b1[i][1];
       
b3[k][2]=b1[i][2];
       
i++;
       
k++;
    }
   
while(j<=t2)        //copy remaining terms from b2
    {
       
b3[k][0]=b2[j][0];
       
b3[k][1]=b1[j][1];
       
b3[k][2]=b1[j][2];
       
j++;
       
k++;
    }
   
b3[0][2]=k-1;       //set number

}

};
int main()
    {
        sparse s;
        
   int m,n,v,b1[MAX][3],b2[MAX][3],b3[MAX][3];
   cout<<"enter no of rows";
   cin>>m;
   cout<<"enter no of columns";
   cin>>n;
   b1[0][0]=m;
   b1[0][1]=n;
   b2[0][0]=m;
   b2[0][1]=n;
   
   s.readsparse(b1);
   s.readsparse(b2);
   s.addsparse(b1,b2,b3);
   s. printsparse(b3);
   

    return 0;
}
