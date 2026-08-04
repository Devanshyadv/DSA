class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>1){
                int j=1;
                while(nums[i-1]+j<nums[i]){
                   ans.push_back(nums[i-1]+j);
                   j++;
                }
            }
        

        }
        return ans;
    }
};