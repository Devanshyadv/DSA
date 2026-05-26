class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>small(26,0);
        vector<int>large(26,0);
        int count=0;
        for(int i=0;i<n;i++){
            if('a'<=word[i] && word[i]<='z'){
                small[word[i]-'a']++;
            }
            if('A'<=word[i] && word[i]<='Z'){
                large[word[i]-'A']++;
            }
        }
        for(int i=0;i<26;i++){
          if(small[i]>0&&large[i]>0){
            count++;
          }
        }
        return count;
    }
};