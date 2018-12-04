class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        group ={
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
        }
        s = [group[c] for c in s]
        ans = 0
        for i in range(len(s)):
            if i < len(s) - 1 and s[i] < s[i + 1]:
                ans -= s[i]
            else:
                ans += s[i]
        return ans
