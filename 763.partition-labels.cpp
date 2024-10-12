/*
 * @lc app=leetcode.cn id=763 lang=cpp
 * @lcpr version=30204
 *
 * [763] 划分字母区间
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
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>> mp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = {i, i};
            } else {
                mp[s[i]].second = i;
            }
        }

        vector<int> ans;
        vector<pair<int, int>> ps;
        for (auto [k, v] : mp) {
            ps.push_back(v);
        }

        sort(ps.begin(), ps.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        });

        int l = ps[0].first;
        int r = ps[0].second;
        for (int i = 1; i < ps.size(); i++) {
            if (ps[i].first > r) {
                ans.push_back(r - l + 1);
                l = ps[i].first;
                r = ps[i].second;
            } else {
                r = max(r, ps[i].second);
            }
        }

        ans.push_back(r - l + 1);

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ababcbacadefegdehijhklij"\n
// @lcpr case=end

// @lcpr case=start
// "eccbbbbdec"\n
// @lcpr case=end

 */

