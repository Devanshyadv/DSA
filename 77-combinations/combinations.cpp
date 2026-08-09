class Solution {
public:

    void solve(int start, int n, int k,
               vector<int>& path,
               vector<vector<int>>& ans) {

        // Combination complete
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++) {

            // Choose
            path.push_back(i);

            // Next number must be greater than i
            solve(i + 1, n, k, path, ans);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(1, n, k, path, ans);

        return ans;
    }
};