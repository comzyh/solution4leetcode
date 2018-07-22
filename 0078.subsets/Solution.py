class Solution:

    def dfs(self, nums, position, current, result):
        if position == len(nums):
            result.append(current[:])
            return
        self.dfs(nums, position + 1, current, result)
        self.dfs(nums, position + 1, current + [nums[position]], result)

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        # nums.sort()
        self.dfs(nums, 0, [], result)
        return result
