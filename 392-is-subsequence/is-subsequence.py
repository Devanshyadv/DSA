class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        fs=len(s)
        ss=len(t)
        i=0
        j=0
        if fs==0:
            return True
        while j<ss:
            if s[i]==t[j]:
                i+=1
            if(i>=fs):
                return True
            j+=1

        return False
        