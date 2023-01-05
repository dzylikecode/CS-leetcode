# Roman to Integer

https://leetcode.com/problems/roman-to-integer/description/

## core

If the current one is smaller than the next one, negate it. Then sum all.

```txt
[1, 4] -> [-1, 4]
```

## js

- 01-3

想用迭代器, 把拿出前两个变量的过程用迭代器分离出来
