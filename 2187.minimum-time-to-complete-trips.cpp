/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 * @lcpr version=30204
 *
 * [2187] 完成旅途的最少时间
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

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 0;

        ll r = *max_element(time.begin(), time.end()) * (ll)totalTrips;

        ll ans = r;

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            
            ll cnt = 0;
            for (int i = 0; i < time.size(); i++) {
                cnt += mid / time[i];
            }

            if (cnt >= totalTrips) {
                ans = min(ans, mid);
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

