#include<bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(), a.end());
    long long low = 0;
    long long high = m-1;
    long long ans = LLONG_MAX;
    while(high<n){
        // cout<<a[high]<<" "<<a[low]<<endl;
        ans = min(ans, (a[high] - a[low]));
        low+=1;
        high+=1;
    }
    return ans;    
}
