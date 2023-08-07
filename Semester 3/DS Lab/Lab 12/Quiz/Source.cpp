#include <iostream>
#include <vector>
using namespace std;

class graph
{
	vector<int> adj[4];
	bool visited[4];

public:

	void addEdge(int src, int des)
	{
		adj[src].push_back(des);
	}

	void dfs(int s)
	{
		visited[s] = true;
		for (int i = 0; i < adj[s].size(); i++)
		{
			if (visited[adj[s][i]] == false)
				dfs(adj[s][i]);
		}
	}


};


int main()
{
	graph g1;
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(2, 4);
	g1.addEdge(3, 4);
	g1.addEdge(3, 5);



}