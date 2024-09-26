/*
 * @lc app=leetcode.cn id=2535 lang=cpp
 * @lcpr version=30204
 *
 * [2535] 数组元素和与数字和的绝对差
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
    int differenceOfSum(vector<int>& nums) {
        int numSum = 0;
        int bitSum = 0;

        auto getBit = [](int num) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };

        for (auto num : nums) {
            numSum += num;
            bitSum += getBit(num);
        }

        return abs(numSum - bitSum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,15,6,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

