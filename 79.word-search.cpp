// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 * @lcpr version=30204
 *
 * [79] 单词搜索
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
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis;

        for(int i = 0; i < m; i++) {
            vis.push_back(vector<bool>(n, false));
        }

        function<bool(int, pii)> check = [&](int cur, pii pos) -> bool
        {
            if (pos.first < 0 || pos.first >= m || pos.second < 0 || pos.second >= n)
            {
                return false;
            }

            if (board[pos.first][pos.second] != word[cur])
            {
                return false;
            }

            if (vis[pos.first][pos.second])
            {
                return false;
            }

            if (cur == word.size() - 1)
            {
                return true;
            }
            else
            {
                vis[pos.first][pos.second] = true;
                if (check(cur + 1, make_pair(pos.first + 1, pos.second)))
                {
                    return true;
                }
                if (check(cur + 1, make_pair(pos.first - 1, pos.second)))
                {
                    return true;
                }
                if (check(cur + 1, make_pair(pos.first, pos.second + 1)))
                {
                    return true;
                }
                if (check(cur + 1, make_pair(pos.first, pos.second - 1)))
                {
                    return true;
                }
                vis[pos.first][pos.second] = false;
                return false;
            }
        };

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check(0, make_pair(i, j)))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["a","b"],["c","d"]]\n"acdb"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"\n
// @lcpr case=end

// @lcpr case=start
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"\n
// @lcpr case=end

 */
