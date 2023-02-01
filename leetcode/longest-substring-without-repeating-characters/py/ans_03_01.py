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
        nxtBegin = 0
        while len(curStr) != 0:
            curMax, curStr, nxtBegin = self.findCurrentMax(curStr, nxtBegin)
            allMax = max(allMax, curMax)
        return allMax

    def findCurrentMax(self, s: str, begin: int):
        curMax = begin
        while curMax < len(s):
            curCh = s[curMax]
            used = s[:curMax]
            if curCh in used:
                idx = used.index(curCh)
                return curMax, s[idx+1:], curMax - idx
            curMax += 1
        return curMax, "", curMax
# @lc code=end
