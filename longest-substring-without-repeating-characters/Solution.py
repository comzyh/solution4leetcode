class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_set = set()
        result = 0
        left = 0
        for c in s:
            while c in char_set:
                char_set.remove(s[left])
                left += 1
            char_set.add(c)
            result = max(result, len(char_set))
        return result
