class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26]={0};
        int left=0;
        int ans=0;
        for(int rigth=0;rigth<s.size();rigth++){
            freq[s[rigth]-'a']++;
            while(freq[s[rigth]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            ans=max(ans,rigth-left+1);
        }
        return ans;
    }
};