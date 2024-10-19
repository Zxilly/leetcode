/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30204
 *
 * [322] 零钱兑换
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int min_val = INT_MAX;
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != -1) {
                    min_val = min(min_val, dp[i - coin] + 1);
                }
            }
            if (min_val != INT_MAX) {
                dp[i] = min_val;
            }
        }
        return dp[amount];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

