class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find sequential prefix sum
        int prefixSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixSum += nums[i];
            } else {
                break;
            }
        }

        // Put all numbers into a set
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest integer >= prefixSum
        // which is not present
        int ans = prefixSum;

        while (st.count(ans)) {
            ans++;
        }

        return ans;
    }
};