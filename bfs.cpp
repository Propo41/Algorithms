# include <bits/stdc++.h>

using namespace std ;


void bfs ( vector < int > graph[], int curr, bool visited[])
{

    queue < int > g_queue;
    g_queue.push(curr);
    visited[curr]= true ;

    while (!g_queue.empty())
    {
        curr = g_queue.front();
        g_queue.pop();

        // for every unvisited vertex v adjacent to node curr
        // push it into the queue
        for(auto v: graph[curr])
        {
            if(!visited[v])
            {
                visited[v]=true;
                g_queue.push(v);
            }

        }
    }
}


int main ()
{
    int v = 8 ; // number of vertices
    int e = 5;
    vector < int > graph[v];
    int u,v;
//taking input of either directed or undirected graph
// adjacency list used
    for(int i=0; i<e; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        //graph[v].push_back(u); uncomment line for undirected graph
    }
    bfs(graph, 1, v);
    return 0 ;
}
