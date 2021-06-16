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
        // XOR VERSION 
    int *findTwoElement(int *arr, int n){
        int XOR1 = arr[0];
        for(int i = 1; i<n; i++){
            XOR1 ^= arr[i]; //XOR of all array elements
        }
        // XOR with 1 to N
        for(int i = 1; i<=n; i++){
            XOR1 ^= i;
        }
        int missing;
        int repeating;
        int right_most_set_bit = XOR1 & ~(XOR1 - 1); 
        // Suppose bin of XOR1 = 1100 (12), So bin of XOR1 - 1 = 1011 (11) (Here the rightmost bit is removed)
        // Now taking it's complement gives = ~(1011) = (0100) (4) ... Here the only set bit is at the posn., where the 
        // original no. (1100 : 12) had its rightmost set-bit. Consider this no. (0100) to be the mask of 
        // the original no. (1100) Now, if we perform and operation, we get :-
        // 1100 & 0100 ---> 0100 (Set at rightmost posn of 12). 

        //  My task is to filter out no.s from array

        for(int i = 0; i< n ; i++){
            if(arr[i] & right_most_set_bit)    // arr[i] belongs to first set 
                missing = arr[i];
            else    // arr[i] belongs to second set
                repeating = arr[i];  
        }
        
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