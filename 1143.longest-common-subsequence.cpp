// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 * @lcpr version=30204
 *
 * [1143] 最长公共子序列
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
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));

        for (int i = 0; i < text1.size(); i++)
        {
            dp[i][0] = max(int(text1[i] == text2[0]), i > 0 ? dp[i - 1][0] : 0);
        }
        for (int i = 0; i < text2.size(); i++)
        {
            dp[0][i] = max(int(text1[0] == text2[i]), i > 0 ? dp[0][i - 1] : 0);
        }

        for (int i = 1; i < text1.size(); i++)
        {
            for (int j = 1; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=longestCommonSubsequence
// paramTypes= ["string","string"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */
