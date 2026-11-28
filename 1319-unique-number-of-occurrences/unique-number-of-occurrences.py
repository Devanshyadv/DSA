class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        freq={}
        for i in arr:
            freq[i]=freq.get(i,0)+1
        
        val=[]
        for value in freq.values():
            val.append(value)
        lenl=len(val)
        lens=len(set(val))
        if lenl==lens:
            return True
        return False