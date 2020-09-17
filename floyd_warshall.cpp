#include <bits/stdc++.h>

using namespace std;

/*
 * cannot be used for negative cycles
 * works for cyclic graphs as long as there's no negative cycle
 * this algorithm is applicable for vertices starting from 1 to V
*/

#define INF INT_MAX



/*
 * utility function to print the shortest distance from starting node to
 * all other nodes
 */
void print_matrix( vector<vector<int>> graph, int V)
{
    cout << endl;
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(graph[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << graph[i][j];
        }
        cout << endl;
    }

    cout << "------------------------------------------------" << endl;
    cout << endl;

}

void floyd_warshall( vector<vector<int> > graph, int V, vector<vector<int> > parent)
{
    // k is the intermediate node
    for(int k=1; k<=V; k++)
    {
        for(int i=1; i<=V; i++)
        {
            for(int j=1; j<=V; j++)
            {
                // handles overflow since INF is set to INT_MAX
                if(graph[i][k]==INF || graph[k][j]==INF)
                    continue;

                // if cost of traveling from i to j via k is less
                // then replace it
                if(graph[i][k]+graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k]+graph[k][j];
                    parent[i][j] = k;

                }

            }
        }

        cout << "Printing when k = " << k << endl;
        print_matrix(graph, V);
        //print_matrix(parent, V);
        cout << " :::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

    }



    //print_matrix(graph, V);


}



int main()
{
    int V,E;
    int u,v,w;

    cin >> V >> E;

    vector<vector<int> > graph( V+1, vector<int> (V+1, INF)); // creating a dynamic 2D array. initialized to INF
    vector<vector<int> > parent( V+1, vector<int> (V+1, INF)); // for quiz: stores predecessor array
    // initializing the diagonal values with 0
    for(int i=1; i<=V; i++)
    {
        for(int j=1; j<=V; j++)
        {
            if(i==j)
                graph[i][j] = 0; // diagonal values are 0, since i->i traversal not possible
        }
    }

    // taking input
    for(int i=0; i<E; i++)
    {

        cin >> u >> v >> w;
        graph[u][v] = w;
        // uncomment line for undirected graph input
        // graph[v].push_back(u);
        // cost[v][u]=w;

        parent[u][v] = u;

    }


    // for quiz
    cout << "Printing when k = 0" << endl;
    print_matrix(graph, V); // print D
    //print_matrix(parent, V); // print pi

    floyd_warshall(graph, V, parent);


    return 0;
}

/*

4 5
1 3 -2
2 1 4
2 3 3
3 4 2
4 2 -1

*/


