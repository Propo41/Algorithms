#include <bits/stdc++.h>

using namespace std;

const int v = 5; // number of nodes

void dfs(int graph[v][v], int curr, int n)
{
    bool visited[n]= {false};
    stack<int> g_stack;
    g_stack.push(curr);

    while(!g_stack.empty())
    {
        curr = g_stack.top();

        if (!visited[curr]) // if topmost element is unvisited
        {
             visited[curr] = true; // mark it visited
             cout << curr << " ";  // and print it
             g_stack.pop();

        }
        // push all adjacent unvisited nodes of stack's top most element
        for (int i=0; i<n; i++)
            if (!visited[i] && graph[curr][i])
                g_stack.push(i);

    }
    cout << endl;



}


int main()
{
    int graph[v][v]; // adjacency matrix
    memset(graph, 0, sizeof(graph));
    int a,b;
    //taking input of either directed or undirected graph until -1 is entered
    //adjacency matrix used
    while(true)
    {
        cin >> a;
        if (a==-1)
            break;
        cin >> b;
        graph[a][b] = 1;
    }

    // the graph, starting node and number of nodes is passed
    dfs(graph, 0, v);



    return 0;
}

