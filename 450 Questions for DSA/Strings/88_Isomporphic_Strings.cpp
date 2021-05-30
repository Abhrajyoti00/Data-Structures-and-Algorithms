#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int i;
        map<char,char>my_map;
        map<char,bool>occured;
        if(str1.length()!=str2.length())
            return false;
        
        for(i=0; i<str1.length(); i++){
                if(my_map.find(str1[i]) == my_map.end()) //Means str1[i] is not present in map
                {
                    if(occured.find(str2[i]) != occured.end())  //Means str2[i] has occured before
                        return false;
                    //Means str2[i] has not occured before, so now we can map the characters
                    occured[str2[i]] = true;
                    my_map[str1[i]] = str2[i];
                }
                
                else if(my_map[str1[i]]!=str2[i]) // Means str1[i] has occured before and now its time to check if the mapping is correct or not
                        return false;
        }
        return true;
    }
};

int main(){
    string s1,s2;
    cin>>s1>>s2;
    Solution sol;
    cout<<sol.areIsomorphic(s1,s2);
    return 0;
}