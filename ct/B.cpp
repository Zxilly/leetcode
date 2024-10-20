#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "../leetcode/parser.hpp"
#else
#define dbg(...)
#endif

class Solution
{
public:
    vector<int> prime(int max_n)
    {
        vector<int> min_prime(max_n + 1, 0);
        for (int i = 2; i <= max_n; ++i)
        {
            if (min_prime[i] == 0)
            {
                min_prime[i] = i;
                for (int j = i * 2; j <= max_n; j += i)
                {
                    if (min_prime[j] == 0)
                    {
                        min_prime[j] = i;
                    }
                }
            }
        }
        return min_prime;
    }

    int minOperations(vector<int> &nums)
    {
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> min_prime = prime(max_num);

        int n = nums.size();
        int ans = 0;

        for (int i = n - 2; i >= 0; --i)
        {
            auto &&target = nums[i];
            int cur = nums[i + 1];
            if (cur < target)
            {
                target = min_prime[target];
                ans++;
            }
            if (cur < target)
            {
                return -1;
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
    cout << sol.minOperations(nums) << endl;
}
