class Solution:

    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        for i in range(l - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                for p in range(l - 1, 0, -1):
                    if nums[p] > nums[i - 1]:
                        break
                nums[i - 1], nums[p] = nums[p], nums[i - 1]
                for j in range(p, l - 1):
                    if nums[j] < nums[j + 1]:
                        nums[j], nums[j + 1] = nums[j + 1], nums[j]
                        break
                break

        else:
            i = 0
        for j in range((l - i) // 2):
            nums[i + j], nums[l - j - 1] = nums[l - j - 1], nums[i + j]
