/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    typedef long long Num;
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return write(read(l1) + read(l2));
    }
    Num read(ListNode *l)
    {
        Num res = 0;
        Num i = 0;
        while (l != nullptr)
        {
            res += l->val * pow(10, i);
            l = l->next;
            i++;
        }
        return res;
    }
    ListNode *write(Num num)
    {
        ListNode *res = new ListNode();
        ListNode *cur = res;
        while (num != 0)
        {
            cur->val = num % 10;
            num /= 10;
            if (num != 0)
            {
                cur->next = new ListNode();
                cur = cur->next;
            }
        }
        return res;
    }
};
// @lc code=end

/**
 * Line 28: Char 17: runtime error: 1e+30 is outside the range of representable values of type 'long long' (solution.cpp)
 * SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:37:17
 *
 * 容易 overflow, 数字太大了
 */