#include <bits/stdc++.h>

using namespace std;



void print(vector<vector<int>> c, int n)
{
    // since for say n inputs, number of matrix is n-1,
    // we only print i = 1 to n-1
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;

    }

}
// matrix chain multiplication with DP
// finds the min number of operations required
// if matrix is 3, then n will be 5 here
int find_min_operations(int d[], int n)
{
    vector<vector<int>> c(n+1, vector<int> (n+1, 0)); // creating a 2D array. initialized to 0
    // all diagonal values will be zero initially since a matrix is not multiplied by itself
    vector<vector<int>> _k(n+1, vector<int> (n+1, 0)); // holds the optimum locations where the parenthesis should be inserted

    // we start from l and increment i from 1 and j from l
    // to access the upper triangular matrix
    for(int l=2; l<=n; l++)
    {
        int j = l;
        for(int i=1; j <= n; i++, j++)
        {

            c[i][j] = INT_MAX;
            for(int k=i; k<j; k++)
            {
                // find the minimum
                int temp = (c[i][k] + c[k+1][j]) + (d[i-1] * d[k] * d[j]);
                if(temp <  c[i][j])
                {
                    c[i][j] = temp;
                    _k[i][j] = k;
                }
            }

        }
    }


    print(_k, n);
  // print(c, n);

    return c[1][n-1];





}

int main()
{
    int n;

    cout << "Enter number of inputs: ";
    cin >> n;

    int d[n]= {0};
    int _d;

    cout << "Enter matrix dimensions: ";
    for(int i=0; i<n; i++)
    {
        cin >> _d;
        d[i]= _d;
    }

    cout << "Min number of operations: " << find_min_operations(d, n) << endl;

    return 0;
}

/*
5
3 2 4 2 5
*/

