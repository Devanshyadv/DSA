class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nextgreater;
        stack<int>s;
        for(auto num : nums2){
            while(!s.empty() && num> s.top()){
                nextgreater[s.top()]=num;
                s.pop();
            }
            s.push(num);
        }
        while (!s.empty()) {
            nextgreater[s.top()] = -1;
            s.pop();
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextgreater[num]);
        }

        return ans;
    }
};