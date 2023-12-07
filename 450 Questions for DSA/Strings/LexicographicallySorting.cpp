#include<bits/stdc++.h>
using namespace std;


void Print(vector<string>v){
    for(auto i : v)
        cout<<i<<" ";
}

bool my_compare(string s1, string s2){
    if((s1.compare(0, s2.length(), s2) == 0) || (s2.compare(0, s1.length(), s1) == 0))
        return s1.length()>s2.length();
    
    return s1<s2;
}

int main(){
    string s1;
    vector<string>v;

    getline(cin, s1);
    istringstream iss(s1);
    while (iss >> s1) {
        v.push_back(s1);
    }

    //sort(v.begin(), v.end(), my_compare);
    sort(v.begin(), v.end());
    Print(v);
    return 0;
}