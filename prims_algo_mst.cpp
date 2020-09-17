#include <bits/stdc++.h>

using namespace std;


#define INF INT_MAX
#define NONE -1

typedef pair<int, int> Pair;

class Graph
{
    int V;
    // since we will be allocating the graph size dynamically, we are creating a reference object
    vector<Pair> *graph; // stores the <vertex, weight>


public:
    Graph(int _V)
    {
        V = _V;
        graph = new vector<Pair> [V+1];

    }

    // adds an edge to the graph
    void addEdge(int u, int v, int w)
    {
        // for undirected graph
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));

    }

    void prim_mst();
};



void Graph::prim_mst()
{

    bool visited[V+1] = {false}; // stores the visited nodes
    int src = 1; // source node assumed to be 1
    priority_queue< Pair, vector <Pair>, greater<Pair> > pq; // first = weight, second = label of vertex
    vector<int> key(V+1, INF);  // holds the key values set to INF initially
    vector<int> parent(V+1, NONE); // holds the parent array to store the MST result

    pq.push(make_pair(0, src));  // push the first node into the min_heap
    key[src] = 0; // set the key to 0

    while (!pq.empty())
    {
        int u = pq.top().second; // u now contains the label of the vertex
        pq.pop();

        visited[u] = true;  // mark it visited

        for (auto v: graph[u])
        {
            // Get vertex label and weight of current adjacent of u.
            int vertex = v.first;
            int weight = v.second;

            //  If v is unvisited and weight of (u,v) is smaller
            // than current key of v
            if (!visited[vertex] && (key[vertex] > weight))
            {
                // Updating key of v
                key[vertex] = weight;
                pq.push(make_pair(key[vertex], vertex));
                parent[vertex] = u;
            }
        }
    }


     // Print the result
    for (int i = 1; i <= V; i++)
        cout << parent[i] << " -- > " << i << endl;

}



int main()
{
    int V, E;
    int u,v,w;
    cin >> V >> E;

    Graph graph(V);
    // taking input
    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);

    }

    graph.prim_mst();


    return 0;
}

/*
7 9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
*/

