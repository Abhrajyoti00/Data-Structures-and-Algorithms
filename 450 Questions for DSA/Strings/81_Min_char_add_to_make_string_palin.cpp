#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string S){
    int l = S.length();
    for(int i=0, j = l-1; i<=j; i++, j--){
        if(S[i]!=S[j]) return false;
    }
    return true;
}

// O(n^2)  Soln

int main(){
    string S;
    cin>>S;
    int count = 0;
    string duplicate_string = S;
    string to_be_added_front = "";
    while(!isPalindrome(S)){
        to_be_added_front += S[S.length()-1];
        count++;
        S.erase(S.length()-1); // Erases all characters after position ‘pos’ 
    }
    cout<<"Palindrome string is = "<<to_be_added_front+duplicate_string<<endl;
    cout<<"No of characters added = "<<count<<endl;
}