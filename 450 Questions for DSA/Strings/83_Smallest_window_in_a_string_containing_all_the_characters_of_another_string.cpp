#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.

    //////////////              TWO POINTER METHOD              ////////////
    // string smallestWindow (string s, string p)
    // {
        
    //     map<char,int>pattern_map;
    //     map<char,int>string_map;
    //     int match_count = 0 ; //To count the total matched counts
    //     string ans = "";
    //     int min_len = INT_MAX;
    //     for(int i = 0; i<p.length();i++){
    //         pattern_map[p[i]]++;
    //     }

    //     int popper = -1, inserter = -1;
    //     while(inserter<int(s.length())){
    //             //    cout<<"here\n";

    //         inserter++;
    //         string_map[s[inserter]]++;
    //         if((pattern_map.find(s[inserter])!= pattern_map.end()) && string_map[s[inserter]]<=pattern_map[s[inserter]]){
    //             match_count++;
    //         }
    //         while(match_count == p.length()){
    //             int cur_len = inserter-popper;
            
    //             if(min_len>cur_len){
    //                 ans = s.substr(popper+1, cur_len);
    //                 // cout<<"Substring ans  "<<ans<<endl;
    //                 min_len = cur_len;
    //             }
    //             popper++;
    //             string_map[s[popper]]--;

    //             if((pattern_map.find(s[popper])!= pattern_map.end()) && string_map[s[popper]]<pattern_map[s[popper]]){
    //                     match_count--;
    //             }
    //         }
    //     }
    //     if(ans.length()>0)
    //         return ans;
    //     else
    //         return "-1";
    // }

    ////////////////////////////               Best Solution - Using  Sliding window O(|S|)             ///////////////////////

    string smallestWindow (string s, string p){
        int count = 0, left = 0, right = 0, i , j, final_left = 0, final_right = 0;
        int min_length = INT_MAX;
        
        int pattern__map[256] = { 0 };
    
        for(i = 0; i<p.length(); i++){
            if(pattern__map[p[i]] == 0)
                count++;
            pattern__map[p[i]]++;
        }
    
        i = 0;
        j = 0;
        
        // s = totmtatapt, p = tat
        //           i
        //               j
        // pattern_map : t = 0, a = 0;
        //count = 1   left = 5 right = 9  min_len = 3

        while(j < s.length()){

            
                pattern__map[s[j]]--;
            
            if(pattern__map[s[j]] == 0){
                count--;
            }
            if(count == 0){ // Means we have received a possible substring
                // We store the current window by left = i, right = j
                
                while(count == 0){   //Means we can remove useless characters
                
                    if(min_length > (j - i + 1)){
                       
                        final_left = i;
                        min_length = min(min_length, j-i+1);
                    }
                    
                   
                        pattern__map[s[i]]++;
                    
                    if(pattern__map[s[i]]>0){
                        count++;
                    }
                    i++;
                }

            }
            j++;

        }
        
        if(min_length == INT_MAX)   return "-1";
        return s.substr(final_left, min_length);
        // return "";
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