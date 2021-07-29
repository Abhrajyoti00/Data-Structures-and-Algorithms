#include <bits/stdc++.h>
using namespace std;
int FindMaxSum(int arr[], int n)
{
    int i, j, s = 0;
    for (int i = 0; i < n; i+=2)
    {
        s+= arr[i];
    }
    return s;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    cout<<FindMaxSum(arr, n);
}