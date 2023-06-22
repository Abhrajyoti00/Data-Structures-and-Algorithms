#include<bits/stdc++.h>
using namespace std;
    int reverse(int x) {
        int k;
        k = x;
        int rev = 0;
        while(k!=0){
            int r = k%10;
            if(((rev) < pow(-2,31)/10) || ((rev) > (pow(2,31)-1)/10))
                return 0;
            rev = rev*10 + r;
            k/=10;
        }
        return rev;
    }
    int main(){
        int n;
        cin>>n;
        cout<<reverse(n);
    }