from collections import Counter
class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        ans = 0
        for i in range(0, len(word)):
            for j in range(i, len(word)):
                substr = word[i:j + 1]
                c = Counter(substr)
                # print(substr, c)
                if c['a'] + c['e'] + c['i'] + c['o'] + c['u'] == j - i + 1 and c['a'] > 0 and  c['e'] > 0 and  c['i'] > 0 and  c['o'] > 0 and  c['u'] > 0:
                    ans += 1
        return ans
