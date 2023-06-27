//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m)
    {
        int l = 0, r = 0, c = 0, flip = 0;
        for (int r = 0; r < n; r++)
        {
            if (arr[r] == 0)
                flip++;
            while (flip > m)
            {
                if (arr[l] == 0)
                    flip--;
                l++;
            }
            c = max(c, r - l + 1);
        }
        return c;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends