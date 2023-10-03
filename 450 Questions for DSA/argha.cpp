#include <bits/stdc++.h>
using namespace std;

class GFG {

public:
    // Check whether the string is palindrom or not.
    bool checkPalindrome(string& s, int start, int end)
    {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void PartitionDP(vector<vector<string>>& res, string& s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Initialize DP table
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(s, i, j))
                    dp[i][j] = true;
            }
        }

        vector<string> curr;
        generatePartitions(res, s, dp, 0, curr);
    }

    void generatePartitions(vector<vector<string>>& res, string& s, vector<vector<bool>>& dp, int start, vector<string>& curr)
    {
        int n = s.size();

        if (start == n) {
            res.push_back(curr);
            return;
        }

        for (int end = start; end < n; end++) {
            if (dp[start][end]) {
                string palin = s.substr(start, end - start + 1);
                curr.push_back(palin);
                generatePartitions(res, s, dp, end + 1, curr);
                curr.pop_back();
            }
        }
    }
};

int main()
{
    GFG ob;
    vector<vector<string>> res;
    // string s = "geeks";
    // string s = "pepper";
        // string s = "aaaa";
        string s = "madam";


    ob.PartitionDP(res, s);
    int c = 1;
    for (auto& v : res) {
        cout<<c++<<" ) ";
        for (auto& it : v) {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}
