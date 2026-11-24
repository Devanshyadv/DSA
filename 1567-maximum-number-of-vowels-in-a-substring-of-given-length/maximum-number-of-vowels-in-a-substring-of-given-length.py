class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = 'aeiou'
        count = 0
        for i in range(k):
            if s[i] in vowels:
                count += 1
        maxi = count
        for i in range(k, len(s)):
            if s[i] in vowels:
                count += 1

            if s[i-k] in vowels:
                count -= 1

            maxi = max(maxi, count)

        return maxi

        
        