/*There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph. Justify the storage representation used.(Operation to be performed  1. adding and deleting edge,
2. adding and  deleting vertices, 
3. calculated in-degree and 
4. out-degree for directed graph and
 degree of a node in undirected graph, Use any traversal to  traverse through the graph)
*/
#include<iostream>
using namespace std;
class node
{
public:
	string city;
	int cost;
	node *next;
	node()	
	{
		next=NULL;
	}
};

class graph
{
	int n;
	node *head[20];
public:
	graph()
	{
		for(int i=0;i<20;i++)
		{
			head[i]=NULL;
		}
	}
	int visited[20];
	int getdata(bool k)
	{
		string city;
		cout<<"Enter the no of city \n";
		cin>>n;	
		cout<<"Enter the cities\n";
		for(int i=0;i<n;i++)
		{
			cout<<i+1<<" ";
			cin>>city;
			head[i]=new node;
			head[i]->city=city;
		}		
		string source,dest;
		cout<<"Enter the no of flight \n";
		int flight;
		cin>>flight;
		cout<<"Enter the source and Destination of flight\n";
		for(int i=0;i<flight;i++)
		{
			cout<<"Source      :";
			cin>>source;
			cout<<"Destination :";
			cin>>dest;	
			edge(source,dest,k);
		}
	}
	void edge(string source,string dest,bool k)
	{
		node *temp=new node;
		
		for(int i=0;i<n;i++)
		{	node *follow=new node;
			temp=head[i];
			if(temp->city==source)
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				follow->city=dest;
				temp->next=follow;
				follow->next=NULL;
				break;
			}
		}
		if(k==0)
		{	node *follow=new node;
			for(int i=0;i<n;i++)
			{
				temp=head[i];
				if(temp->city==dest)
				{
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					follow->city=source;
					temp->next=follow;
					follow->next=NULL;
					break;
				}
			}
		}		
	}
	int display()
	{
		node *temp=new node;
		for(int i=0;i<n;i++)
		{
			temp=head[i];
			while(temp->next!=NULL)
			{
				cout<<temp->city<<"->";
				temp=temp->next;
			}
			cout<<temp->city;
			cout<<endl;
		}
	}
	void result()
	{
	}
	int Insert_vertex(bool k)
	{
		string city;
		int m;
		cout<<"Enter the no of city \n";
		cin>>m;	
		cout<<"Enter the cities\n";
		for(int i=n;i<m+n;i++)
		{
			cout<<i+1<<" ";
			cin>>city;
			head[i]=new node;
			head[i]->city=city;
		}		
			n=n+m;
		string source,dest;
		cout<<"Enter the no of flight \n";
		int flight;
		cin>>flight;
		cout<<"Enter the source and Destination of flight\n";
		for(int i=0;i<flight;i++)
		{
			cout<<"Source      :";
			cin>>source;
			cout<<"Destination :";
			cin>>dest;	
			edge(source,dest,k);
		}
	} 
	int new_path(bool k)
	{
		string source,dest;
		cout<<"Enter the no of flight \n";
		int flight;
		cin>>flight;
		cout<<"Enter the source and Destination of flight\n";
		for(int i=0;i<flight;i++)
		{
			cout<<"Source      :";
			cin>>source;
			cout<<"Destination :";
			cin>>dest;	
			edge(source,dest,k);
		}
	}
	int Delete_path(bool k)
	{
		string source,dest;
		cout<<"Which path u want to delete?\n";
		cout<<"Source      :";
		cin>>source;
		cout<<"Destination :";
		cin>>dest;
		node *temp=new node;
		node *follow=new node;
		
		for(int i=0;i<n;i++)
		{
			temp=head[i];
			if(temp->city==source)
			{
				while(temp!=NULL && temp->city!=dest)
				{
					follow=temp;
					temp=temp->next;	
				}
				if(temp->city==dest)
				{
					if(temp->next==NULL)
					{
						follow->next=NULL;
						delete temp;
					}
					else
					{
						follow->next=temp->next;
						delete temp;
					}
				}
			}
		}
		if(k==0)
		{
			node *follow=new node;
			for(int i=0;i<n;i++)
			{
				temp=head[i];
				if(temp->city==dest)
				{
					while(temp!=NULL && temp->city!=source)
					{
						follow=temp;
						temp=temp->next;	
					}
					if(temp->city==source)
					{
						if(temp->next==NULL)
						{
							follow->next=NULL;
							delete temp;
						}
						else
						{
							follow->next=temp->next;
							delete temp;
						}
					}
				}
			}
		}	
	}
	int in()
	{
		cout<<"Enter the city for incoming flights\n";
		string city;
		cin>>city;
		int in=0;
		node *temp=new node;
		for(int i=0;i<n;i++)
		{
			temp=head[i];
			if(temp->city!=city)
			{
				while(temp!=NULL)
				{
					if(temp->city==city)
						in++;
					temp=temp->next;
				}
			}
		}
		cout<<"Incoming flights "<<in;
	}
	int out()
	{
		cout<<"Enter the city for outgoing flights\n";
		string city;
		cin>>city;
		int out=0;
		node *temp=new node;
		for(int i=0;i<n;i++)
		{
			temp=head[i];
			if(temp->city==city)
			{
				while(temp!=NULL)
				{
					out++;
					temp=temp->next;
				}
				break;
			}
		}
		cout<<"Outgoing flights "<<out-1;
	}	
	int Delete_vertex()
	{
		cout<<"Enter the city u want to delete\n";
		string city;
		cin>>city;
		node *follow=new node;
		node *temp=new node;
	
		for(int i=0;i<n;i++)
		{
			temp=head[i];
			if(temp->city!=city)
			{
				while(temp!=NULL && temp->city!=city)
				{
					follow=temp;
					temp=temp->next;
				}
				if(temp->city==city)
				{
					if(temp->next==NULL)
					{
						follow->next=NULL;
						delete temp;
					}
					else
					{
						follow->next=temp->next;
						delete temp;
					}
				}

			}
		}
		for(int i=0;i<n;i++)	
		{
			temp=head[i];
			if(temp->city==city)
			{
				temp->next=NULL;
				delete temp;
			}
		}
	}
	
	
void dfsTraversal()
	{
		for( int i=0;i<n;i++)
			visited[i]=0;
		cout<<"\nDFS TRAVERSAL: \n";
		DFS(head[0]->city);
		cout<<"\n";
	}
void DFS(string str)
{
	node *p = new node;
	int ind;
	
	for(int i=0;i<n;i++)
	{
		if(head[i]->city==str)
			ind = i;
	}
	
	cout<<" "<<str<<" ";
	p=head[ind];
	visited[ind]=1;
	while(p!=NULL)
	{
		str=p->city;
		for(int i=0;i<n;i++)
	{
		if(head[i]->city==str)
			 ind = i;
	}
		if(!visited[ind])
			DFS(str);
		p=p->next;
	}

}

};

int main()
{
	graph g;

		bool con;
        int res,flight,n1;
		char ch;	
		string source,dest;
        cout<<"0. Undirected\n1.Directed\nEnter Flight data Insertion Type:"<<endl;
        cin>>con;
        if(con==0)
        {
            g.getdata(0);
        }
        else
        {
            g.getdata(1);
        }
		g.display();
       do
		{
			cout<<"Which operation you want to perform ?\n"<<endl;
    	    cout<<"In which mode u want perform the operation on graph ?\n"<<endl;
        	cout<<"1. Insert the city\n2. Delete the Airport\n";
			cout<<"3. Add the new path\n4. Delete the path\n";
			cout<<"5. Upcoming flights\n6. Outgoing flights\n";
			cout<<"7. DFS\n";
        	cin>>res;
        	switch(res)
        	{
        	    case 1:
        	    	    g.Insert_vertex(con);
						g.display();
        	    	   break;
        	    case 2:
        	            g.Delete_vertex();
						g.display();
        	            break;
        	    case 3:
						g.new_path(con);
						g.display();
        	    	    break;
        	    case 4: g.Delete_path(con);
						g.display();
        	            break;
				case 5:
			   			g.in();
        	            break;
				case 6:
			   			g.out();
        	            break;
        	    case 7: 
        	    		g.dfsTraversal();
        	    		break;

        	}
			cout<<"Do you want to continue(y/n)?";
			cin>>ch;
		}while(ch=='y' ||ch=='Y');	return 0;
}
