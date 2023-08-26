/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto totalSize = nums1.size() + nums2.size();
        vector<int> nums(totalSize);
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
        auto mid = totalSize / 2;
        return totalSize % 2 == 0 ? (nums[mid - 1] + nums[mid]) / 2.0 : nums[mid];
    }
};
// @lc code=end
