#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define NONE -1

/*
utility function to return the node with the min cost.
Linear O(V) complexity
*/
int min_node(int curr_cost[], bool visited[], int V)
{
    int min_cost = INF;
    int min_node=-1;

    for(int i=1; i<=V; i++)
    {
        if(!visited[i] && curr_cost[i] < min_cost )
        {
            min_cost = curr_cost[i];
            min_node = i;
        }

    }

    // if min_node is unchanged, ie still -1, then it means the traversal is complete
    return min_node;

}

void trace_shortest_distance(int curr_cost[], int V)
{
    for(int i=1; i<=V; i++)
        cout << "distance to travel node " << i << " : " << curr_cost[i] << endl;

}



void trace_shortest_path(int parent[], int V)
{
    for(int i=1; i<=V; i++)
    {

        list<int>path;
        int u = i;
        path.push_back(u);
        while(u!=NONE)
        {
            path.push_back(parent[u]);
            u = parent[u];
        }
        cout << "Shortest path from 1 to " << i << " : ";
        while(!path.empty())
        {
            cout << path.back() << " > ";
            path.pop_back();
        }
        cout << endl;
    }

}


void dijkstra(vector<int> graph[],  vector<vector<int>> cost, int V)
{
    // initialize parent array with NONE
    int parent[V+1];
    memset(parent, NONE, sizeof(parent));


    // initialize curr_cost array with INF except node 1
    int curr_cost[V+1];
    for(int i=2; i<=V; i++)
        curr_cost[i]=INF;
    curr_cost[1]=0;

    //initialize visited array with false
    bool visited[V+1]= {false};


    int u;
    for(int i=1; i<=V; i++)
    {
        u = min_node(curr_cost, visited, V);
        // traversal completed
        // no need to iterate all the vertices
        if(u==-1)
            break;

        visited[u] = true;

        for(auto v: graph[u])
        {
            if(!visited[v])
            {
                //relaxing
                if(cost[u][v]+curr_cost[u] < curr_cost[v])
                {
                    curr_cost[v] = cost[u][v]+curr_cost[u];
                    parent[v]=u;
                }
            }
        }

    }

    trace_shortest_distance(curr_cost, V);
    trace_shortest_path(parent, V);


}


int main()
{
    int V,E;
    int u,v,w;

    cin >> V >> E;

    vector<int> graph[V+1];
    vector<vector<int> > cost( V+1, vector<int> (V+1, INF));

    // taking input
    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(v);
        cost[u][v]=w;
    }

    dijkstra(graph, cost, V);


    return 0;
}


