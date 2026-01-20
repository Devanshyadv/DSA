class Solution {
public:
    bool validparen(string s){
        int count=0;
        for(char c:s) { 
            if(c=='('){
            count++;
         }
         else{
            count--;
         }
         if(count<0){
            return false;
         }
         
         }
         return count == 0;
    }
    void generateall(string curr,vector<string>&res,int n){
          if(curr.size()==2*n){
            if(validparen(curr)){
                res.push_back(curr);
            }
            return;
          }
          generateall(curr+"(",res,n);
          generateall(curr+")",res,n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;
        generateall("",res,n);
        return res;
    }
};