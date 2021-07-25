#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int s) {
        int n;
        vector<int>ans_small;
        vector<vector<int>>ans_big;
        vector<int>::iterator big_it;
        vector<int>::iterator it;
        n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i<n;i++){
            mp[arr[i]]++;
        }
        for(int i = 0; i<= n-4; i++){
            int temp_sum = s;
            mp[arr[i]]-=1;
            temp_sum-=arr[i];
            ans_small.push_back(arr[i]);
            for(int j = i+1; j<=n-3;j++){
                mp[arr[j]]-=1;
                temp_sum-=arr[i];
                ans_small.push_back(arr[j]);
                for(int k = j+1; k<=n-2; k++){
                    mp[arr[k]]-=1;
                    temp_sum-=arr[i];
                    ans_small.push_back(arr[k]);
                    if(mp.find(temp_sum)!=mp.end() && mp[temp_sum]>0){
                        ans_small.push_back(temp_sum);
                        // ans_small.push_back(); //Substitute with $ later
                        ans_big.push_back(ans_small);
                    }
                    else{
                        mp[arr[k]]+=1;
                        it = ans_small.begin()+k;
                        ans_small.erase(it);
                    }
                }
                mp[arr[j]]+=1;
                it = ans_small.begin()+j;
                ans_small.erase(it);
            }
            mp[arr[i]]+=1;
            it = ans_small.begin()+i;
            ans_small.erase(it);
        }
        return ans_big;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int k;
    cin>>k;
    vector<int>my_vec;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        my_vec.push_back(arr[i]);
    }
    vector<vector<int>>ans;
    Solution s;
    ans = s.fourSum(my_vec, k);
    for(int i = 0; i<ans.size();i++)
    {
        for(int j = 0; j<ans[i].size();i++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"$";
    }

}