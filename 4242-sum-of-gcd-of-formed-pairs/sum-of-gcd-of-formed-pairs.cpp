class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        vector<int>prefixGcd;
        for(int i=0;i<n;i++){
              if(nums[i]>maxi){
                maxi=nums[i];
              }
              prefixGcd.push_back(gcd(nums[i],maxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int s=0;
        int e=n-1;
        long long sum=0;
        while(s<e){
           sum+=gcd(prefixGcd[s],prefixGcd[e]);
           s++;
           e--;
        }
        return sum;
    }
};