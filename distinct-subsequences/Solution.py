class Solution:
    # @param {string} s
    # @param {string} t
    # @return {integer}

    def numDistinct(self, s, t):
        len_s = len(s)
        len_t = len(t)
        appear = {}
        for i in range(0, len_t):
            if t[i] not in appear:
                appear[t[i]] = []
            appear[t[i]].append(i)
        dp = [0 for i in range(len_t)]
        cur = 0
        pre = 1
        for i in range(0, len_s):
            if s[i] not in appear:
                continue
            cur, pre = pre, cur
            for pos in reversed(appear[s[i]]):
                if pos == 0:
                    dp[pos] += 1
                else:
                    dp[pos] += dp[pos - 1]
        return dp[len_t - 1]


if __name__ == '__main__':
    s = Solution()
    print s.numDistinct('cccc', 'cc')
