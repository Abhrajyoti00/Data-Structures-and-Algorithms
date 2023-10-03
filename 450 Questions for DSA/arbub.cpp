#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    int weight;
    TreeNode(int v, int w) : val(v), left(nullptr), right(nullptr), weight(w) {}
};

int minCost(TreeNode* root, int k) {
    vector<vector<int>> dp(root->weight + 1, vector<int>(k + 1, INT_MAX));

    // Base case: Choosing 0 nodes has a cost of 0.
    for (int i = 0; i <= root->weight; ++i) {
        dp[i][0] = 0;
    }

    // Recursive function to fill in dp table.
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) {
            return;
        }

        dfs(node->left);
        dfs(node->right);

        for (int i = 1; i <= root->weight; ++i) {
            for (int j = 1; j <= k; ++j) {
                // Include the current node.
                for (int leftNodes = 0; leftNodes <= i - 1; ++leftNodes) {
                    dp[i][j] = min(dp[i][j], node->weight + dp[leftNodes][j - 1] + dp[i - 1 - leftNodes][j - 1]);
                }

                // Exclude the current node.
                dp[i][j] = min(dp[i][j], dp[i][j]);
            }
        }
    };

    dfs(root);

    return dp[root->weight][k];
}

int main() {
    // Example usage:
    // Construct the binary tree with weights and root node.
    TreeNode* root = new TreeNode(1, 5);
    root->left = new TreeNode(2, 3);
    root->right = new TreeNode(3, 7);

    int k = 2; // Number of nodes to select.
    int result = minCost(root, k);
    cout << "Minimum cost of choosing " << k << " nodes: " << result << endl;

    // Don't forget to free memory for the tree nodes.
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
