// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=30204
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return build(preorder, inorder);
    }

    TreeNode *build(std::ranges::subrange<vector<int>::iterator> pre, 
                    std::ranges::subrange<vector<int>::iterator> in)
    {
        if (pre.empty())
        {
            return nullptr;
        }
        
        auto root = new TreeNode(*pre.begin());
        
        auto in_root_pos = std::ranges::find(in, *pre.begin());
        auto left_size = in_root_pos - in.begin();
        
        auto left_pre = std::ranges::subrange(pre.begin() + 1, pre.begin() + 1 + left_size);
        auto left_in = std::ranges::subrange(in.begin(), in_root_pos);
        
        auto right_pre = std::ranges::subrange(pre.begin() + 1 + left_size, pre.end());
        auto right_in = std::ranges::subrange(in_root_pos + 1, in.end());
        
        root->left = build(left_pre, left_in);
        root->right = build(right_pre, right_in);
        
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
