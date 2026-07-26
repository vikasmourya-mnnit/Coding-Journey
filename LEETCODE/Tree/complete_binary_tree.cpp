//WRONG BEACUSE OF RECURSION
//NOT A PROPETY OF SUBTREE
// class Solution {
// public:
//     bool solve(TreeNode* root){
//         if(root==NULL) return true;
//         if(root->left==NULL && root->right!=NULL) return false;
//         auto left = solve(root->left);
//         auto right = solve(root->right);

//         return left&& right;
//     }
//     bool isCompleteTree(TreeNode* root) {
//         return solve(root);
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int i, int total) {
        if (root == NULL)
            return true;
        if (i >= total)
            return false;
        return solve(root->left, 2 * i + 1, total) && 
               solve(root->right, 2 * i + 2, total);
    }
    int count(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + count(root->left) + count(root->right);
    }
    bool isCompleteTree(TreeNode* root) {
        int total = count(root);
        int i = 0;
        return solve(root, 0, total);
    }
};


