/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30203
 *
 * [20] 有效的括号
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#else
#define dbg(...)
#endif
#ifdef LC_LOCAL
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    exec(&Solution::isValid); // CHANGE FOR PROBLEM
}
#endif
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                st.push(c);
                continue;
            }

            if (st.empty())
            {
                return false;
            }

            auto curTop = st.top();
            switch (c)
            {
            case ')':
                if (curTop != '(')
                {
                    return false;
                }
                break;
            case ']':
                if (curTop != '[')
                {
                    return false;
                }
                break;
            case '}':
                if (curTop != '{')
                {
                    return false;
                }
                break;
            }
            st.pop();
        }
        return st.empty();
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

 */
