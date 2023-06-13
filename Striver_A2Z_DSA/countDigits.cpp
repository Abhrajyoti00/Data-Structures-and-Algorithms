#include<bits/stdc++.h>
using namespace std;

int evenlyDivides(int N){
    vector<char>s;
    string str = to_string(N);
    for(char it : str){
        if(it!='0')
        s.push_back(it);
    }
    int c = 0;
    for(char it : s){
        if(N%(it-'0')==0)
            c++;
    }
    return c;
}

int main(){
    int N;
    cin>>N;
    cout<<evenlyDivides(N);
    return 0;
}
