class Solution:
    def longestSubarray(self, nums: list[int]) -> int:
        n=len(nums)
        left=0
        maxlen=0
        countzero=0
        for right in range(n):
            if nums[right]==0:
                countzero+=1

            while countzero>1:
                if nums[left]==0:
                    countzero-=1
                left+=1
            maxlen=max(maxlen,right-left+1)
        return maxlen-1
            
        

        