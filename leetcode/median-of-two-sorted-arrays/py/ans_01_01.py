#
# @lc app=leetcode id=4 lang=python3
#
# [4] Median of Two Sorted Arrays
#

# @lc code=start
import bisect


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        if m < n:
            nums1, nums2 = nums2, nums1
            m, n = n, m
        for num in nums2:
            bisect.insort(nums1, num)
        mid = (m + n) // 2
        if (m + n) % 2 == 0:
            return (nums1[mid] + nums1[mid - 1]) / 2
        else:
            return nums1[mid]

# @lc code=end
