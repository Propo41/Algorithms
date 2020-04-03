#include <bits/stdc++.h>

/*
Works for cases where every edge has weight as either 0 or 1

tutorial: https://www.youtube.com/watch?v=cMP1IaWuFuM
https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/
The approach is similar to Dijkstra that the if the shortest distance to node is relaxed by the
previous node then only it will be pushed in the queue.

*/

using namespace std;

void bfs_0_1(vector<pair<int,int>> graph[], int V, int source)
{

    deque <int> q;
    q.push_back(source);

    int cost[V+1];
    for(int i=1; i<=n; i++)
        cost[i]=INT_MAX;

    cost[source] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop_front();

        for(auto v: graph[u])
        {
            // if the cost for traveling from u to v
            // is less than the current cost of v,
            // then update the cost of v
            if(cost[u] + v.second < cost[v.first])
            {
                cost[v.first] = cost[u] + v.second;
                //if the edge weight to travel from u - v
                // is 1, then push v at the back, else front
                if(v.second)
                    q.push_back(v.first);
                else
                    q.push_front(v.first);

            }

        }

    }

    for(int i=1; i<=V; i++)
        cout << "cost to travel from " << source << " to " << i << " is: " << cost[i] << " ";
    cout << endl;


}



int main()
{
    int V,E;
    int u,v,w;

    cin >> V >> E;

    vector<pair<int,int>> graph[V+1];

    // taking input 1-V
    // graph[] contains both the edge eight and the adjacent nodes
    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }

    bfs_0_1(graph, V, 1);



    return 0;
}


