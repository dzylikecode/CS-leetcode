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

#include <vector>

class Solution
{
private:
    class Num
    {
    private:
        std::vector<int> digits;

    public:
        Num() = default;
        Num(const ListNode *l)
        {
            while (l != nullptr)
            {
                digits.push_back(l->val);
                l = l->next;
            }
        }
        int operator[](int i) const
        {
            return digits[i];
        }
        Num operator+(const Num &other) const
        {
            Num res;
            int carry = 0;
            for (int i = 0; i < std::max(digits.size(), other.digits.size()); i++)
            {
                int sum = carry;
                if (i < digits.size())
                    sum += digits[i];
                if (i < other.digits.size())
                    sum += other.digits[i];
                res.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            if (carry != 0)
                res.digits.push_back(carry);
            return res;
        }
        ListNode *to_list_node() const
        {
            ListNode *res = new ListNode();
            ListNode *cur = res;
            for (int i = 0; i < digits.size(); i++)
            {
                cur->val = digits[i];
                if (i != digits.size() - 1)
                {
                    cur->next = new ListNode();
                    cur = cur->next;
                }
            }
            return res;
        }
    };

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return write(read(l1) + read(l2));
    }
    Num read(ListNode *l)
    {
        return Num(l);
    }
    ListNode *write(const Num &num)
    {
        return num.to_list_node();
    }
};
// @lc code=end