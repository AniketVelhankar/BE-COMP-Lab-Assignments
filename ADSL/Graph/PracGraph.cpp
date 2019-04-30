#include<iostream>
#include<queue>
#include<stack>
#include<cstring>

using namespace std;
class graph {
	int edges,vertices;
	int adj_mat[20][20];
	string cities[20];
public:
	graph();
	virtual ~graph();
	void add_vertex();
	void add_edge();
	int find_city(string);
	void print_graph();
	int degree(string);
	void delete_city();
	void delete_edge();
	void bfs_traversal();
	void dfs_traversal();
};

graph::graph() {
	// TODO Auto-generated constructor stub
	edges=vertices=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			adj_mat[i][j]=0;
		}
	}
}

graph::~graph() {
	// TODO Auto-generated destructor stub
}

void graph::add_vertex()
{
	cout<<"Enter city name"<<endl;
	string city;
	cin>>city;
	int index1 = find_city(city);
	if(index1==-1)
	{

		vertices++;
		cities[vertices]=city;
		index1=vertices;
	}

		cout<<"To how many cities is it connected"<<endl;
		int num;
		cin>>num;
		string con;
		int wt;
		for(int i=0;i<num;i++)
		{
			cout<<"Enter name and dist of connection no. "<<i+1<<endl;
			cin>>con>>wt;
			int index2 = find_city(con);
				if(index2==-1)
				{
					vertices++;
					cities[vertices]=con;
					index2=vertices;
				}

				adj_mat[index1][index2]=wt;
				adj_mat[index2][index1]=wt;
				edges++;

		}


}

int graph::find_city(string city)
{
	for(int i=0;i<20;i++)
	{
		if(city==cities[i])
			return i;
	}
	return -1;
}

void graph::print_graph()
{
	for(int i=0;i<20;i++)
	{
		if(cities[i]!="")
		cout<<cities[i]<<": ";
		for(int j=0;j<20;j++)
		{
			if(adj_mat[i][j]!=0)
				cout<<cities[j]<<"("<<adj_mat[i][j]<<") ";
		}
		if(cities[i]!="")
		cout<<endl;
	}
}
int graph::degree(string x)
{
	int deg=0;
	int index = find_city(x);
	if(index==-1)
		return -1;
	else
	{
		for(int j=0;j<20;j++)
		{
			if(adj_mat[index][j]!=0)
				deg++;
		}
	}
	return deg;
}

void graph::delete_city()
{
	string c;
	cout<<"Enter city to delete"<<endl;
	cin>>c;
	int index = find_city(c);
	if(index!=-1)
	{
		cities[index]="";
		vertices--;
		for(int j=0;j<20;j++)
		{
			if(adj_mat[index][j]!=0)
			{
				adj_mat[index][j]=0;
				adj_mat[j][index]=0;
				edges--;
			}
		}
		cout<<"City deleted"<<endl;
	}
	else
		cout<<"This city does not exist"<<endl;

}
void graph::add_edge()
{
	string s,d;
	cout<<"Enter source and destination"<<endl;
	cin>>s>>d;
	int wt;
	cout<<"Enter distance"<<endl;
	cin>>wt;
	int index1=find_city(s),index2=find_city(d);
	if(index1==-1){
		vertices++;
				cities[vertices]=s;
				index1=vertices;
	}
	if(index2==-1){
			vertices++;
					cities[vertices]=d;
					index2=vertices;
		}
	if(adj_mat[index1][index2]==0)
	{
					adj_mat[index1][index2]=wt;
					adj_mat[index2][index1]=wt;
					edges++;
	}
	else
	{
		cout<<"This path already exists"<<endl;
	}
}

void graph::delete_edge()
{
	string s,d;
		cout<<"Enter source and destination"<<endl;
		cin>>s>>d;
		int index1=find_city(s),index2=find_city(d);
		if(index1!=-1 && index2!=-1)
		{
		adj_mat[index1][index2]=0;
		adj_mat[index2][index1]=0;
		cout<<"Path deleted"<<endl;
		edges--;
		}
		else
		{
			cout<<"Path does not exist"<<endl;
		}
}

void graph::bfs_traversal()
{
	cout<<"Enter city to start traversing"<<endl;
	string city;
	cin>>city;
	cout<<"BFS Traversal:"<<endl;
	bool visited[20];
	for(int i=0;i<20;i++)
		visited[i]=0;
	queue<int>q;
	int index=find_city(city);
	if(index!=-1)
	{
		q.push(index);
		visited[index]=1;

		while(!q.empty())
					{
						int a=q.front();
						q.pop();
						cout<<cities[a]<<" ";
						for(int j=0;j<20;j++)
								{
									if(adj_mat[a][j]!=0 && visited[j]!=1)
									{
										q.push(j);
										visited[j]=1;
									}

								}

					}
		cout<<endl;
	}
	else
		cout<<"City does not exist"<<endl;

}

void graph::dfs_traversal()
{
	cout<<"Enter city to start traversing"<<endl;
		string city;
		cin>>city;
		cout<<"DFS Traversal:"<<endl;
		bool visited[20];
		for(int i=0;i<20;i++)
			visited[i]=0;
		stack<int>s;
		int index=find_city(city);
		if(index!=-1)
		{
			s.push(index);
			visited[index]=1;

			while(!s.empty())
						{
							int a=s.top();
							s.pop();
							cout<<cities[a]<<" ";
							for(int j=0;j<20;j++)
									{
										if(adj_mat[a][j]!=0 && visited[j]!=1)
										{
											s.push(j);
											visited[j]=1;
										}

									}

						}
			cout<<endl;
		}
		else
			cout<<"City does not exist"<<endl;

}


int main()
{
	graph g;
		int choice=0;


			bool b=1;
			string city,s,d;

			while(b){
			cout<<"1.Add city"<<endl;
			cout<<"2.Print list of flights"<<endl;
			cout<<"3.Add edge"<<endl;
			cout<<"4.Calculate degree"<<endl;
			cout<<"5.Exit"<<endl;
			cout<<"6.Delete city"<<endl;
			cout<<"7.Delete path"<<endl;
			cout<<"8.BFS Traversal"<<endl;
			cout<<"9.DFS Traversal"<<endl;
			cout<<"Enter your choice"<<endl;
			cin>>choice;

			switch(choice)
			{
				case 1:

				g.add_vertex();
			break;

			case 2:
				g.print_graph();
				break;
			case 3:
				g.add_edge();
				break;
			case 4:
				cout<<"Enter city"<<endl;
				cin>>city;
				if(g.degree(city)==-1)
					cout<<"This city does not exist"<<endl;
				else
					cout<<"Total no. of flights = "<<g.degree(city)<<endl;
				break;
			case 5:
				return 0;
				break;
			case 6:
				g.delete_city();
				break;
			case 7:
				g.delete_edge();
				break;
			case 8:
				g.bfs_traversal();
				break;
			case 9:
				g.dfs_traversal();
				break;
			default:cout<<"Invalid input"<<endl;
			}

		}
		return 0;


}



