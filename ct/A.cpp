#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "../leetcode/parser.hpp"
#else
#define dbg(...)
#endif
class Solution {
public:
    long long lcm(long long a, long long b) {
        return a * (b / gcd(a, b));
    }

    long long ll(const vector<int>& nums) {
        long long result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result = lcm(result, nums[i]);
        }
        return result;
    }

    long long gl(const vector<int>& nums) {
        long long result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            result = gcd(result, nums[i]);
        }
        return result;
    }


    long long maxScore(vector<int>& nums) {
        long long ans = gl(nums) * ll(nums);

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> erased = nums;
            erased.erase(erased.begin() + i);

            ans = max(ans, gl(erased) * ll(erased));
        }

        return ans;
    }
};
#ifdef LC_LOCAL
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
#endif
