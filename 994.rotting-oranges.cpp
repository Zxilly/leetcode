/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30204
 *
 * [994] 腐烂的橘子
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
    int orangesRotting(vector<vector<int>> &grid)
    {
        deque<pair<int, int>> bads;

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    bads.emplace_back(i, j);
                }
            }
        }

        int ans = 0;
        while (!bads.empty())
        {
            auto check = [&](int x, int y)
            {
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                {
                    return;
                }
                if (grid[x][y] == 1)
                {
                    grid[x][y] = 2;
                    bads.emplace_back(x, y);
                }
            };
            int left = bads.size();
            while (left--)
            {
                auto [x, y] = bads.front();
                bads.pop_front();
                check(x - 1, y);
                check(x + 1, y);
                check(x, y - 1);
                check(x, y + 1);
            }
            if (!bads.empty())
            {
                ans++;
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */
