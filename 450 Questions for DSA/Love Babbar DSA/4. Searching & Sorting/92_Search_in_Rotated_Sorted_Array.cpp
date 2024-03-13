// This is a 100% fastest soln out there in leetcode

#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int search(vector<int> &arr, int target)
//     {

//         int first = 1, n = arr.size();
//         int last = n - 1;
//         if (n == 0)
//             return -1;
//         if (n == 1)
//         {
//             if (arr[0] == target)
//                 return 0;
//             else
//                 return -1;
//         }
//         if (n == 2)
//         {
//             if (arr[0] == target)
//                 return 0;
//             if (arr[1] == target)
//                 return 1;
//             return -1;
//         }
//         int mid = 0;
//         int broken = -1;
//         while (first <= last)
//         {
//             // cout<<"first = "<<first<<" last = "<<last<< " mid = "<<mid<<endl;
//             mid = (first + last) / 2;
//             if ((mid == n - 1) || ((arr[mid] < arr[mid - 1])) && arr[mid] < arr[mid + 1])
//             {
//                 broken = mid;
//                 break;
//             }
//             else if (mid != n - 1 && (mid == first) && (first == last))
//             {
//                 broken = n - 1;
//                 break;
//             }
//             // else if(mid == n-2 && arr[mid]<=arr[n-1]){
//             //     broken = n-1;
//             //     break;
//             // }
//             else if (arr[mid] > arr[last])
//             {
//                 first = mid + 1;
//             }
//             else if (arr[mid] <= arr[last])
//             {
//                 last = mid;
//             }
//         }
//         // cout<<"Broken at "<<broken<<endl;

//         first = 0, last = broken - 1;
//         mid = 0;
//         int ans1 = -1, ans2 = -1;
//         while (first <= last)
//         {

//             mid = (first + last) / 2;
//             // cout<<"arr[mid] = "<<arr[mid]<<endl;
//             if (arr[mid] < target)
//                 first = mid + 1;
//             else if (arr[mid] > target)
//                 last = mid - 1;
//             else if (arr[mid] == target)
//             {
//                 ans1 = mid;
//                 break;
//             }
//         }
//         first = broken, last = n - 1;
//         mid = 0;
//         // cout<<"here\n";
//         // cout<<broken<<"here"<<endl;
//         while (first <= last)
//         {
//             mid = (first + last) / 2;
//             // cout<<"arr[mid] = "<<arr[mid]<<endl;

//             if (arr[mid] < target)
//                 first = mid + 1;
//             else if (arr[mid] > target)
//                 last = mid - 1;
//             else if (arr[mid] == target)
//             {
//                 ans2 = mid;
//                 break;
//             }
//         }
//         // cout<<"ans1 = "<<ans1<<" ans2 = "<<ans2<<endl;
//         if (ans1 == -1 && ans2 == -1)
//             return -1;
//         else if (ans1 != -1)
//             return ans1;
//         else if (ans2 != -1)
//             return ans2;
//         return -1;
//     }
// };


// Better Solution ... Still O(log N), but only using one binary search

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        /* Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4  */

        int n = arr.size();
        if (n == 0)
            return -1;
        int low = 0, high = n - 1;
        int first = arr[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int value = arr[mid]; // value is the mid element
            if (target == value)
                return mid;
            bool am_big = value >= first;      // let value = 6, so it's > 4
            bool target_big = target >= first; // let target = 5, so it's > 4
            if (am_big == target_big) // Means it lies on the left side of the pivot element (here it's 0 )
            {
                if (target > value) // let target = 7, and my value = 6, so need to search on the right side
                    low = mid + 1;
                else // let target = 5 and my value = 6, so search on the left side
                    high = mid - 1;
            }
            else{ //Means either value is big or the target is big
                if(am_big) // let value = 6 which is > 4, but target = 0 which is < 4
                    // So search in right half
                    low = mid+1;
                else // Means let value = 1 and target = 7 , so search in the left side
                    high = mid-1;               
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    int n, target;
    cin >> n;
    int arr[n];
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        nums.push_back(arr[i]);
    }
    cin >> target;
    cout << sol.search(nums, target);
    return 0;
}