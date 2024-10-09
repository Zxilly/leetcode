/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        vector<bool> pick(nums.size());

        function<void(int)> dfs = [&](int cur) {
            if (cur == nums.size()) {
                vector<int> a;
                for(int i = 0; i < nums.size(); i++) {
                    if (pick[i]) {
                        a.push_back(nums[i]);
                    }
                }
                ans.push_back(a);
            } else {
                pick[cur] = true;
                dfs(cur + 1);
                pick[cur] = false;
                dfs(cur + 1);
            }
        };

        dfs(0);

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

