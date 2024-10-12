/*
 * @lc app=leetcode.cn id=121 lang=cpp
 * @lcpr version=30204
 *
 * [121] 买卖股票的最佳时机
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
    int maxProfit(vector<int> &prices)
    {
        int ans = 0;
        int mn = prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            ans = max(ans, prices[i] - mn);
            if (prices[i] < mn)
            {
                mn = prices[i];
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,1,5,3,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [7,6,4,3,1]\n
// @lcpr case=end

 */
