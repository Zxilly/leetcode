/*
 * @lc app=leetcode.cn id=238 lang=cpp
 * @lcpr version=30204
 *
 * [238] 除自身以外数组的乘积
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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size() + 1, 1);
        vector<int> suf(nums.size() + 1, 1);

        for (int i = 0; i < nums.size(); i++) {
            pre[i + 1] = pre[i] * nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i];
        }

        vector<int> res(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            res[i] = pre[i] * suf[i + 1];
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1,0,-3,3]\n
// @lcpr case=end

 */

