#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    set<int>s;
    int i;
    for(i=0; i<n; i++)
        s.insert(a[i]);
    for(i=0; i<m; i++)
        s.insert(b[i]);
    return s.size();
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    int b[m];
    for(int i=0;i<m;i++)
        cin>>b[i];

    cout<<doUnion(a, n, b, m)<<endl;
}