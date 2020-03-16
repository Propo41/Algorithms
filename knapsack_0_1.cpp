#include <bits/stdc++.h>
#define vec vector<int>

using namespace std;

//complexity 0(rc)
int knapsack(vec wt, vec val, int max_capacity)
{
    int r = wt.size();
    int c = max_capacity;
    vector < vec > sack(r+1, vec (c+1, 0)); // 2D vector initialized all to 0

    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(wt[i-1] <= j)
                //take the best of previous profit and current profit + any remaining value
                sack[i][j] = max(val[i-1] + sack[i-1][j-wt[i-1]], sack[i-1][j]);
            else
                // use the previous profit
                sack[i][j] = sack[i-1][j];
        }
    }

    cout << "Items to be selected: ";
    for(int i=r, j=c; i>0 && j>0 ; i--)
    {
        if(sack[i][j]!=sack[i-1][j])
        {
            cout << wt[i-1] << " ";
            j-=wt[i-1];
        }
    }

    cout << endl << "Maximum profit: " << sack[r][c] << endl;

}

int main()
{

    vec wt{2,4,6,7,8};
    vec val{6,4,2,5,3};
    cout << knapsack(wt, val, 6) << endl;

    return 0;

}
