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

// int main(){
//     string S;
//     cin>>S;
//     int count = 0;
//     string duplicate_string = S;
//     string to_be_added_front = "";
//     while(!isPalindrome(S)){
//         to_be_added_front += S[S.length()-1];
//         count++;
//         S.erase(S.length()-1); // Erases all characters after position ‘pos’ 
//     }
//     cout<<"Palindrome string is = "<<to_be_added_front+duplicate_string<<endl;
//     cout<<"No of characters added = "<<count<<endl;
// }

//O(n) Solution 

int lps_count(string modified_string){
    // modified_string = "AACECAAAA$AAAACECAA"

    int lps_array[modified_string.length()];
    lps_array[0] = 0;
    int i = 1;
    int j = 0;
    while(i < modified_string.length()){
        if (modified_string[i] == modified_string[j]){
            j++;
            lps_array[i] = j;
            i++;
        }
        else{
            if(j!=0){
                j = lps_array[j-1];
            }
            else{
                lps_array[i] = 0;
                i++;
            }
        }
    }
    int last_entry = lps_array[modified_string.length()-1];
    return last_entry;
}


int main(){
    string S;
    cin>>S;
    string duplicate_string = S ;
    reverse(duplicate_string.begin(), duplicate_string.end());
    string modified_string = S + "$" +  duplicate_string; // The modified_string is the original string + a special character + the reverse
    int original_length = S.length();
    int count = lps_count(modified_string);
    int ans = original_length - count;
    cout<<ans<<"\n";
    return 0;
}