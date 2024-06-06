/*
 * @lc app=leetcode.cn id=169 lang=cpp
 * @lcpr version=30203
 *
 * [169] 多数元素
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
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int cur;
        for (int num : nums) {
            if (count == 0) {
                cur = num;
            }
            count += (num == cur) ? 1 : -1;
        }

        return cur;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,1,1,1,2,2]\n
// @lcpr case=end

 */

