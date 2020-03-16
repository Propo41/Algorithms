#include <bits/stdc++.h>

using namespace std;


void print(vector<double> bucket)
{
    for(int i=0; i<bucket.size(); i++)
        cout << bucket[i] << " ";
    cout << endl;
}


void bucket_sort(vector<double>&A)
{
    map< double, vector<double> > bucket;
    int n = A.size();
    for(int i=0; i<n; i++)
        bucket[floor(n*A[i])].push_back(A[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<bucket[i].size(); j++)
            sort(bucket[i].begin(), bucket[i].end());

    A.clear();

    //concatenating the bucket subintervals
    for(int i=0; i<bucket.size(); i++)
        for(int j=0; j<bucket[i].size(); j++)
            A.push_back(bucket[i][j]);



}


int main()
{

    vector<double>A {0.78, 0.17, 0.39, 0.26, 0.21, 0.12, 0.68};
    cout << "before sort: ";
    print(A);
    bucket_sort(A);
    cout << "after sort: ";
    print(A);




    return 0;
}
