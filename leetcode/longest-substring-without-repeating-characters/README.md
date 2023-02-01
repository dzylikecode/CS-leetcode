# longest substring without repeating characters

```py
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        return self.recursive(s)

    def recursive(self, s: str) -> int:
        if not s:
            return 0
        owned = set()
        curMax = 0
        while curMax < len(s):
            curCh = s[curMax]
            if curCh in owned:
                return max(curMax, self.recursive(s[curMax:]))
            owned.add(curCh)
            curMax += 1
        return curMax
```

以为是从 d 后面的 f 开始计算, 事实上应该从 d 后面的 v 开始计算

```txt
s =
"dvdf"
Output
2
Expected
3
```

---

在上面的方法上面进一步改进

[](py/ans_02_02.py ":include :type=code py")

`findCurrentMax` 的 `curMax` 可以优化

变成双指针窗口思想

https://leetcode.com/problems/longest-substring-without-repeating-characters/solutions/2133524/java-c-a-reall-detailed-explanation/

---

我没想到我用 c++ 的实现比 python 还慢
