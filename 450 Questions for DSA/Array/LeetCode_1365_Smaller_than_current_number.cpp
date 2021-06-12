// Runtime: 4 ms, faster than 95.27% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
// Memory Usage: 10.6 MB, less than 13.66% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int, greater <int> > mymap;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mymap[nums[i]]++;
        }
        int ans = 0;
        auto largest = mymap.begin();
        auto it = mymap.begin();
        it++;
        for(; it!=mymap.end(); it++){
            ans+= it->second;            
        }
        // for(auto it: mymap)
            // cout<<it.first<<endl;
        // cout<<"ans = "<<ans<<endl;
        mymap[largest->first] = ans; // To store the value of largest no to be equal to total no of small nos
        // cout<<"Largest = "<<largest->first;

        it = mymap.begin();
        it++;
        for(; it!=mymap.end(); it++){
            ans = ans-(it->second);
            mymap[it->first] = ans;
        }
        vector<int>ans_vector;
        for(int i = 0 ; i<n; i++){
            ans_vector.push_back(mymap[nums[i]]);
        }
        return ans_vector;
    }
    
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int>vec;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        vec.push_back(arr[i]);
    }
    Solution sol;
    auto ans = sol.smallerNumbersThanCurrent(vec);
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    return 0;
}