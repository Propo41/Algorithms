#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
public:

    vector<vector<int>> adjList;
    Graph(vector<Edge> edges, int nodes)
    {
        // resizes the vector to N elements
        adjList.resize(nodes);
        for (auto edge: edges)
            adjList[edge.src].push_back(edge.dest);
    }

};

// uses modified DFS to iterate through unvisited vertices and when a vertex has no other
// child nodes, it pops from the stack and is added to the topologically sorted sequence.
void topological_sort_util(Graph graph, vector<bool> &visited, stack<int> &sorted, int root)
{

    stack<int> dfs_stack;
    dfs_stack.push(root);
    // iff all the children of a vertex has been explored, the stack is popped
    // and the popped element is added to the topologically sorted sequence.
    // the bool variable is used to trigger that.
    bool is_explored = false;
    int curr;

    while(!dfs_stack.empty())
    {
        curr = dfs_stack.top();
        if(!visited[curr])
            visited[curr]=true;

        //if there are any unvisited adjacent nodes of the current node, push it into the stack
        for(auto node = graph.adjList[curr].begin(); node!=graph.adjList[curr].end(); node++)
        {
            if(!visited[*node])
            {
                dfs_stack.push(*node);
                visited[*node]=true;
                is_explored = true;
            }
        }

        if (!is_explored)
        {
            sorted.push(curr);
            dfs_stack.pop();
        }
        is_explored = false;

    }

}

// returns the topologically sorted elements as a stack.
stack<int> topological_sort(Graph graph, int nodes)
{
    vector<bool> visited(nodes, false);
    stack<int> sorted;
    // for every unvisited vertex, apply DFS
    for(int vertex=0; vertex<nodes; vertex++)
        if(!visited[vertex])
            topological_sort_util(graph, visited, sorted, vertex);

    return sorted;

}

void print(stack<int> sorted_graph)
{
    while(!sorted_graph.empty())
    {
        cout << sorted_graph.top() << " ";
        sorted_graph.pop();

    }
    cout << endl;

}

int main()
{

    vector<Edge> edges =
    {
        // contains all connected vertices
        //{0, 1}, {0, 2}, {0, 6}, {1, 3}, {1, 4}, {2, 3},{2, 6}, {3, 5}, {3, 4}, {5, 6}

        // contains disconnected vertices
        {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 7}, {4, 5}, {5, 6}
    };
    int nodes = 8;

    Graph graph(edges, nodes);
    print(topological_sort(graph, nodes));

    return 0;

}
