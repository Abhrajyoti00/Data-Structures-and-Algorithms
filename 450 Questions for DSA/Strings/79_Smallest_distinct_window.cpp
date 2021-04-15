#include<bits/stdc++.h>
using namespace std;
#define NoOfCharacters 256
class Solution{
    public:
    string findSubString(string str)
    {
        int n = str.length();
        int start =  0, end = n-1, i ,j;
        map<char, int>mp;
        for(i = 0; i < n; i++){
            mp[str[i]]++;
        }
        for(auto it:mp){
            for(j = start; j<n; j++){
                cout<<"start: "<<start<<"end : "<<end<<endl;
                if(start == end || start<n && j!=start && str[j] == str[start]){
                    start+=1;
                }
                if(it.first == str[j]){
                    end = j;
                }
            }
        }
        cout<<"start: "<<start<<"end : "<<end<<endl;
        // cout<<start - end<<endl;
        return str.substr(start,start-end);
        // for(i = 0; i< (ascii); i++)
    }
};

int main(){
    string S;
    cin>>S;
    Solution sol;
    // sol.findSubString(S);
    cout<<sol.findSubString(S)<<endl;
}