// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3321 lang=cpp
 * @lcpr version=30204
 *
 * [3321] 计算子数组的 x-sum II
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
struct Element
{
    int cnt;
    int val;

    bool operator<(const Element &other) const
    {
        if (cnt == other.cnt)
        {
            return val > other.val;
        }
        return cnt > other.cnt;
    };

    bool operator==(const Element &other) const
    {
        return cnt == other.cnt && val == other.val;
    };
};

class Solution
{
public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        set<Element> top_set;
        set<Element> rest_set;
        long long top_sum = 0;

        vector<long long> ans;

        map<int, int> cnt_map;

        auto insert = [&](int add_val, int rm_val, bool rm) -> void
        {
            if (add_val == rm_val)
            {
                return;
            }

            int cnt = cnt_map[add_val];

            bool need_update = false;

            auto it = top_set.find({cnt, add_val});
            if (it != top_set.end())
            {
                int old_cnt = it->cnt;
                top_set.erase(it);
                top_set.insert({old_cnt + 1, add_val});
                top_sum += add_val;
            }
            else
            {
                if (top_set.size() < x)
                {
                    top_set.insert({cnt + 1, add_val});
                    top_sum += add_val;
                }
                else
                {
                    need_update = true;
                    auto it = rest_set.find({cnt, add_val});
                    if (it != rest_set.end())
                    {
                        int old_cnt = it->cnt;
                        rest_set.erase(it);
                        rest_set.insert({old_cnt + 1, add_val});
                    }
                    else
                    {
                        rest_set.insert({cnt + 1, add_val});
                    }
                }
            }
            cnt_map[add_val]++;

            if (rm)
            {
                cnt = cnt_map[rm_val];
                it = rest_set.find({cnt, rm_val});
                if (it != rest_set.end())
                {
                    int old_cnt = it->cnt;
                    rest_set.erase(it);
                    rest_set.insert({old_cnt - 1, rm_val});
                }
                else
                {
                    it = top_set.find({cnt, rm_val});
                    if (it != top_set.end())
                    {
                        int old_cnt = it->cnt;
                        top_set.erase(it);
                        top_set.insert({old_cnt - 1, rm_val});
                        top_sum -= rm_val;
                        need_update = true;
                    }
                }
                cnt_map[rm_val]--;
            }

            if (need_update)
            {
                while (true)
                {
                    auto top_back = *prev(top_set.end());
                    auto rest_front = *rest_set.begin();
                    if (top_back.cnt < rest_front.cnt || (top_back.cnt == rest_front.cnt && top_back.val < rest_front.val))
                    {
                        top_set.erase(top_back);
                        rest_set.erase(rest_front);
                        top_set.insert(rest_front);
                        rest_set.insert(top_back);
                        top_sum = top_sum - 1LL * top_back.val * top_back.cnt + 1LL * rest_front.val * rest_front.cnt;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return;
        };

        for (int i = 0; i < k; i++)
        {
            insert(nums[i], 0, false);
        }

        ans.push_back(top_sum);
        for (int i = k; i < nums.size(); i++)
        {
            insert(nums[i], nums[i - k], true);
            ans.push_back(top_sum);
        }
        return ans;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findXSum
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [1,1,2,2,3,4,2,3]\n6\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,8,7,8,7,5]\n2\n2\n
// @lcpr case=end

 */
