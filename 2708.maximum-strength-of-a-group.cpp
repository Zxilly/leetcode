/*
 * @lc app=leetcode.cn id=2708 lang=cpp
 * @lcpr version=30204
 *
 * [2708] 一个小组的最大实力值
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
  long long maxStrength(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];

    vector<int> negs;
    vector<int> poss;
    bool hasZero = false;

    for (auto &n : nums) {
      if (n < 0)
        negs.push_back(n);
      else if (n > 0)
        poss.push_back(n);
      else
        hasZero = true;
    }

    sort(negs.begin(), negs.end());
    sort(poss.begin(), poss.end());

    long long hasNegValue = false;
    long long negValue = 1;
    long long hasPosValue = false;
    long long posValue = 1;

    if (!negs.empty()) {
        if (negs.size() % 2 == 1) {
            if (negs.size() > 1) {
                hasNegValue = true;
                for(int i = 0; i < negs.size() - 1; i++) {
                    negValue *= negs[i];
                }
            }
        } else {
            hasNegValue = true;
            for(int i = 0; i < negs.size(); i++) {
                negValue *= negs[i];
            }
        }
    }

    if (!poss.empty()) {
        hasPosValue = true;
        for(int i = 0; i < poss.size(); i++) {
            posValue *= poss[i];
        }
    }

    int ans = 1;

    if (!hasPosValue) {
        if (hasNegValue) {
            return negValue;
        }

        if (hasZero) {
            return 0;
        }

        return negs[0];
    }

    return negValue * posValue;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [3,-1,-5,2,5,-9]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-5,-4]\n
// @lcpr case=end

 */
