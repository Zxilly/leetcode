/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 * @lcpr version=30204
 *
 * [1436] 旅行终点站
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
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> out;
        for (auto &path : paths) {
            out[path[0]]++;
        }
        for (auto &path : paths) {
            if (out[path[1]] == 0) {
                return path[1];
            }
        }
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]\n
// @lcpr case=end

// @lcpr case=start
// [["B","C"],["D","B"],["C","A"]]\n
// @lcpr case=end

// @lcpr case=start
// [["A","Z"]]\n
// @lcpr case=end

 */

