class Solution {
public:
    map<int, vector<int>> mp;
    int solve(Node* root, map<int, vector<int>>& mp){
        if(!root) return 0;
        
        int left = solve(root->left, mp);
        int right = solve(root->right, mp);
        
        int height = max(left, right) + 1;
        mp[height].push_back(root->val);
        
        return height;
    }
    vector<vector<int>>find(Node* root){
        
        vector<vector<int>> ans;
        solve(root,mp);
        for(auto& pair : mp) {
            ans.push_back(pair.second);
        }
        int m = ans.size();
        for(int i =0;i<m;i++){
            for(int j = 0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
        }
    }

};