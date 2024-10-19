/*
 * @lc app=leetcode.cn id=139 lang=cpp
 * @lcpr version=30204
 *
 * [139] 单词拆分
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
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (auto w : wordDict)
            {
                if (i >= w.size() && s.substr(i - w.size(), w.size()) == w)
                {
                    dp[i] = dp[i] || dp[i - w.size()];
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "leetcode"\n["leet", "code"]\n
// @lcpr case=end

// @lcpr case=start
// "applepenapple"\n["apple", "pen"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]\n
// @lcpr case=end

 */
