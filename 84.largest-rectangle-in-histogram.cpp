// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=84 lang=cpp
 * @lcpr version=30204
 *
 * [84] 柱状图中最大的矩形
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
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        if (n == 1) {
            return heights[0];
        }
        int ans = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int length = heights[stk.top()];
                stk.pop();
                int width = i;
                if (!stk.empty()) {
                    width = i - stk.top() - 1;
                }
                ans = max(ans, length * width);
            }
            stk.push(i);
        }
        while (!stk.empty()) {
            int length = heights[stk.top()];
            stk.pop();
            int width = n;
            if (!stk.empty()) {
                width = n - stk.top() - 1;
            }
            ans = max(ans, length * width);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,5,6,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n
// @lcpr case=end

 */
