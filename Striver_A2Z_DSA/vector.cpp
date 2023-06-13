#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);
    cout<<v[0]<<"\n";
    cout<<v[1]<<"\n";
    vector<int>v1(5,20);
    for(auto it : v1)
        cout<<it<<" ";
        vector<pair<int,int>>v2;
        v2.push_back({4,5});
    cout<<"\n"<<v2[0].second<<endl;
    vector<int>v3;
    vector<int>v4;
    vector<int>v5;

    return 0;
}