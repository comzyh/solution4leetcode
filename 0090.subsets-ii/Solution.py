class Solution:

    def dfs(self, nums, position, current, result, take):
        if position == len(nums):
            result.append(current[:])
            return
        self.dfs(nums, position + 1, current, result, False)
        if position >= 1 and nums[position] == nums[position - 1] and not take:
            return
        self.dfs(nums, position + 1, current + [nums[position]], result, True)

    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        # nums.sort()
        self.dfs(nums, 0, [], result, False)
        return result
