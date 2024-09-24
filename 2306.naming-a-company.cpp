// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2306 lang=cpp
 * @lcpr version=30204
 *
 * [2306] 公司命名
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
using ll = long long;

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        unordered_map<char, set<string>> mp;
        for (auto &&idea : ideas)
        {
            auto suf = idea.substr(1);
            mp[idea[0]].insert(suf);
        }

        ll ans = 0;
        vector<pair<char, set<string>>> vec(mp.begin(), mp.end());

        for (int i = 0; i < vec.size() - 1; i++)
        {
            for (int j = i + 1; j < vec.size(); j++)
            {
                auto max_len = max(vec[i].second.size(), vec[j].second.size());

                vector<string> inter(max_len);
                auto it = set_intersection(vec[i].second.begin(), vec[i].second.end(), vec[j].second.begin(), vec[j].second.end(), inter.begin());

                auto inter_len = distance(inter.begin(), it);

                ans += (vec[i].second.size() - inter_len) * (vec[j].second.size() - inter_len) * 2;
            }
        }

        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=distinctNames
// paramTypes= ["string[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// ["coffee","donuts","time","toffee"]\n
// @lcpr case=end

// @lcpr case=start
// ["lack","back"]\n
// @lcpr case=end

 */
