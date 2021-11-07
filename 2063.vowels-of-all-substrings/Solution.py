class Solution:
    def countVowels(self, word: str) -> int:
        ans = 0
        for i, c in enumerate(word):
            if c not in 'aeiou':
                continue
            ans += (i + 1) * (len(word) - i)
        return ans
