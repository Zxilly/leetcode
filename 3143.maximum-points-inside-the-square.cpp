// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3143 lang=cpp
 * @lcpr version=30204
 *
 * [3143] 正方形中的最多点数
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        sort(points.begin(), points.end(), [](auto &a, auto &b)
             { return max(abs(a[0]), abs(a[1])) < max(abs(b[0]), abs(b[1])); });

        for(auto &p: points){
            cout << p[0] << " " << p[1] << endl;
        }

        int cur = 0;
        int curCnt = 0;
        int ans = 0;
        set<char> seen;

        for (int i = 0; i < points.size(); i++)
        {
            auto &&p = points[i];
            int dis = max(p[0], p[1]);
            if (seen.count(s[i]))
            {
                curCnt = 0;
                break;
            }
            else
            {
                if (dis != cur)
                {
                    ans += curCnt;
                    cur = dis;
                    curCnt = 0;
                }

                if (seen.count(s[i]))
                {
                    curCnt = 0;
                    break;
                }
                else
                {
                    curCnt++;
                }

                seen.insert(s[i]);
            }
        }

        return ans + curCnt;
    }
};


// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxPointsInsideSquare
// paramTypes= ["number[][]","string"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]]\n"abdca"\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[-2,-2],[-2,2]]\n"abb"\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[-1,-1],[2,-2]]\n"ccd"\n
// @lcpr case=end

 */
