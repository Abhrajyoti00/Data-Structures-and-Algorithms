#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        /*
        S = aabaa

        Output:  aba

        S = a a b a a 
            0 1 2 3 4
        
        i = 3
        my_vect = 'a', 'b', 'a' 
        */

       vector<char> my_vect;
       my_vect.push_back(S[0]);
       for(int i = 1; i<S.length();i++){
           if(S[i] != my_vect.back()){  //Accessing the last character in vector
               my_vect.push_back(S[i]);
           }
       }
       string ans_string = "";
       for(int i = 0; i< my_vect.size(); i++){
           ans_string = ans_string+my_vect[i];
       }
        return ans_string;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;

    cout<<sol.removeConsecutiveCharacter(s)<<endl;
}