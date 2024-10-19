/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30204
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s)
    {
        int len = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = s.size() - 1 - i;
            int step = min(left, right);

            for (int j = 0; j <= step; j++)
            {
                if (s[i - j] == s[i + j])
                {
                    if (2 * j + 1 > len)
                    {
                        len = 2 * j + 1;
                        start = i - j;
                        end = i + j;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        for (int i = 1; i < s.size(); i++)
        {
            int left = i;
            int right = s.size() - i;

            int step = min(left, right);

            for (int j = 0; j <= step; j++)
            {
                if (s[i - j] == s[i + j - 1])
                {
                    if (2 * j > len)
                    {
                        len = 2 * j;
                        start = i - j;
                        end = i + j - 1;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
