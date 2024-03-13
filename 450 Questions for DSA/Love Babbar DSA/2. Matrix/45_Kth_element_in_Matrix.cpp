#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int temp[n*n+1];
    int c = 0;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n; j++){
            temp[c++] = mat[i][j];
        }
    }
    sort(temp, temp+n);
    return k+1;
}

