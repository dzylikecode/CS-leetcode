/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <unordered_map>
#include <map>
using namespace std;
using goMap = unordered_map<char, int>;
// using goMap = map<char, int>;
class Solution
{
private:
    int i = 0;
    int j = 0;

public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        while (j < s.length())
        {
            res = max(res, findCurrentMax(s));
        }
        return res;
    }

private:
    int findCurrentMax(const string &s)
    {
        goMap used;
        initUsed(s, used);
        while (j < s.length())
        {
            auto curCh = s[j];
            if (isIn(used, curCh))
            {
                int res = j - i;
                i = used[curCh] + 1;
                return res;
            }
            used[curCh] = j;
            j++;
        }
        return j - i;
    }

    bool isIn(const goMap &used, const char &curCh)
    {
        return used.find(curCh) != used.end();
    }

    void initUsed(const string &s, goMap &used)
    {
        for (auto k = i; k < j; k++)
        {
            used[s[k]] = k;
        }
    }
};
// @lc code=end
