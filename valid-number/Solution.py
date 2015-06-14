class Solution:
    # @param {string} s
    # @return {boolean}

    def isNumber(self, s):
        import re
        found = re.match(
            r'^\s*((\+|-)?((\d+)|(\d+\.)|(\.\d+)|(\d+\.\d+))(e(\+|-)?\d+)?)\s*$', s)
        return found is not None
