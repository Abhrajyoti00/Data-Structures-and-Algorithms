#include <bits/stdc++.h>
using namespace std;
int main(){
    int i = 10;
    int *p = &i;
    cout<<p<<endl;
    p = p+1; //added 4 bytes
    cout<<p<<endl;
    p = p+2; //added 8 bytes
    cout<<p<<endl;
    p = p-2; //moved back 8 bytes
    cout<<p<<endl;

    double d = 102.23;
    double *dp = &d;
    cout<<dp<<endl;
    dp++;
    cout<<dp<<endl;
}