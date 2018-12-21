class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        if (digits == ""):
            return []
        ans = [""]

        for d in digits:
            nextans = []
            for item in ans:
                for c in mapping[d]:
                    nextans.append(item + c)
            ans = nextans
        return ans
