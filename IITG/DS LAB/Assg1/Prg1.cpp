#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, ￼￼return the number of pairs (i, j) where i < j
// such that |nums[i] - nums[j]| == k.

int main(){
    int n;
    cout<<"Enter the number of elements present in the array nums :- \n";
    cin>>n;
    int nums[n];
    cout<<"Enter the elements :- \n";
    for(int i =0; i<n; i++)
        cin>>nums[i];
    map<int, int> freq_map;
    cout<<"Enter the value of k \n";
    int k;
    cin>>k;
    for(int i =0; i<n; i++)
    {
        freq_map[nums[i]]++;
    }
    int ans = 0;
    for(int i =0; i<n; i++){
        ans+=freq_map[nums[i]-k];
    }
    cout<<ans;
}