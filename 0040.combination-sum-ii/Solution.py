class Solution:

    def dfs(self, dp, position, layer, current, result):
        if position == 0:
            result.append(current[:])
            return
        last = -1
        for i, l in dp[position][layer - 1::-1]:
            if i != last:  # dedupe
                self.dfs(dp, i, l, (position - i,) + current, result)
            last = i

    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        dp = [[] for i in range(target + 1)]  # Where am I come from ? Using set here
        for i in candidates:
            for j in range(target, i - 1, -1):  # Here is different to 0040.combination-sum, loop backward
                if j - i == 0 or len(dp[j - i]) > 0:  # previous state is reachable
                    dp[j].append((j - i, len(dp[j - i])))  # (previous state, available state number now)

        result = []
        self.dfs(dp, target, len(dp[target]), (), result)
        return result
