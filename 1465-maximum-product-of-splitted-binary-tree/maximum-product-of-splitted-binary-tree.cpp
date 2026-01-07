/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    long long sumTree(TreeNode* root) {
        if (!root) return 0;
        return root->val + sumTree(root->left) + sumTree(root->right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long currSum = root->val +
                            dfs(root->left) +
                            dfs(root->right);

        maxProd = max(maxProd, currSum * (totalSum - currSum));
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = sumTree(root);
        dfs(root);
        return maxProd % MOD;
    }
};
