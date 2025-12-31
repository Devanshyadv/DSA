class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int l=nums.size()-1;
        int ans=0;
        while(s<=l){
           int  m =(s+l)/2;
           if(nums[m]==target){
            return m;
           }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                l=m-1;
            }
            
        }
        return -1;
    }
};