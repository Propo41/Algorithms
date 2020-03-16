#include <bits/stdc++.h>

using namespace std;


vector<int> countingSort(vector<int> A, vector<int> B, int k)
{
    vector<int> C(k+1, 0);

    for(int j=1; j<A.size(); j++)
          C[A[j]]+=1;

    for(int i=1; i<=k; i++)
        C[i]+=C[i-1];

    for(int j=A.size()-1; j>=1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] -= 1;
    }

    return B;


}
void print(vector<int> vec)
{
     for(int i=1; i<vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

}
int main()
{

    vector<int> src;
    int n = 10;
    // the first index is trash. index for input and output array starts from 1 and ends at n-1
    for (int i=0; i<n; i++)
        src.push_back(rand()%10);
    cout << "before sort: ";
    print(src);
    vector<int> output(src.size());
    vector<int> sorted = countingSort(src, output, *max_element(src.begin(), src.end()));
    cout << "after sort: ";
    print(sorted);





    return 0;
}
