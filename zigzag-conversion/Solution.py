class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        results = [[] for i in range(numRows)]
        for i, c in enumerate(s):
            p = i % (2 * numRows - 2) if numRows > 1 else 0
            if p >= numRows:
                p = 2 * numRows - 2 - p
            results[p].append(c)
        result = ''
        for line in results:
            result += ''.join(line)
        return result

if __name__ == '__main__':
    obj = Solution()
    obj.convert("PAYPALISHIRING", 3)