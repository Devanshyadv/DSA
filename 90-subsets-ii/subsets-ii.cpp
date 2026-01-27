class Solution {
public:
    void solve(int i, vector<int>& curr,
               vector<int>& nums, vector<vector<int>>& res) {

        res.push_back(curr);

        for (int st = i; st < nums.size(); st++) {
            if (st > i && nums[st] == nums[st - 1]) continue;

            curr.push_back(nums[st]);
            solve(st + 1, curr, nums, res);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(0, curr, nums, res);
        return res;
    }
};
