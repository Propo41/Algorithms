# include <bits/stdc++.h>
using namespace std ;
void bfs ( vector < int > graph[], int curr, int n)
{
    bool visited[n]= { false };
    queue < int > g_queue;
    g_queue.push(curr);
    visited[curr]= true ;
    while (!g_queue.empty())
    {
        for ( int i= 0 ; i<graph[curr].size(); i++)
        {
            if (!visited[graph[curr][i]])
            {
                visited[graph[curr][i]] = true ;
                g_queue.push(graph[curr][i]);
            }
        }
        curr = g_queue.front();
        cout << curr << " " ;
        g_queue.pop();
    }
}
int main ()
{
    int v = 8 ; // number of nodes
    vector < int > graph[v];
    int a,b;
//taking input of either directed or undirected graph
// adjacency list used
    while ( true )
    {
        cin >> a;
        if (a== -1 )
            break ;
        cin >> b;
        graph[a].push_back(b);
    }
    bfs(graph, 1, v);
    return 0 ;
}
