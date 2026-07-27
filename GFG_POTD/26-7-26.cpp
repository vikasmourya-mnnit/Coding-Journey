//sort the level of binary tree
class Solution {
	public:
	vector<vector<int>> levelSort(vector<int>& arr) {
		// code here
		queue<pair<int, int>> pq;
		pq.push({arr[0], 0}); // val , idx
		int n = arr.size();
		vector<vector<int>>ans;
		while (!pq.empty()) {
			int sz = pq.size();
			vector<int>temp;
			while (sz--) {
				int x = pq.front().first;
				int idx = pq.front().second;
				pq.pop();
				
				temp.push_back(x);
				if (2*idx + 1<n) {
					pq.push({arr[2*idx + 1], 2*idx + 1});
				}
				if (2*idx + 2<n) {
					pq.push({arr[2*idx + 2], 2*idx + 2});
				}
				
			}
			sort(temp.begin(), temp.end());
			ans.push_back(temp);
		}
		return ans;
	}
};
