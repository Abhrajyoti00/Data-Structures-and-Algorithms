#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.

    //////////////              TWO POINTER METHOD              ////////////
    string smallestWindow (string s, string p)
    {
        
        map<char,int>pattern_map;
        map<char,int>string_map;
        int match_count = 0 ; //To count the total matched counts
        string ans = "";
        int min_len = INT_MAX;
        for(int i = 0; i<p.length();i++){
            pattern_map[p[i]]++;
        }

        int popper = -1, inserter = -1;
        while(inserter<int(s.length())){
                //    cout<<"here\n";

            inserter++;
            string_map[s[inserter]]++;
            if((pattern_map.find(s[inserter])!= pattern_map.end()) && string_map[s[inserter]]<=pattern_map[s[inserter]]){
                match_count++;
            }
            while(match_count == p.length()){
                int cur_len = inserter-popper;
            
                if(min_len>cur_len){
                    ans = s.substr(popper+1, cur_len);
                    // cout<<"Substring ans  "<<ans<<endl;
                    min_len = cur_len;
                }
                popper++;
                string_map[s[popper]]--;

                if((pattern_map.find(s[popper])!= pattern_map.end()) && string_map[s[popper]]<pattern_map[s[popper]]){
                        match_count--;
                }
            }
        }
        if(ans.length()>0)
            return ans;
        else
            return "-1";
    }
};

int main(){
    string s,p;
    cin>>s>>p;
    Solution sol;
    cout<<sol.smallestWindow(s,p);
}
//s = "dbaecbbabdcaafbddcabgba"
//p = "abbcdc"
//Output = "cbbabdc"