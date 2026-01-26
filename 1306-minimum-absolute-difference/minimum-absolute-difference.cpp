class Solution {
public:
   /* void solve(int i;vector<int>&curr,vector<int>&arr,vector<vector<int>>&res,int &d ){
        if(i==arr.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1,curr,arr,res,d);
        curr.pop_back(num[i]);
        solve(i+1,curr,arr,res,d);

    }*/
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
       // vector<int>curr;
        vector<vector<int>>res;
        int n=arr.size();
        int d=INT_MAX;
        //solve(0,curr,arr,res,d);
        //return res;
        for(int i=0;i+2-1<n;i++){
            if((arr[i+2-1]-arr[i])<d){
               d=arr[i+2-1]-arr[i];
            }
        }
        for(int i=0;i+2-1<n;i++){
           if((arr[i+2-1]-arr[i])==d){
            vector<int>curr;
            curr.push_back(arr[i]);
            curr.push_back(arr[i+2-1]);
            
            res.push_back(curr);
           }
        }
        return res;
    }
};