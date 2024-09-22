/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
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
  double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
  {
    int n = arr1.size(), m = arr2.size();

    // If arr1 has more elements, then call medianOf2
    // with reversed parameters
    if (n > m)
      return findMedianSortedArrays(arr2, arr1);

    int low = 0, high = n;
    while (low <= high)
    {
      int mid1 = (low + high) / 2;
      int mid2 = (n + m + 1) / 2 - mid1;

      int l1 = (mid1 == 0 ? INT_MIN : arr1[mid1 - 1]);
      int r1 = (mid1 == n ? INT_MAX : arr1[mid1]);

      int l2 = (mid2 == 0 ? INT_MIN : arr2[mid2 - 1]);
      int r2 = (mid2 == m ? INT_MAX : arr2[mid2]);

      if (l1 <= r2 && l2 <= r1)
      {
        if ((n + m) % 2 == 0)
          return (max(l1, l2) + min(r1, r2)) / 2.0;
        else
          return max(l1, l2);
      }

      if (l1 > r2)
        high = mid1 - 1;

      else
        low = mid1 + 1;
    }
    return 0;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */
