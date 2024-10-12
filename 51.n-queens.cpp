/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
    vector<vector<string>> solveNQueens(int n) {
        vector<string> mp(n, string(n, '.'));

        auto check = [&](int x, int y) {
            for (int i = 0; i < x; i++) {
                if (mp[i][y] == 'Q') {
                    return false;
                }
            }

            for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
                if (mp[i][j] == 'Q') {
                    return false;
                }
            }

            for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
                if (mp[i][j] == 'Q') {
                    return false;
                }
            }

            return true;
        };

        auto dfs = [&](auto&& dfs, int x) -> vector<vector<string>> {
            if (x == n) {
                return {mp};
            }

            vector<vector<string>> res;
            for (int i = 0; i < n; i++) {
                if (check(x, i)) {
                    mp[x][i] = 'Q';
                    auto tmp = dfs(dfs, x + 1);
                    res.insert(res.end(), tmp.begin(), tmp.end());
                    mp[x][i] = '.';
                }
            }

            return res;
        };

        return dfs(dfs, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

