class Solution {
public:
    int trap(vector<int>& height) {
          int n = height.size();
        vector<int>left(n);
        vector<int>right(n);
      
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            if(left[i-1]<height[i]){
                left[i]=height[i];
            }
            else{
                left[i]=left[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(right[i+1]<height[i]){
                right[i]=height[i];
            }
            else{
                 right[i]=right[i+1];
            }
        }
        int total=0;
        for(int i=0;i<n;i++){
            total+=min(left[i],right[i])-height[i];
        }
        return total;

    }
};