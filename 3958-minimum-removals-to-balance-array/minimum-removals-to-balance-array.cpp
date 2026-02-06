class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left =0,maxLen=0;

        for(int r=0;r<n;r++){
            while(nums[r]>(long long)nums[left]*k){
            left++;
            }

            maxLen =max(maxLen,r-left+1);
        }
        
        return n - maxLen ;
    }
};