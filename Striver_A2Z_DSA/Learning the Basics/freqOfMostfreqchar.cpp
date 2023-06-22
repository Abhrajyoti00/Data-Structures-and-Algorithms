//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
        //  long long maxFrequency(vector< long long>& nums,  long long k) {
        //     sort(nums.begin(), nums.end());
        //      long long i =0, n = nums.size();
        //      long long j = n-1, max_num = 1;  long long max_freq = 1;
        //     while(j>0){
        //         while(i!=j && k!=0){
        //             if(nums[j]-nums[i]>k)
        //                 i++;
        //             else{
        //                 k = k - (nums[j]-nums[i]);
        //                 i++;
        //                 max_num++;
        //             }
        //             max_freq = max(max_num, max_freq);
        //         }
        //         max_num = 1;
        //         i = 0;
        //         j--;
        //     }
        //     return max_freq;
        // }

        long long maxFrequency(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        long long l = 0, r = 0, tot_till_r = 0, max_ws = 1;
        while (r < nums.size()) {
            
            tot_till_r += nums[r];
            while (nums[r] * (r - l + 1) > tot_till_r + k) {
                tot_till_r -= nums[l];
                l++;
            }
            max_ws = max(max_ws, r - l + 1);
            r++;
        }
        return max_ws;
    }
    };
    

//{ Driver Code Starts.
 long long main() {
     long long tc;
    cin >> tc;
    while (tc--) {
         long long n;
        cin >> n;
        vector< long long> nums(n);
        for (auto &i : nums) cin >> i;
         long long k;
        cin >> k;
        Solution obj;
         long long ans = obj.maxFrequency(nums, k);
        cout << ans << " ";
        cout << "\n";
    }
    return 0;
}