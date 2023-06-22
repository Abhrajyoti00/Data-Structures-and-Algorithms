class Solution {
public:
    bool check(vector<int>& arr) {
        int c1 = 0, c2 = 0;
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]<arr[i-1]){
                c1++;
            }
        }
        if((c1 == 0) || (c1 ==1 && arr[arr.size()-1]<=arr[0]))
            return true;
        else
            return false;
    }
};