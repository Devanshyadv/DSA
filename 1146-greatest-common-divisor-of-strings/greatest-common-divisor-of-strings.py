class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        l1=len(str1)
        l2=len(str2)
        if str1+str2 != str2+str1:
            return ""
        k=gcd(l1,l2)
        return str1[:k]


        