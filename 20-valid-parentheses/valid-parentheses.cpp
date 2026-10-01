class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        if(n==1){
            return false;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty())return false;
                char ch=st.top();
                if(ch=='('&&s[i]!=')'){
                    return false;
                }
                if(ch=='{'&&s[i]!='}'){
                    return false;
                }
                if(ch=='['&&s[i]!=']'){
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};