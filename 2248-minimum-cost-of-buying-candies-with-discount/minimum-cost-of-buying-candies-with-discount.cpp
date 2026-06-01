class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        sort(cost.begin(),cost.end());
        int i=n-1;
        int ans=0;
        while(i>=0){
            if(i==0){
                ans+=cost[0];
            }
            else{ans+=cost[i]+cost[i-1];
            }
            i=i-3;


        }
        return ans;
    }
};