#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
private:
    vector<vector<int>> adjList;
    vector <int> indegree;
    int nodes;

public:
    Graph(vector<Edge> edges, int n)
    {
        adjList.resize(n);
        nodes = n;
        vector<int> temp(n, 0);
		indegree = temp;

        for (auto edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            indegree[edge.dest]++;
        }

    }

    bool kahn_topological_sort(vector<int> &sorted);
};


bool Graph :: kahn_topological_sort(vector<int> &sorted)
{
    vector<int> no_degree; // contains nodes that have indegree value 0

    //linear search to find nodes having indegree value 0
    for(int i=0; i<this->nodes; i++)
        if(!indegree[i])
            no_degree.push_back(i);


    while(!no_degree.empty())
    {
        int u = no_degree.back();
        no_degree.pop_back();

        sorted.push_back(u);
        // for all adjacent nodes of u, remove an edge
        // and if it becomes 0, then push it into no_degree
        for(auto v: this->adjList[u])
        {
            indegree[v] -= 1;
            if(!indegree[v])
                no_degree.push_back(v);
        }

    }

    // if graph has edges then graph has at least one cycle
    for (int i = 0; i < this->nodes; i++)
        if (indegree[i])
            return false;


    return true;





}


int main()
{

    vector<Edge> edges =
    {
        { 0, 6 }, { 1, 2 }, { 1, 4 }, { 1, 6 }, { 3, 0 }, { 3, 4 },
        { 5, 1 }, { 7, 0 }, { 7, 1 }
    };

    int n = 8;
    vector<int> sorted;    // contains the topologically sorted nodes

    Graph graph(edges, n);

    // Perform Topological Sort
    if (graph.kahn_topological_sort(sorted))
        for (int i: sorted)
            cout << i << " ";
    else
        cout << "Graph has at least one cycle. Topological sorting is not possible";


    return 0;
}
