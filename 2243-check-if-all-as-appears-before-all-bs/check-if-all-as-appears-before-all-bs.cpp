class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        bool p=false;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                 p=true;
            }
            if(p==true && s[i]=='a'){
                return false;
            }
        }
        return true;
    }
};