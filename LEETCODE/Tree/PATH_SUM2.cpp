
class Solution {
public:
    vector<vector<int>> ans;
    bool solve(TreeNode* root, int targetSum, vector<int> &temp) {

        if (root == NULL)
            return false;

        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (targetSum == root->val) {
                ans.push_back(temp);
                temp.pop_back();
                return true;
            }
             temp.pop_back();
            return false;
        }

        bool l = solve(root->left, targetSum - root->val, temp);
        bool r = solve(root->right, targetSum - root->val, temp);
        temp.pop_back();
        return l || r;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;

        solve(root, targetSum, temp);

        return ans;
    }
};