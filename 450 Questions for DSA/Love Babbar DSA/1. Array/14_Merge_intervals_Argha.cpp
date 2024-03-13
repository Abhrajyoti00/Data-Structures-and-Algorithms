#include<bits/stdc++.h>
using namespace std;
// Argharupa's Solution in Cpp TC : O(n), SC: O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> :: iterator iter;
    
    sort(intervals.begin(), intervals.end()); //sorting the vector
    iter = unique(intervals.begin(), intervals.end()); //removing the duplicate eleemnts
    intervals.resize(distance(intervals.begin(), iter)); //resizing the array
    int index = 0;
    for (auto interval : intervals)
    {

        if (interval[0] <= intervals[index][1])
        {

            intervals[index][1] = max(interval[1], intervals[index][1]);
        }
        else
        {
            index++;
            intervals[index] = interval;
        }
    }
    
    intervals.resize(index + 1); 
    return intervals;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{8,10},{2,6},{15,18}};
    intervals = sol.merge(intervals);
    for(int i = 0; i< intervals.size();i++){
        for(int j = 0; j<intervals[i].size(); j++){
            cout<<intervals[i][j]<<",";
        }
        cout<<" ";
    }
}

