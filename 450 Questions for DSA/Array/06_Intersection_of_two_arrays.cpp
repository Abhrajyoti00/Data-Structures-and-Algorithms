#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp_nums1;
        for(int i = 0; i<nums1.size(); i++){
            mp_nums1[nums1[i]]++;
        }
        unordered_set<int>set_nums2;
        for(int i = 0; i<nums2.size(); i++){
            set_nums2.insert(nums2[i]);
        }
        vector<int> ans;
        for(auto itr : set_nums2){
            if(mp_nums1[itr]>=1){
                ans.push_back(itr);
            }
        }
        return ans;
    }
};