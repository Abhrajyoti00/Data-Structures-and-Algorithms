// CANNOT COMPARE str.length() to signed integer... Always use int(str.length()) to compare unsigned int values


#include<bits/stdc++.h>
using namespace std;
#define NoOfCharacters 256
class Solution{
    public:

    // O(n^2) Soln 
    // string findSubString(string str)
    // {
    //     set <char> hash_map;
    //     for(int i = 0; i <str.length(); i++){
    //         hash_map.insert(str[i]);
    //     }
    //     int min_size = 1000000;
    //     string ans;
    //     for(int i = 0; i < str.length(); i++){
    //         string sub_str = "";
            
    //         int count = 0;
    //         int visited_char[256] = {0};
    //         for(int j = i; j < str.length(); j++){
    //             if(visited_char[str[j]] == 0){
    //                 count+=1;
    //                 visited_char[str[j]] = 1;
    //             }
    //             sub_str+=str[j];
    //             if(count == hash_map.size()){
    //                 break;
    //             }
    //         }
    //         if(sub_str.length() < min_size && count == hash_map.size()){
    //             min_size = sub_str.length();
    //             cout<<"The substring "<<sub_str<<endl;
    //             ans = sub_str;
    //         }
    //     }
    //     return ans;
    // }

    // O(n) Solution 

    string findSubString(string str){
        // Suppose the string is S = "aabcbcdbca";

        set<char>distinct_string;
        for(int i = 0; i < str.length();i++){
            distinct_string.insert(str[i]);
        }
        map<char, int> HashMap;
        
        int i = -1;
        int j = -1;
        int len = str.length();
        string substring = "";
        while(true){
            bool f1 = false, f2 = false;
            // acquire  till HashMap.size() < distinct_string.size();
            while((i<int(str.length()-1)) && (HashMap.size() < distinct_string.size())){
                i++;
                char ch = str[i];
                
                HashMap[str[i]]+=1;

                // cout<<HashMap[str[i]]<<endl;
                f1 = true;
            }

            // Collect and Release
            while(j<i && HashMap.size() == int(distinct_string.size())){
                int plen = i - j;
                if(plen <= len){
                    len = plen;
                    // cout<<" i = "<<i<< " j = "<< j<< "str[j] = "<<str[j]<<endl;
                    substring = str.substr(j+1, len);
                }
                j++;
                char ch = str[j];
                if(HashMap[ch] == 1){
                    HashMap.erase(ch);
                }
                else{
                    HashMap[ch]-=1;
                }
                f2 = true;
            }
            if(f1 == false && f2 == false)
                break;
        }
        // cout<<len<<endl;
        return substring;
    }


};

int main(){
    string S;
    // cin>>S;
    S = "aabcbcdbca";
    S = "B";
    Solution sol;
    // sol.findSubString(S);
    cout<<sol.findSubString(S)<<endl;
}