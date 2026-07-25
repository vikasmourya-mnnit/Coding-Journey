//LC 236
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        // jo phle mil gya woh bhi ans h
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;
        auto left = solve(root->left, p, q);
        auto right = solve(root->right, p, q);

        if (left == NULL) {
            return right;
        } else if (right == NULL)
            return left;
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};