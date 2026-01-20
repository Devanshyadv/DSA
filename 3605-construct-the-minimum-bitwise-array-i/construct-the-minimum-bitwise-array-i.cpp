class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(auto num:nums){
            int ans=-1;
            for(int i=1;i<=num;i++){
                if((i|i+1)==num){
                     ans=i;
                     break;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};