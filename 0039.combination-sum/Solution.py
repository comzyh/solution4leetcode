class Solution:

    def dfs(self, dp, position, current, result):
        if position == 0:
            result.append(current[:])
            return
        for i in dp[position]:
            self.dfs(dp, i, current + [position - i], result)

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        dp = [[] for i in range(target + 1)]
        for i in candidates:
            for j in range(i, target + 1):
                dp[j].append(j - i)
        result = []
        self.dfs(dp, target, [], result)
        return result
