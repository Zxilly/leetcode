// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=32 lang=cpp
 * @lcpr version=30204
 *
 * [32] 最长有效括号
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
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size() + 1, 0);
        for (int i = 1; i < s.size(); i++)
        {
            char cur = s[i];
            if (cur == '(')
            {
                continue;
            }
            else
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = 2;
                    if (i > 2)
                    {
                        dp[i] += dp[i - 2];
                    }
                } else {
                    int pi = i - dp[i - 1] - 1;
                    if (pi >= 0 && s[pi] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (pi > 0) {
                            dp[i] += dp[pi - 1];
                        }
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

/*
// @lcpr case=start
// "(()"\n
// @lcpr case=end

// @lcpr case=start
// ")()())"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

 */
