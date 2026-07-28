class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        map<char,int> counts;
        for(char c:s){
            counts[c]++;
        }
        string result="";
        char single=' ';
        for(auto it:counts){
            if(it.second==1){
             single=it.first;
            }
            else if(it.second%2==1){
                int i=it.second/2;
                while(i>0){
                    result.push_back(it.first);
                    i--;
                    }
                single=it.first;
            }
            if(it.second%2==0){
                int j=it.second/2;
                while(j>0){
                    result.push_back(it.first);
                    j--;
                    }
            }
        }
        string temp=result;
        reverse(temp.begin(),temp.end());
        string ans;
        if(single!=' '){
            ans=result+single+temp;
        }
        else{
            ans=result+temp;
        }
        return ans;
    }
};