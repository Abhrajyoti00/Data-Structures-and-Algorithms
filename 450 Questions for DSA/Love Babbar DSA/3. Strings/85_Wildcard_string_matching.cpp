#include<bits/stdc++.h>
using namespace std;

            /*  Input: wild = ge?ks*
                pattern = geeksforgeeks
                Output: Yes

                Input:
                geek*s?
                geeks

                Its Correct output is:
                No

                Input:
                geeks**
                geeks

                Its Correct output is:
                Yes
            */

class Solution{
    public:
    bool solver(string wild, string pattern, int i, int j){
        if(i == wild.length() && j == pattern.length()){
            return true;
        }
        if(j == pattern.length()){
            for(int k = wild.length()-1; k>=i; k--){
                if(wild[k]!='*')
                    return false;
            }
        }
        if(i == wild.length())
            return false;

        if(wild[i] == pattern[j] || wild[i] == '?')
            return solver(wild,pattern, i+1, j+1);
        
        if(wild[i] == '*'){
            return ((solver(wild, pattern, i+1, j)) or (solver(wild, pattern, i, j+1))); // Either wild character doesnot replace any 
            //or it replaces many characters
        }

    }
    bool match(string wild, string pattern)
    {
            
            return solver( wild, pattern,0, 0);
    }
};


int main(){
    string wild, pattern;
    cin>>wild>>pattern;
    Solution sol;
    cout<<sol.match(wild, pattern);
    return 0;
}