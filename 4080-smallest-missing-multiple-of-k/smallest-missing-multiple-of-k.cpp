class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        for(auto x:nums){
            s.insert(x);
        }
        int ans=0;
        int i=1;
        while(i>0){
            if(!s.count(k*i)){
                ans=k*i;
                break;
            }
            i++;
        }
        return ans;
    }
};