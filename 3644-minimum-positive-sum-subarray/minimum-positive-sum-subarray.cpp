class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int minisum=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int len=j-i+1;
                if(len>=l&& len<=r){
                    if(sum>0){
                        minisum=min(minisum,sum);
                 }
                }
                if(len>r)break;
            }
        }
        return minisum==INT_MAX? -1:minisum;
    }
};