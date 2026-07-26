// leetcode 1110. Delete Nodes And Return Forest
class Solution {
public:
    set<int> st;
    vector<TreeNode*> ans;
    TreeNode* solve(TreeNode* root) {
        if (root == NULL)
            return NULL;
        root->left = solve(root->left);
        root->right = solve(root->right);

        if (st.find(root->val) != st.end()) {
            if (root->left != NULL) {
                ans.push_back(root->left);
            }

            if (root->right != NULL) {
                ans.push_back(root->right);
            }

            return NULL;
        } else
            return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto val : to_delete) {
            st.insert(val);
        }
        solve(root);
        if (st.find(root->val) == st.end()) {
            ans.push_back(root);
        }

        return ans;
    }
};