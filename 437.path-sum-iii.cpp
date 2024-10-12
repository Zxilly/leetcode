/*
 * @lc app=leetcode.cn id=437 lang=cpp
 * @lcpr version=30204
 *
 * [437] 路径总和 III
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

using ll = long long;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll, int> prefix;
        prefix[0] = 1;
        
        auto dfs = [&](auto&& dfs, TreeNode* root, ll cur, int targetSum) -> int {
            if (!root) {
                return 0;
            }

            cur += root->val;
            ll res = 0;
            res += prefix[cur - targetSum];
            prefix[cur]++;
            res += dfs(dfs, root->left, cur, targetSum);
            res += dfs(dfs, root->right, cur, targetSum);
            prefix[cur]--;
            return res;
        };

        return dfs(dfs, root, 0, targetSum);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */

