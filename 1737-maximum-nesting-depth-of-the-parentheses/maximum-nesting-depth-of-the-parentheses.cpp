class Solution {
public:
    int maxDepth(string s) {
        int res=0;
        int curr=0;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(s[i]=='('){
                curr++;
                res=max(curr,res);   
            }
            if(s[i]==')'){
                curr--;
            }
        }
        return res;

    }
};