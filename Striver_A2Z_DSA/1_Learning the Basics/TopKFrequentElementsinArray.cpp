//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Comparator function to sort pairs
    // according to second value
        static bool cmp(pair<int, int> a, pair<int, int> b)
        {
            if(a.second == b.second)
                return a.first>b.first;
            return a.second > b.second;
        }
 
        vector<int> topK(vector<int>& nums, int k) {
            map<int,int>m;
            for(int i = 0 ; i <nums.size();i++){
                m[nums[i]]++;
            }
            vector<pair<int,int>>vec(m.begin(), m.end());
            vector<int>ans;

            sort(vec.begin(), vec.end(), cmp);
            for(int i = 0; i< k; i++){
                ans.push_back(vec[i].first);
            }     
            return ans;
        }
    };
    

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends