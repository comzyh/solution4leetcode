class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        group = [(1000, 'M'), (500, 'D'), (100, 'C'), (50, 'L'), (10, 'X'), (5, 'V'), (1, 'I')]
        ret = []
        for i in range(7):
            while num >= group[i][0]:
                num -= group[i][0]
                ret.append(group[i][1])
            if i != 6 and i % 2 == 0 and num // group[i + 2][0] == 9:
                ret.append(group[i + 2][1])
                ret.append(group[i][1])
                num -= 9 * group[i + 2][0]
            if i % 2 == 1 and num // group[i + 1][0] == 4:
                ret.append(group[i + 1][1])
                ret.append(group[i][1])
                num -= 4 * group[i + 1][0]
        return ''.join(ret)
