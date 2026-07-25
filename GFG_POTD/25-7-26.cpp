
// Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.
class Solution {
public:
    int maximumSum(vector<vector<int>> &mat, int k) {
        int n = mat.size();

        
        vector<vector<int>> pre(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            pre[i][0] = mat[i][0];
            for (int j = 1; j < n; j++) {
                pre[i][j] = pre[i][j - 1] + mat[i][j];
            }
        }

        
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < n; i++) {
                pre[i][j] += pre[i - 1][j];
            }
        }

        int ans = INT_MIN;

        for (int i = 0; i + k - 1 < n; i++) {
            for (int j = 0; j + k - 1 < n; j++) {

                int r2 = i + k - 1;
                int c2 = j + k - 1;

                int sum = pre[r2][c2];

                if (i > 0)
                    sum -= pre[i - 1][c2];

                if (j > 0)
                    sum -= pre[r2][j - 1];

                if (i > 0 && j > 0)
                    sum += pre[i - 1][j - 1];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};