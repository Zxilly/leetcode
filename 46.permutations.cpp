/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=30204
 *
 * [46] 全排列
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> known;
        vector<bool> vis(nums.size(), false);
        dfs(nums, known, vis, ans);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& known, vector<bool> vis, vector<vector<int>>& ans) {
        if (known.size() == nums.size()) {
            ans.push_back(known);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            known.push_back(nums[i]);
            dfs(nums, known, vis, ans);
            known.pop_back();
            vis[i] = false;
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

