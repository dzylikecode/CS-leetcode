#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        allMax = 0
        curStr = s
        while len(curStr) != 0:
            curMax, curStr = self.findCurrentMax(curStr)
            allMax = max(allMax, curMax)
        return allMax

    def findCurrentMax(self, s: str) -> tuple[int, str]:
        curMax = 0
        while curMax < len(s):
            curCh = s[curMax]
            used = s[:curMax]
            if curCh in used:
                idx = used.index(curCh)
                return curMax, s[idx+1:]
            curMax += 1
        return curMax, ""
# @lc code=end
