// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30204
 *
 * [560] 和为 K 的子数组
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
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        ll sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

 */

