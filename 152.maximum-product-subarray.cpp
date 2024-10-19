/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30204
 *
 * [152] 乘积最大子数组
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
    int maxProduct(vector<int>& nums) {
        vector<int> max_dp(nums.size());
        vector<int> min_dp(nums.size());
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            max_dp[i] = max({nums[i], max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]});
            min_dp[i] = min({nums[i], max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]});
        }
        return *max_element(max_dp.begin(), max_dp.end());

    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */

