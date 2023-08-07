#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Edge
{
	int src;
	int des;
};

class Graph
{
public:
	vector<vector<int>> adjList;
	Graph(vector<Edge> const& edges, int n)
	{
		adjList.resize(n);

		for (auto& edge : edges)
		{
			adjList[edge.src].push_back(edge.des);
			adjList[edge.des].push_back(edge.src);
		}
	}
};

void BFS(Graph const& graph, int v, vector<bool>& isDiscovered)
{
	queue<int> q;
	isDiscovered[v] = true;
	q.push(v);

	while (!q.empty())
	{
		v = q.front();
		q.pop();
		cout << v << " ";

		for (int u : graph.adjList[v])
		{
			if (!isDiscovered[u])
			{
				isDiscovered[u] = true;
				//cout << "RESET:";
				q.push(u);
			}
		}
	}
}

void DFS_Rec(Graph const& graph, int v, vector<bool>& isDiscovered, int * arr,int n)
{
	static int dis = 6;
	static bool ended = false;
	static bool reset = true;
	isDiscovered[v] = true;

	cout <<"For Vertex:"<< v << " dis:"<<dis<<endl;
	arr[v] = dis;

	for (int u : graph.adjList[v])
	{
		if (!isDiscovered[u])
		{
			reset = true;
			dis += 6;
			DFS_Rec(graph, u, isDiscovered,arr,n);
			dis -= 6;
			ended = true;
			if (ended && reset)
			{
				arr[v + 1] -= 6;
				dis -= 6;
				cout << "For Vertex:" << v+1 << " dis:" << dis << endl;
				reset = false;
			}
		}

	}
}


int main()
{

	// vertex 6 is single node
	vector<Edge> edges = {
		{1,2},{1,5},{2,3},{3,4}
	};

	int n = 6;

	Graph g1(edges, n);
	vector <bool> isDiscovered(n, false);


	int* arr = new int[n];

	for (int i = 1; i < n; i++)
	{
		if (!isDiscovered[i])
		{
			DFS_Rec(g1, i, isDiscovered,arr,n);
		}
	}

	
	cout << endl << endl;
	for (int i = 1; i < n; i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}



