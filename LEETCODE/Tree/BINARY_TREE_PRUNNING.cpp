
class Solution {
public:
    // left, right me sbhi zero walo ko hatane ke baad ka address

    TreeNode* solve(TreeNode* root) {
        if (root == NULL)
            return NULL;
        auto l = solve(root->left);
        auto r = solve(root->right);
        root->left = l;
        root->right = r;
        if (root->val == 0 && root->left == NULL && root->right == NULL)
            return NULL;

        return root;
    }
    TreeNode* pruneTree(TreeNode* root) { return solve(root); }
};