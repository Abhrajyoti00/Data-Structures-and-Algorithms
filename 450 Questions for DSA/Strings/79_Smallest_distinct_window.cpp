#include<bits/stdc++.h>
using namespace std;
#define NoOfCharacters 256
class Solution{
    public:
    string findSubString(string str)
    {
        set <char> hash_map;
        for(int i = 0; i <str.length(); i++){
            hash_map.insert(str[i]);
        }
        int min_size = 1000000;
        string ans;
        for(int i = 0; i < str.length(); i++){
            string sub_str = "";
            
            int count = 0;
            int visited_char[256] = {0};
            for(int j = i; j < str.length(); j++){
                if(visited_char[str[j]] == 0){
                    count+=1;
                    visited_char[str[j]] = 1;
                }
                sub_str+=str[j];
                if(count == hash_map.size()){
                    break;
                }
            }
            if(sub_str.length() < min_size && count == hash_map.size()){
                min_size = sub_str.length();
                // cout<<"The substring "<<sub_str<<endl;
                ans = sub_str;
            }
        }
        return ans;
    }
};

int main(){
    string S;
    cin>>S;
    Solution sol;
    // sol.findSubString(S);
    cout<<sol.findSubString(S)<<endl;
}