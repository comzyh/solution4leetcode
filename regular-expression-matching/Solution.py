from collections import defaultdict


class NfaNode:
    index_class = 0

    @classmethod
    def get_index(cls):
        cls.index_class += 1
        return cls.index_class - 1

    def __init__(self, final=False):
        self.index = self.get_index()

        self.next = defaultdict(lambda: [])
        self.final = final

    def __hash__(self):
        return self.index

    def __eq__(self, other):
        return other.index == self.index

    def add(self, s, final=False):
        if len(s) == 2:
            new_node = NfaNode(final=final)
            self.next[''].append(new_node)
            new_node.next[s[0]].append(new_node)
            return new_node
        else:
            new_node = NfaNode(final=final)
            self.next[s[0]].append(new_node)
            return new_node

    def expand(self):
        current = self
        res = set()
        while current is not None:
            res |= set([current])
            current = current.next[''][0] if len(current.next['']) > 0 else None
        return res


    def __repr__(self):
        return "id: {}, next: {}".format(self.index, {k: [n.index for n in self.next[k]] for k in self.next.keys()})


class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        root_node = NfaNode(final=p=='')
        current_node = root_node
        for i, c in enumerate(p):
            if c == '*':
                continue
            if i + 1 < len(p) and p[i + 1] == '*':
                current_node = current_node.add(p[i:i + 2], i + 2 == len(p))
            else:
                current_node = current_node.add(p[i], i + 1 == len(p))

        current = root_node.expand()
        for i, c in enumerate(s):
            next_set = set()
            for node in current:
                next_set |= set(node.next['.'])
                next_set |= set(node.next[c])
            # print(c, current)
            # print(current)
            current = set()
            for node in next_set:
                current |= node.expand()
        ans = False
        for node in current:
            ans = ans or node.final
        return ans


if __name__ == '__main__':
    obj = Solution()
    print(obj.isMatch('a', 'ab*'))
"""
"aa"
"a"
"aa"
"a*"
"ab"
".*"
"aab"
"c*a*b*"
"mississippi"
"mis*is*p*."
"mississippi"
"mis*is*ip*."
"""