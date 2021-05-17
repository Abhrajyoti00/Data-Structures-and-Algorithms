#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        map<char,int>pattern_map;
        map<char,int>string_map;
        int map_count; //To count the total matched counts
        string ans = "";
        int min_len = INT_MAX;
        for(int i = 0; i<p.length();i++){
            pattern_map[p[i]]++;
        }
        int popper = -1, inserter = 0;
        while(inserter<s.length()){
            string_map[s[inserter]]++;
            if(string_map[s[inserter]]<=pattern_map[s[inserter]]){
                map_count++;
            }
            if(map_count == p.length()){
                int cur_len = inserter-popper;
                
                while(popper<inserter){
                    if(min_len>cur_len){
                        ans = s.substr(popper+1, cur_len);
                        cout<<"Substring ans"<<endl;
                        min_len = cur_len;
                    }
                    if(string_map[s[popper]]<pattern_map[s[popper]]){
                        map_count--;
                        break;
                    }
                    string_map[s[popper]]--;
                    popper++;
                }
            }
            inserter++;
        }

        return ans;
    }
};

int main(){
    string s,p;
    cin>>s>>p;
    Solution sol;
    cout<<sol.smallestWindow(s,p);
}