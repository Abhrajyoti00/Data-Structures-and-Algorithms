#include <bits/stdc++.h>
using namespace std;

int minFlips (string S){
    int c1 = 0; // Even = 1, odd = 0 then true
    int c2 = 0; // Even = 0, Odd = 1 then true
    for (int i = 0; i <S.length(); i++){
        if (i%2 == 0){
            if (S[i] == '0')
                c1++;
            else
                c2++;
        }
        
        else{
            if (S[i] == '0')
                c2++;
            else
                c1++;
        }
    }
    int change = min(c1,c2);
        
    return change;
}


int main(){
    int i,j,n;string S;
    cin>>S;
    cout<<minFlips(S)<<endl;
}