// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2207 lang=cpp
 * @lcpr version=30204
 *
 * [2207] 字符串中最多数目的子序列
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
    long long maximumSubsequenceCount(string text, string pattern) {
        ll preCnt = 0, postCnt = 0;
        ll orig = 0;
        for (auto t: text) {
            if (t == pattern[1]) {
                postCnt++;
                orig += preCnt;
            }

            if (t == pattern[0]) {
                preCnt++;
            }
        }

        ll addt = max(preCnt, postCnt);

        return orig + addt;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumSubsequenceCount
// paramTypes= ["string","string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "abdcdbc"\n"ac"\n
// @lcpr case=end

// @lcpr case=start
// "fwymvreuftzgrcrxczjacqovduqaiig"\n"yy"\n
// @lcpr case=end

 */

