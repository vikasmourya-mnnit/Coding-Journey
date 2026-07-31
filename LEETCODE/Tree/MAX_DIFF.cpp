/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxi = 0;

    int solve(TreeNode* root, int mini, int maxiVal) {
        if (root == NULL)
            return 0;

        maxi = max({maxi,
                    abs(root->val - mini),
                    abs(root->val - maxiVal)});

        mini = min(mini, root->val);
        maxiVal = max(maxiVal, root->val);

        solve(root->left, mini, maxiVal);
        solve(root->right, mini, maxiVal);

        return maxi;
    }

    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};