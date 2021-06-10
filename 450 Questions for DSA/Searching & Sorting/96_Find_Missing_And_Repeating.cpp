#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
    int ans[2] = {0}; //Data Hiding
public:
    // T.C = O(n), S.C =  O(1) ... But this modifies the array

    // int *findTwoElement(int *arr, int n)
    // {
    //     // code here
    //     // int ans[2] = {0};
    //     for (int i = 0; i < n; i++) {
    //         if (arr[abs(arr[i]) - 1] > 0)
    //             arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    //         else
    //             ans[0] = abs(arr[i]);
    //     }

    //     // cout << "and the missing element is ";
    //     for (int i = 0; i < n; i++) {
    //         if (arr[i] > 0)
    //             ans[1] = (i + 1); // We do this because since there was no element whose value was (i+1) ... 
    //                               // That's why the no at index (i) is still +ve.
    //     }
    //     return ans;
    // }


// Better but causes INteger overflow ... 
    // int *findTwoElement(int *arr, int n)
    // {
    //     ll missing = 0, repeating = 0;     // missing = x, repeating = y
    //     ll SUM = n * (n + 1) / 2;          // Sum of N nos
    //     ll SUM_SQ = SUM * (2 * n + 1) / 3; // Sum of Squared nos
    //     for (int i = 0; i < n; i++)
    //     {
    //         SUM -= (ll)arr[i];
    //         SUM_SQ -= (ll)arr[i] * (ll)arr[i];
    //     }
    //     missing = (SUM + SUM_SQ / SUM) / 2;
    //     repeating = missing - SUM;
    //     ans[0] = repeating;
    //     ans[1] = missing;
    //     return ans;
    // }

    int *findTwoElement(int *arr, int n){
        
    }

};

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution sol;
    auto ans = sol.findTwoElement(arr, n);
    cout << "Repeating = " << ans[0] << " Missing = " << ans[1] << endl;
    return 0;
}