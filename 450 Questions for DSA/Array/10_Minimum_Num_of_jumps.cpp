#include <bits/stdc++.h>
using namespace std;

// // O(k^n) Soln
// int minJumps(int i, int arr[], int n){
//     if (i>=n)
//         return INT_MAX;

//     if (i==n-1)
//         return 0;

//     int minvalue = INT_MAX;

//     int steps = arr[i];
//     for (int j=1; j<=steps; j++){
//         minvalue = min(minvalue, minJumps(i+j, arr, n));
//     }
//     return minvalue+1;
// }

// O(n^2) Soln .. DP Soln

int minJumps(int arr[], int n){
    int *jumps = new int[n+1];
    int i, j;
    if (n == 0 || arr[0] == 0)
        return -1;
    jumps[0] = 0;
    for(i = 1; i<n; i++){
        jumps[i] = INT_MAX;

        for(j = 0; j < i; j++){
            if(i<=j+arr[j] && jumps[j]!=INT_MAX){
                jumps[i] = min(jumps[i], jumps[j]+1);  //Jumping from that least position + 1
                break;
            }
        }
    }
    if(jumps[n-1]!= INT_MAX)
        return jumps[n-1];
    else
        return -1;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minJumps(arr, n) << endl;
}

// 5
// 0 1 1 1 1
// Its Correct output is:
// -1



// 10
// 2 3 1 1 2 4 2 0 1 1

// 4