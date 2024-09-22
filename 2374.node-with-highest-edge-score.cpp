// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2374 lang=cpp
 * @lcpr version=30204
 *
 * [2374] 边积分最高的节点
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
    int edgeScore(vector<int> &edges)
    {
        map<ll, ll> cnt;
        for (int i = 0; i < edges.size(); i++)
        {
            cnt[edges[i]] += i;
        }

        ll ans = LONG_LONG_MIN;
        ll cur = LONG_LONG_MIN;

        for (int i = 0; i < edges.size(); i++)
        {
            if (cnt[i] > cur)
            {
                cur = cnt[i];
                ans = i;
            }
        }

        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=edgeScore
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,0,0,0,0,7,7,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,0,2]\n
// @lcpr case=end

 */
