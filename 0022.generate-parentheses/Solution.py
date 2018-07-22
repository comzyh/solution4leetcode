class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        n *= 2
        def dfs(pos, current, left):
            if pos == n:
                result.append(current)
            if left > 0:
                dfs(pos + 1, current + ")", left -1)
            if pos + left < n:
                dfs(pos + 1, current + "(", left + 1)
        dfs(0, "", 0)
        return result
