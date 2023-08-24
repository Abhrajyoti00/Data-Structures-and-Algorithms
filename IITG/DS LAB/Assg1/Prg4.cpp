// Given an integer array nums, return true
// if you can partition the array into two subsets such
// that the sum of the elements in both subsets is equal or false otherwise.
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

#include <bits/stdc++.h>
using namespace std;

bool Subset_sum(vector<int> &nums, int n, int to_find)
{
    if (to_find == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }

    if (nums[n - 1] > to_find)
    {
        return Subset_sum(nums, n - 1, to_find);
    }

    return Subset_sum(nums, n - 1, to_find - nums[n - 1]) || Subset_sum(nums, n - 1, to_find);
}

bool canPartition(vector<int> &nums)
{
    int TotalSum = 0;
    for (int i = 0; i < nums.size(); i++)
        TotalSum += nums[i];

    if (TotalSum % 2 != 0)
    {
        return false;
    }

    int to_find = TotalSum / 2;
    int n = nums.size();

    return Subset_sum(nums, n, to_find);
}

int main()
{
    int n;
    cout << "Enter the number of elements present in the array nums :- \n";
    cin >> n;
    int nums[n];
    cout << "Enter the elements :- \n";
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        v.push_back(nums[i]);
    }
    if (canPartition(v) == 1)
        cout << "True";
    else
        cout << "False";
}