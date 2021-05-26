#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> :: iterator iter;
    
        sort(intervals.begin(), intervals.end());
        iter = unique(intervals.begin(), intervals.end());
        intervals.resize(distance(intervals.begin(), iter));
        int b;
        for(iter = intervals.begin()+ 1; iter < intervals.end(); iter++ ){
            if((*iter)[0] <= (*(iter - 1))[1]){
                b = max((*iter)[1], (*(iter - 1))[1]) ;
                (*(iter - 1))[1] = b;
                intervals.erase(iter);
                iter--;
            }

        }
        return intervals;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{8,10},{2,6},{15,18}};
    intervals = sol.merge(intervals);
    for(int i = 0; i< intervals.size();i++){
        for(int j = 0; j<intervals.size(); j++){
            cout<<intervals[i][j]<<" ";
        }
        cout<<endl;
    }
}

