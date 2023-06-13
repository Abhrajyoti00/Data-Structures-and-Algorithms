#include<bits/stdc++.h>
using namespace std;

long long gcd ( long long a, long long b){
    while(a > 0 && b> 0){
            if(a>=b)
                a = a%b;
            else 
                b = b%a;
        }
        if(a == 0)
        return (b);
        else 
        return a;
}
vector<long long> lcmAndGcd(long long a , long long b) {
        vector<long long> v;
        v.push_back(gcd(a,b));
        v.push_back((a*b)/gcd(a,b));
        return v;
        
    }

int main(){
    long long a, b;
    cin>>a>>b;
    vector<long long> v = lcmAndGcd(a,b);
    for(auto it : v)
        cout<<it<< " ";
}