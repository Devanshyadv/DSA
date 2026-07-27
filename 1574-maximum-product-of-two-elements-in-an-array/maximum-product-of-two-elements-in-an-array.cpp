class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int firstmax=INT_MIN;
        int secondmax=INT_MIN;
        for(int i=0;i<n;i++){
            if(firstmax<nums[i]){
                secondmax=firstmax;
                firstmax=nums[i];
            }
            else if(secondmax<nums[i]&& nums[i]<=firstmax){
                secondmax=nums[i];
            }
        }
        return (firstmax-1)*(secondmax-1);
    }
};