class Solution {
public:
    bool check(vector<int>&arr){
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(nums.size()>1 && check(nums)== false){
           int n = nums.size();
            int minsum = nums[0] + nums[1];
            int idx = 0;
            for(int i=1;i<n-1;i++){
                 int s=nums[i]+nums[i+1];
                 if(s<minsum){
                    minsum=s;
                    idx=i;
                 }     
            }
            vector<int> next;
            for(int i = 0; i < idx; i++) next.push_back(nums[i]);
            next.push_back(minsum);
            for(int i = idx + 2; i < n; i++) next.push_back(nums[i]);
            nums=next;
            ans++;

        }
        return ans;
    }
};