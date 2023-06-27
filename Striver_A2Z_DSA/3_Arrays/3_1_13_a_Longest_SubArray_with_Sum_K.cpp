//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

// All postive integers solution 
//     int longestSubarrayWithSumK(vector<int> A, long long K) {
//         long long N = A.size();    
//         long long sum = 0, f = 0, l = 0, len = 0, max_len = 0;
//         while(l<N && f<=l){
//             len = 0;
//             sum+=A[l];
//             while(sum>K){
//                 sum-=A[f];
//                 f++;
//             }
//             if(sum == K){
//                 len = l-f+1;
//                 max_len = max(max_len, len);
//                 // sum-=A[f];
//                 // f+=1;
//             }
//             l++;
//         }
//         return max_len;     
// }

    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        long long sum = 0;
        int max_len = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<N;i++){
            sum+=A[i];
            if(sum == K){
                max_len = max(max_len, i+1);
            }
            long long rem = K-sum;
            if(mp.find(rem)!=mp.end()){
                max_len = max(max_len, i-mp[rem]);

            }
            else{
                mp[sum] = i;
            }
        }
        return max_len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends