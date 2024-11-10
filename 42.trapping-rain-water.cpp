/*
 * @lc app=leetcode.cn id=42 lang=cpp
 * @lcpr version=30204
 *
 * [42] 接雨水
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> left_max(height.size());
        vector<int> right_max(height.size());
        int n = height.size();
        int ans = 0;

        left_max[0] = height[0];
        right_max[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++)
        {
            ans += max(0, min(left_max[i], right_max[i]) - height[i]);
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,0,2,1,0,1,3,2,1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,0,3,2,5]\n
// @lcpr case=end

 */
