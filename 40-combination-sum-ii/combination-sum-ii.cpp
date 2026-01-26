class Solution {
public:
    void solve(int i,int sum,vector<int>&curr,vector<vector<int>>&res,vector<int>&candidates,int target){
        if(sum==target){
            res.push_back(curr);
            return;
        }
        if(i==candidates.size()|| sum>target){
            return;
        }
        curr.push_back(candidates[i]);
        sum+=candidates[i];
        solve(i+1,sum,curr,res,candidates,target);
        sum-=candidates[i];
        curr.pop_back();
        int j = i + 1;
        while (j < candidates.size() && candidates[j] == candidates[i]) {
            j++;
        }
        solve(j,sum,curr,res,candidates,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        vector<vector<int>>res;
        solve(0,0,curr,res,candidates,target);
        return res;
    }
};