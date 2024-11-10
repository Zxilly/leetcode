#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#else
#define dbg(...)
#endif

using ll = long long;
const int MOD = 1e9 + 7;

class Solution
{
public:
    int countKReducibleNumbers(string s, int k)
    {
        int n = s.length();

        vector<int> cost(n + 1, -1);
        function<int(int)> get_cost = [&](int x) -> int
        {
            if (cost[x] != -1)
                return cost[x];
            if (x == 1)
                return cost[x] = 0;
            int cnt = __builtin_popcount(x);
            return cost[x] = 1 + get_cost(cnt);
        };
        for (int i = 1; i <= n; ++i)
        {
            cost[i] = get_cost(i);
        }
        cost[0] = INT32_MAX;

        vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(2, 0))));
        dp[0][0][1][0] = 1;

        for (int pos = 0; pos < n; ++pos)
        {
            for (int sum = 0; sum <= n; ++sum)
            {
                for (int tight = 0; tight <= 1; ++tight)
                {
                    for (int is_num_started = 0; is_num_started <= 1; ++is_num_started)
                    {
                        if (dp[pos][sum][tight][is_num_started] == 0)
                            continue;
                        int limit = tight ? (s[pos] - '0') : 1;
                        for (int digit = 0; digit <= limit; ++digit)
                        {
                            int other = tight && (digit == limit) ? 1 : 0;
                            int started = is_num_started;
                            int new_sum = sum;
                            if (is_num_started)
                            {
                                new_sum += digit;
                            }
                            else
                            {
                                if (digit == 1)
                                    started = 1;
                            }

                            if (new_sum > n)
                                continue;

                            dp[pos + 1][new_sum][other][started] =
                                (dp[pos + 1][new_sum][other][started] + dp[pos][sum][tight][is_num_started]) % MOD;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int sum = 1; sum <= n; ++sum)
        {
            if (cost[sum] > k)
                continue;
            ans = (ans + dp[n][sum][0][1]) % MOD;
            ans = (ans + dp[n][sum][1][1]) % MOD;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}