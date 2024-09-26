// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30204
 *
 * [394] 字符串解码
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
    string decodeString(string s)
    {
        string ans;
        stack<char> numCS;

        int i = 0;

        auto get_num = [&]()
        {
            int num = 0;
            int base = 1;
            while (!numCS.empty())
            {
                num += (numCS.top() - '0') * base;
                base *= 10;
                numCS.pop();
            }
            return num;
        };

        auto parseCnt = [&]()
        {
            while (i < s.size() && isdigit(s[i]))
            {
                numCS.push(s[i]);
                i++;
            }
            return get_num();
        };

        function<string()> parseTmpl = [&]()
        {
            int cnt = parseCnt();
            i++; // skip [
            string tmpl;

            while (i < s.size() && s[i] != ']')
            {
                if (isdigit(s[i]))
                {
                    tmpl += parseTmpl();
                }
                else
                {
                    tmpl += s[i];
                    i++;
                }
            }

            i++; // skip ]

            string res;
            while (cnt--)
            {
                res += tmpl;
            }

            return res;
        };

        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                ans += parseTmpl();
            }
            else
            {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "100[leetcode]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */
