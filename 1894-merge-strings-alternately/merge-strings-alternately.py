class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        lw1=len(word1)
        lw2=len(word2)
        i=0
        j=0
        ans=''
        while i<lw1 and i<lw2:
            ans+=word1[i]
            ans+=word2[i]
            i=i+1
        
        if i<lw1:
            ans+=word1[i:lw1]
        
        if i<lw2:
            ans+=word2[i:lw2]

        return ans


        