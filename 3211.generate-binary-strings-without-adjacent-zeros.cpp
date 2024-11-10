/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 * @lcpr version=30204
 *
 * [3211] 生成不含相邻零的二进制字符串
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
    vector<string> validStrings(int n) {
        vector<string> res;

        vector<char> tmp;
        auto dfs = [&](auto &&dfs, int idx) -> void {
            if (idx == n) {
                res.emplace_back(tmp.begin(), tmp.end());
                return;
            }

            tmp.push_back('1');
            dfs(dfs, idx + 1);
            tmp.pop_back();

            if (tmp.empty() || tmp.back() != '0') {
                tmp.push_back('0');
                dfs(dfs, idx + 1);
                tmp.pop_back();
            }
        };

        dfs(dfs, 0);

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

