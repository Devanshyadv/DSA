class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        left = 0
        countzero = 0
        maxlen = 0

        for right in range(len(nums)):

            if nums[right] == 0:
                countzero += 1

            while countzero > k:
                if nums[left] == 0:
                    countzero -= 1

                left += 1

            maxlen = max(maxlen, right - left + 1)

        return maxlen
        