#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic1(string str1, string str2)
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

    /* Another Approach:

    In this approach, we will count the number of occurrences of a particular character in both the string using two arrays,
    while we will compare the two arrays if at any moment with the loop the count of the current character in both strings
    becomes different we return false, else after the loop ends we return true.
    Follow the code given below you will understand everything.
    Below is the implementation of the above idea : */

    bool areIsomorphic2(string str1, string str2)
    {
        int MAX = 256;
        int count_of_str1[MAX] = {0};
        int count_of_str2[MAX] = {0};
        int n,m;
        n = str1.length();
        m = str2.length();
        if(n!=m)
            return false;
        for(int i = 0; i<n; i++){
            count_of_str1[str1[i]]++;
            count_of_str2[str2[i]]++;

            if(count_of_str1[str1[i]]!=count_of_str2[str2[i]])
                return false;
        }
        return true;
    }



};

int main(){
    string s1,s2;
    cin>>s1>>s2;
    Solution sol;
    cout<<sol.areIsomorphic1(s1,s2);
    cout<<sol.areIsomorphic2(s1,s2);
    return 0;
}