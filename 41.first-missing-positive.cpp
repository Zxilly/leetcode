// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30204
 *
 * [41] 缺失的第一个正数
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
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            auto cur = nums[i];
            if (cur <= 0 || cur > nums.size()) {
                nums[i] = 0;
                continue;
            }

            if (cur == i + 1) {
                continue;
            }

            auto mt = nums[cur - 1];
            if (mt != cur) {
                nums[cur - 1] = cur;
                nums[i] = mt;
                i--;
                continue;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

