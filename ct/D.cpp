#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#else
#define dbg(...)
#endif

using ll = long long;

inline ll c2(ll n)
{
    return (n * (n - 1)) / 2;
}

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end());

        int MAX = max_num;
        vector<long long> freq(MAX + 1, 0);
        for (auto x : nums)
        {
            freq[x]++;
        }

        vector<long long> cnt(MAX + 1, 0);
        for (int g = 1; g <= MAX; g++)
        {
            for (int multiple = g; multiple <= MAX; multiple += g)
            {
                cnt[g] += freq[multiple];
            }
        }

        vector<long long> exact(MAX + 1, 0);
        for (int g = MAX; g >= 1; g--)
        {
            exact[g] = c2(cnt[g]);
            for (int multiple = 2 * g; multiple <= MAX; multiple += g)
            {
                exact[g] -= exact[multiple];
            }
        }

        vector<pair<int, long long>> gcd_list;
        for (int g = 1; g <= MAX; g++)
        {
            if (exact[g] > 0)
            {
                gcd_list.emplace_back(g, exact[g]);
            }
        }
        sort(gcd_list.begin(), gcd_list.end());

        vector<ll> prefixSum;
        prefixSum.reserve(gcd_list.size());
        ll current_sum = 0;
        for (auto &[g, cnt_g] : gcd_list)
        {
            current_sum += cnt_g;
            prefixSum.emplace_back(current_sum);
        }

        vector<int> answer;
        for (auto q_idx : queries)
        {
            ll target = q_idx + 1;
            int left = 0, right = prefixSum.size() - 1;
            int res = -1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (prefixSum[mid] >= target)
                {
                    res = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            answer.push_back(res != -1 ? gcd_list[res].first : -1);
        }

        return answer;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    // [[1,2],[0,2],[0,1],[3,4]]
    vector<vector<int>> ins = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    sol.remainingMethods(5, 0, ins);
}