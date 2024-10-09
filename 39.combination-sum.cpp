/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> cur;
        int curSum = 0;

        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        function<void(int)> dfs = [&](int pos)
        {
            if (curSum > target)
            {
                return;
            }
            if (curSum == target)
            {
                ans.push_back(cur);
                return;
            }

            for (int i = pos; i < candidates.size(); i++)
            {
                int c = candidates[i];
                cur.push_back(c);
                curSum += c;
                dfs(i);
                cur.pop_back();
                curSum -= c;
            }
        };

        dfs(0);

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */
