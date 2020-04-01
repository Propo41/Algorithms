#include <bits/stdc++.h>

using namespace std;


/*
Returns the min number of prefix reversals required to sort the array
in ascending order

HOW: BFS is used. We think of each node as a permutation of the strings being reversed in prefix order.
For example: (3 1 2) is first reversed to (1 3 2) and then (2 1 3) in a linear fashion. So, in this case,
both (1 3 2) and (2 1 3) are considered as nodes that are to be pushed into the bfs queue.
The number of reversals required are tracked using a pair object.
The pair holds both the nodes (aka strings) and the count for the amount of reversals performed
*/
int prefixReversalSort(string start, string dest, int n)
{

    queue< pair<string, int> > bfs_queue;
    pair< string, int > curr; // used to store/point towards the top most node in the queue
    map <string, bool> visited;

    curr = make_pair(start, 0); // the curr node now holds the initial string and a count of 0 reversals.
    bfs_queue.push(curr);

    while(!bfs_queue.empty())
    {
        curr = bfs_queue.front();
        visited[curr.first]=true;
        bfs_queue.pop();

        // permute the string by reversing every characters from index 2 to n
        // and push it into the queue
        for(int i = 2; i <= n; i++)
        {
            // storing the string in a temp variable to keep it unscathed,
            //since we'll be needing it for rest of the iterations
            string temp = curr.first;
            // reverse the string till prefix i
            reverse(temp.begin(), temp.begin()+i);

            //if the reversed sting is already in the visited set, the don't push it
            if(visited.count(temp)==1)
                continue;

            // if while reversing, we get the sorted string, return it
            if(temp == dest)
                return curr.second + 1;

            bfs_queue.push(make_pair(temp, curr.second+1));

        }

    }



}

int main()
{
    int n,a;
    cin >> n;

    int arr[n+1];
    string start="", dest = "";

    for(int i=0; i<n; i++)
    {
        cin >> a;
        arr[i]=a;
        start+=to_string(a);
    }

    sort(arr, arr+n);
    for(int i=0; i<n; i++)
        dest += to_string(arr[i]);

    if(start == dest)
        cout << 0 << endl; // since it's already sorted
    else
        cout << prefixReversalSort(start, dest, n) << " prefix reversals need to be performed to sort it" << endl;


    return 0;
}


