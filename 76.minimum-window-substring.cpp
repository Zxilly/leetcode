/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=30204
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        for (auto c : t) {
            window[c]--;
        }

        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            auto c = s[right];
            right++;

            if (window.count(c)) {
                window[c]++;
                if (window[c] == 0) {
                    valid++;
                }
            }

            while (valid == window.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                auto d = s[left];
                left++;

                if (window.count(d)) {
                    if (window[d] == 0) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */

