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
        
        n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        set<vector<int>>power_set;
        for(int i = 0; i<= n-4; i++){
            for(int j = i+1; j<=n-3;j++){
                for(int k = j+1; k<=n-2; k++){
                    int sum_reqd = s - (arr[i]+arr[j]+arr[k]);
                    if(binary_search(arr.begin()+(k+1), arr.end(), sum_reqd))
                        {
                            ans_small.push_back(arr[i]);
                            ans_small.push_back(arr[j]);
                            ans_small.push_back(arr[k]);
                            ans_small.push_back(sum_reqd);
                        }
                        power_set.insert(ans_small);
                        ans_small.clear();
                }   
            }
        }
        for(auto iterator: power_set)
            ans_big.push_back(iterator);
        return ans_big;
    }
};

int main()
{

    /*7 23
    10 2 3 4 5 7 8 


    6 21
    1 4 45 6 10 12
    */
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
        for(int j = 0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"$";
    }

}