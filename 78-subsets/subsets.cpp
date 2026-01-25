class Solution {
public:
    void subst(int i,vector<int> &curr,vector<int>& nums,vector<vector<int>>&res){
        if(i==nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        subst(i + 1, curr,nums, res);
        curr.pop_back();
        subst(i + 1, curr,nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;
        subst(0,curr,nums,res);
        return res;
    }
};