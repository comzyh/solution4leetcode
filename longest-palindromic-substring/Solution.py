class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        dp0 = [0] * len(s)
        dp1 = [0] * len(s)
        ans = ''
        for i in range(len(s)):
            for j in range(1, i + 2):
                if s[i] != s[i - j + 1]:
                    continue
                if j % 2 == 1:
                    if i - j // 2 + dp1[i - j // 2] == i:
                        dp1[i - j // 2] += 1
                    else:
                        continue
                else:
                    if i - j // 2 + 1 + dp0[i - j // 2 + 1] == i:
                        dp0[i - j // 2 + 1] += 1
                    else:
                        continue
                if j > len(ans):
                    ans = s[i - j + 1: i + 1]
        return ans