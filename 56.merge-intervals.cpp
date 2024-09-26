/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto&& a, auto&& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;

        vector<int> cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (cur[1] >= intervals[i][0]) {
                cur[1] = max(cur[1], intervals[i][1]);
            } else {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

