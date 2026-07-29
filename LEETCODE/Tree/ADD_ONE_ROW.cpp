class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int curr) {
        if (root == NULL)
            return NULL;

        if (curr == depth - 1) {
            TreeNode* l1 = new TreeNode(val);
            TreeNode* l2 = new TreeNode(val);

            TreeNode* temp_l = root->left;
            TreeNode* temp_r = root->right;

            root->left = l1;
            root->right = l2;

            l1->left = temp_l;
            l2->right = temp_r;

            return root;   
        }

        solve(root->left, val, depth, curr + 1);
        solve(root->right, val, depth, curr + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return solve(root, val, depth, 1);
    }
};