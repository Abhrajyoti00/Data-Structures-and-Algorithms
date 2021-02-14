// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n)
{
    int s, s1 = 0;
    s = INT_MIN;
    int i;
    for (i = 0; i < n; i++){
        s1+=arr[i];
        if(s1>s)
            s=s1;
        if(s1<0)
            s1=0;
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxSubarraySum(arr, n);
}