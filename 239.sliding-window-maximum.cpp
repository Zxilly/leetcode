/*
 * @lc app=leetcode.cn id=239 lang=cpp
 * @lcpr version=30204
 *
 * [239] 滑动窗口最大值
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }
            window.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[window.front()]);
                if (window.front() == i - k + 1) {
                    window.pop_front();
                }
            }
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,-1,-3,5,3,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

