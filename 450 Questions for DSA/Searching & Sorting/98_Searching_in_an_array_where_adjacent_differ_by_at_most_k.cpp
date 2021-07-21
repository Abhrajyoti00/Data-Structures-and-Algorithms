#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while(i<n){
        if(x == arr[i])
            return i;
        i = i + max(1, abs(x-arr[i])/k);
    }
    return -1;
}
int main(){
    int arr[] = {4, 5, 6, 7, 6}, K = 1,X = 6;
    cout<<search(arr, 5, X, K);
}