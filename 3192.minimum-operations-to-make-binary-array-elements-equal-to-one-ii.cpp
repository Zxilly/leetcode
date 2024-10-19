/*
 * @lc app=leetcode.cn id=3192 lang=cpp
 * @lcpr version=30204
 *
 * [3192] 使二进制数组全部等于 1 的最少操作次数 II
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
    int minOperations(vector<int> &nums)
    {
        int op = 0;
        for (auto i : nums)
        {
            if (i % 2 == 0)
            {
                if (op % 2 == 1)
                {
                    continue;
                }
                else
                {
                    op++;
                }
            }
            else
            {
                if (op % 2 == 1)
                {
                    op++;
                }
                else
                {
                    continue;
                }
            }
        }
        return op;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0]\n
// @lcpr case=end

 */
