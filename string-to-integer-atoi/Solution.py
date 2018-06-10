class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        str = str.strip()
        for i, c in enumerate(str):
            if not ((c >= '0' and c <= '9') or (i == 0 and c in '-+')):
                str = str[:i]
                break
        if len(str.strip('-+')) == 0 :
            return 0
        i = int(str)
        if i > 2 ** 31 - 1:
            i = 2 ** 31 - 1
        if i < - 2 ** 31:
            i = - 2 ** 31
        return i