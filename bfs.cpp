#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> graph[], int curr, int n)
{
    bool visited[n] = {false};
    queue<int> g_queue;

    g_queue.push(curr);
    visited[curr]=true;

    while(!g_queue.empty())
    {

        curr = g_queue.front();
        cout << curr << " ";
        g_queue.pop();
        for(auto i=graph[curr].begin(); i!=graph[curr].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                g_queue.push(*i);
            }
        }

    }

}


int main()
{

    int v = 5; // number of nodes (0-4)

    vector<char> graph[v];
    cout << ((char)('A'- 17)) - '0' << endl;
    graph[((char)('A'- 17)) - '0'].push_back('C');




    return 0;
}
