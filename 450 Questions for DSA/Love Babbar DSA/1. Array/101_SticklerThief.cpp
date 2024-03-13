#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int FindMaxSum(int arr[], int n)
    {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = max(dp[i-1],dp[i-1]+dp[i]); 
        }
         cout<<sum1<<" "<<sum2<<endl;
        return max(sum1, sum2);
    }
};

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Solution ob;
    cout << ob.FindMaxSum(a, n) << endl;
    return 0;
}