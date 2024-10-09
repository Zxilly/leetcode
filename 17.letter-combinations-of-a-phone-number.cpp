/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        map<char, string> cs = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        vector<char> path;
        function<void(int)> build = [&](int cur)
        {
            if (path.size() == digits.size())
            {
                ans.emplace_back(string(path.begin(), path.end()));
                return;
            }

            for (auto c : cs[digits[cur]])
            {
                path.emplace_back(c);
                build(cur + 1);
                path.pop_back();
            }
        };

        if (!digits.empty())
        {
            build(0);
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */
