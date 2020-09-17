#include <bits/stdc++.h>

using namespace std;


class Subset
{
private:
    vector<int> w;
    vector<int> x;


public:
    int m;

    void printSubset(int k);
    void subsetSum(int s, int k, int r);
    void addElement(int a)
    {
        w.push_back(a);
        x.push_back(0);

    }
};


void Subset::printSubset(int k)
{
    cout << "Printing possible subset: ";
    for(int i=0; i<=k; i++)
    {
        x[i]==1? cout << w[i] << " " : cout << "";

    }
    cout << endl;
}

/*
 * s: sum of elements already chosen
 * k: index of element which is active for selection
 * r: sum of elements remaining
*/
void Subset::subsetSum(int s, int k, int r)
{
    // it is assumed that w[1] <= m and sum of all elements in w[] is >= m
    x[k] = 1;

    if(s+w[k]==m)
    {
        // terminating condition
        printSubset(k);

    }
    // before going to the next child, check if it exceeds m or not
    else if(s+w[k]+w[k+1] <= m)
    {
        subsetSum(s+w[k], k+1, r-w[k]);

    }
    // generate right child during stack pops (if within m)
    if((s+r-w[k] >= m) && (s+w[k+1] <= m))
    {
        x[k]=0;
        subsetSum(s, k+1, r-w[k]);
    }

}



int main()
{

    int n, m, a;
    int total = 0;
    Subset subset;


    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> a;
        subset.addElement(a);
        total+=a;
    }

    cout << "Enter target amount: ";
    cin >> m;

    cout << endl;

    subset.m = m;
    subset.subsetSum(0,0,total);


    return 0;
}

/*
6
5 10 12 13 15 18
30
*/
