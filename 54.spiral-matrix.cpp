/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return ans;
        }

        int l = 0, r = n - 1, t = 0, b = m - 1;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            for (int i = t + 1; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (l < r && t < b) {
                for (int i = r - 1; i >= l; i--) {
                    ans.push_back(matrix[b][i]);
                }
                for (int i = b - 1; i > t; i--) {
                    ans.push_back(matrix[i][l]);
                }
            }
            l++;
            r--;
            t++;
            b--;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

