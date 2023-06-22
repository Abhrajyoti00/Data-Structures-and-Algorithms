class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        // int b[n], c=0;
        // for(int i = 0 ; i<n; i++){
        //     if(nums[i]!=0)
        //         b[c++] = nums[i];
        // }
        // int k = c;
        // for(int i = c; i<n; i++)
        //     b[i] = 0;
        // for(int i = 0;i<n;i++)
        //     nums[i] = b[i];
        int i=0,j=0;
        while(j<n && i<=j){
            if(arr[j]!=0){
                arr[i] = arr[j];
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        for(;i<n&&i<j;i++)
            arr[i] = 0;
    }
};