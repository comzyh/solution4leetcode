INT_MAX = 2 ** 31 - 1


def get_num(nums, index):
    if index < 0:
        return -INT_MAX
    elif index >= len(nums):
        return INT_MAX
    return nums[index]


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        left_ans_only = False
        if (len(nums1) + len(nums2)) % 2 == 1:
            left_ans_only = True
            if len(nums1) % 2 == 1:
                nums1.append(INT_MAX)
            else:
                nums2.append(INT_MAX)
        b = 0
        e = len(nums1)
        target = (len(nums1) + len(nums2)) // 2
        while b < e:
            k1 = (b + e) // 2
            k2 = target - k1
            print(k1, k2)
            if get_num(nums1, k1 - 1) > get_num(nums2, k2):  # k1 -
                e = k1 - 1
                continue
            if get_num(nums2, k2 - 1) > get_num(nums1, k1):
                b = k1 + 1
                continue
            break
        l = max(get_num(nums1, k1 - 1), get_num(nums2, k2 - 1))
        r = min(get_num(nums1, k1), get_num(nums2, k2))
        if left_ans_only:
            return l
        else:
            return (l + r) / 2

if __name__ == '__main__':
    obj = Solution()
    print(obj.findMedianSortedArrays([1,3], [2]))