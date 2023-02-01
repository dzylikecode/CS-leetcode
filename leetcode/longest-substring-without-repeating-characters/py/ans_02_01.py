#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:    # 其实这包含在while循环里面, 可以不需要
            return len(s)
        curMax = 0
        while curMax < len(s):
            curCh = s[curMax]
            used = s[:curMax]
            if curCh in used:
                idx = used.index(curCh)
                return max(curMax, self.lengthOfLongestSubstring(s[idx+1:]))
            curMax += 1
        return curMax
# @lc code=end
