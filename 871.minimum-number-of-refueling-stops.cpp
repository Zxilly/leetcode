// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=871 lang=cpp
 * @lcpr version=30204
 *
 * [871] 最低加油次数
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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        priority_queue<int> pq;
        stations.push_back({target, 0});
        for (int i = 0; i < stations.size() && stations[i][0] <= target; i++) {
            startFuel -= stations[i][0] - (i == 0 ? 0 : stations[i - 1][0]);
            while (startFuel < 0 && !pq.empty()) {
                startFuel += pq.top();
                pq.pop();
                ans++;
            }
            if (startFuel < 0) return -1;
            pq.emplace(stations[i][1]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n1\n[]\n
// @lcpr case=end

// @lcpr case=start
// 100\n1\n[[10,100]]\n
// @lcpr case=end

// @lcpr case=start
// 100\n10\n[[10,60],[20,30],[30,30],[60,40]]\n
// @lcpr case=end

 */

