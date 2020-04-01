#include <bits/stdc++.h>

using namespace std;

/*
The program finds the diameter of a k-ary tree based on their weights.
*/

/*
Returns a leaf node by using bfs traversal
parameters: start: source node
           n: number of nodes
           graph[]: the adjacency vertices along with their weights
           depth[]: contains the depth of ith nodes
*/
int bfs(int start, vector<pair<int, int>> graph[], int n, int depth[])
{
    queue<int> g_queue;
    g_queue.push(start);
    bool visited[n + 1] = {false};
    visited[start] = true;

    while (!g_queue.empty())
    {
        start = g_queue.front();
        g_queue.pop();

        // for every unvisited vertex v adjacent to node start
        // push it into the queue
        for (auto v : graph[start])
        {
            if (!visited[v.first])
            {
                visited[v.first] = true;
                g_queue.push(v.first);
                 // since, the edges have weights, we are adding it
                // if the weights weren't there, then we could have just added 1 to depth[start]
                depth[v.first] = depth[start] + v.second;

            }
        }
    }


    return int(max_element(depth + 1, depth + n + 1) - depth);
}

int main()
{

    int n, u, v, w;

    cin >> n; // number of nodes of a k-ary tree
    vector<pair<int, int>> graph[n + 1];
    // stores the depth of node i, where i is the index, from the start node
    // so, the diameter of a tree would be the maximum element in this array
    int depth[n + 1] = {0};


    // taking input
    // the edge weights are stored as a pair
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int start_leaf = bfs(1, graph, n, depth);        // start traversal from node 1. Any node would do. Returns a leaf node
    // initialize it to 0 again
    for(int i=1; i<=n; i++)
        depth[i] = 0;

    int end_leaf = bfs(start_leaf, graph, n, depth); // now traverse the graph from one leaf node to another.

    cout << depth[end_leaf] << endl;

    return 0;
}

