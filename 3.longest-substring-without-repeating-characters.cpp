// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30203
 *
 * [3] 无重复字符的最长子串
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
    exec(&Solution::lengthOfLongestSubstring); // CHANGE FOR PROBLEM
}
#endif
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty()) {
            return 0;
        }

        int ans = INT_MIN;
        set<char> found;
        int pre = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (found.contains(c)) {
                while (s[pre] != c) {
                    found.erase(s[pre]);
                    pre++;
                }
                pre++;
            } else {
                found.insert(c);
            }
            ans = max(ans, i - pre + 1);
        }

        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
