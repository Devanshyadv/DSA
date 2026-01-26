class Solution {
public:
    void solve(int i,vector<int>& candidates, int target,int sum,vector<int>&curr, vector<vector<int>>&res){
        if(sum==target){
                res.push_back(curr);
                return;
            }
        if(sum>target || i==candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        sum+=candidates[i];
        solve(i,candidates,target,sum,curr,res);
        sum-=candidates[i];
        curr.pop_back();
        solve(i+1,candidates,target,sum,curr,res); 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int>curr;
        vector<vector<int>>res;
        solve(0,candidates,target,sum,curr,res);
        return res;
    }
};