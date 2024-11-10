#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "../leetcode/parser.hpp"
#else
#define dbg(...)
#endif
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        for(int i = 0; i + k * 2 - 1 < nums.size(); i++) {
            bool ok = true;
            for(int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] <= nums[j]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            for(int j = i + k; j < i + k * 2 - 1; j++) {
                if (nums[j + 1] <= nums[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<int> nums = {-15, 19};
    int k = 1;
    cout << sol.hasIncreasingSubarrays(nums, k) << endl;
}

