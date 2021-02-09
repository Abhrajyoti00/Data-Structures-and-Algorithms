#include<bits/stdc++.h>
using namespace std;
int minJumps(int i, int arr[], int n){
    if (i>=n)
        return INT_MAX;
    
    if (i==n)
        return 0;
    
    int minvalue = INT_MAX;

    int steps = arr[i];
    for (int j=1; j<=steps; j++){
        minvalue = min(minvalue, minJumps(i+j, arr, n));
    }
    return minvalue+1;


}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minJumps(0, arr, n)<<endl;
}