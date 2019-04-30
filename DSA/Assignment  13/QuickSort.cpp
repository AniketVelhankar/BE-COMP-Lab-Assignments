#include <iostream>
using namespace std;
#define M 7
class QSort
{
public:
	void display(float a[])
	{
		cout<<"\n Top Five Scores Are:\n";
		for(int i=5;i<10;i++)
		{
			cout<<"\n"<<a[i];
		}
	}
	void quickSort(float a[],float first,float last)
	{
		int pivot, j, i;
		float temp;
		if(first<last)
		{
			pivot=first;
			i=first;
			j=last;
			while(i<j)
			{
				while(a[i]<=a[pivot]&&i<last)
					i++;
				while(a[j]>a[pivot])
					j--;
				if(i<j){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
			temp=a[pivot];
			a[pivot]=a[j];
			a[j]=temp;
			quickSort(a,first,j-1);
			quickSort(a,j+1,last);
		}
	}
};
int main()
{
	QSort a;
	int N=10;
	float x[N];
	cout<<"\n Enter Array Elements:";
	for(int i=0;i<10;i++)
	{
		cin>>x[i];
	}
	a.quickSort(x,0,N-1);
	a.display(x);
	return 0;
}
