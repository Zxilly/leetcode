/*
 * @lc app=leetcode.cn id=1928 lang=cpp
 * @lcpr version=30204
 *
 * [1928] 规定时间内到达终点的最小花费
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
using pii = pair<int, int>;

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        const int INFTY = INT_MAX / 2;
        int n = passingFees.size();
        vector<vector<int>> f(maxTime + 1, vector<int>(n, INFTY));
        f[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; ++t)
        {
            for (const auto &edge : edges)
            {
                int i = edge[0], j = edge[1], cost = edge[2];
                if (cost <= t)
                {
                    f[t][i] = min(f[t][i], f[t - cost][j] + passingFees[i]);
                    f[t][j] = min(f[t][j], f[t - cost][i] + passingFees[j]);
                }
            }
        }

        int ans = INFTY;
        for (int t = 1; t <= maxTime; ++t)
        {
            ans = min(ans, f[t][n - 1]);
        }
        return ans == INFTY ? -1 : ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 30\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start
// 29\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

// @lcpr case=start
// 25\n[[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]]\n[5,1,2,20,20,3]\n
// @lcpr case=end

 */
