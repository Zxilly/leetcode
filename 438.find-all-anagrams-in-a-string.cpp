/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> need, window;
        for (char c : p) {
            need[c]++;
        }

        int left = 0, right = p.size() - 1;
        for (int i = 0; i <= right; i++) {
            window[s[i]]++;
        }

        auto compare = [&] () -> bool {
            for (auto& [k, v] : need) {
                if (window[k] != v) {
                    return false;
                }
            }
            return true;
        };

        while (right < s.size()) {
            if (compare()) {
                ans.push_back(left);
            }
            window[s[left]]--;
            left++;
            right++;
            if (right < s.size()) {
                window[s[right]]++;
            } else {
                break;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

