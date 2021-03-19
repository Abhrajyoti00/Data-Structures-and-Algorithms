#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

//O(n^3) Solution:- 
// bool isPalindrome(string str){
//     int n = str.length();
//     string reversed_string = "";
//     for(int i=n-1; i>=0; i--){
//         reversed_string = reversed_string + str[i];
//     }
//     if(reversed_string.compare(str) == 0)
//         return true;
//     return false;

// }

// int32_t main(){
// fast


// // ||| Author: Abhrajyoti Kundu |||
// // ||| DS-ALGO Lover |||


// int t=1;
// cin>>t;
// while(t--){
//       string str;
//       cin>>str;
//       int n = str.length();
//       int len = 0, max_len = 0, max_i = 0, max_j = 0;
//       for(int i = 0; i < n; i++){
          
//           for (int j = n-1; j > i; j--){
//               string smaller_string = "";
//               for(int k = i; k <= j; k++){
//                   smaller_string+=str[k];
//               }
//             //   cout<<"smaller string = "<<smaller_string<<endl;
//               if(isPalindrome(smaller_string)){
//                   len = (j-i)+1;
//                   if(len>max_len){
//                       max_len = max(max_len,len);
//                       max_i = i;
//                       max_j = j;
//                   }
                  
//                   break;
//               }
//           }
//       }
//       string smaller_string = "";
//         for(int k = max_i; k <= max_j; k++){
//             smaller_string+=str[k];
//         }
//         // cout<<"Max length = "<<max_len<<endl;
//         // cout<<"Max_i = "<<max_i<<endl;
//         // cout<<"Max_j = "<<max_j<<endl;
//         cout<<smaller_string<<endl;

// }


// TC O(n^2), SC O(1) Solution

int expandFromMid(string str, int left, int right){
    while((left>=0 && right<str.length()) &&  (str[left] == str[right])){
        left--;
        right++;
    }
    return right-left-1;
}

string longestPalindrome(string str) {
        if(str == "" || str.length()<1)
                return "";
        int n = str.length();
        int len = 0;
        int start = 0, end = 0;
        for(int i = 0; i <n; i++){
            
            int len1 = expandFromMid(str, i, i);  //"racecar"
            int len2 = expandFromMid(str, i, i+1); //"caabbaade"
            len = max(len1, len2);
            if(len>end-start){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return str.substr(start, end-start+1);
                  
    }

int32_t main(){
fast


// ||| Author: Abhrajyoti Kundu |||
// ||| DS-ALGO Lover |||


int t=1;
cin>>t;
while(t--){
      string str;
      cin>>str;
    // str = "aaaabbaa";
    // str = "pracecarq";
      int n = str.length();
      int len = 0, max_len = 0, max_i = 0, max_j = 0;
      cout<<longestPalindrome(str)<<endl;
}
}
