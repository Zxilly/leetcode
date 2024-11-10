#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "../leetcode/parser.hpp"
#else
#define dbg(...)
#endif

using ll = long long;

class Solution
{
public:
    // 给你一个由 n 个整数组成的数组 nums ，请你找出 k 的 最大值，使得存在 两个 相邻 且长度为 k 的 严格递增 子数组。
    // 具体来说，需要检查是否存在从下标 a 和 b (a < b) 开始的 两个 子数组，并满足下述全部条件：
    // 这两个子数组 nums[a..a + k - 1] 和 nums[b..b + k - 1] 都是 严格递增 的。
    // 这两个子数组必须是 相邻的，即 b = a + k。
    // 返回 k 的 最大可能 值。
    // 子数组 是数组中的一个连续 非空 的元素序列。
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> incl(n, 1);
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                incl[i] = incl[i + 1] + 1;
            }
            else
            {
                incl[i] = 1;
            }
        }

        int l = 1, r = n / 2, ans = 0;
        while (l <= r)
        {
            int k = l + (r - l) / 2;
            bool found = false;
            for (int i = 0; i <= n - 2 * k; i++)
            {
                if (incl[i] >= k && incl[i + k] >= k)
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                ans = k;
                l = k + 1;
            }
            else
            {
                r = k - 1;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> nums = {105, 11};
}
