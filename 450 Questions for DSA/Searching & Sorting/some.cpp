#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll FE(ll X, ll n){
    ll Y;
    if(n==0)    
        return(1);
    else if(n==1)
        return(X);
    else
    {
        Y = FE(X,n/2);
        if(n%2 == 0)
            return (Y*Y);
        else
            return (X*Y*Y);
    }

}

int main()
{
    ll x,y,z,n;
    cin>>x>>n;
    cout<<"The result of X^n="<<FE(x,n) ;
}