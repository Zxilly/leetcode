/*
 * @lc app=leetcode.cn id=148 lang=cpp
 * @lcpr version=30204
 *
 * [148] 排序链表
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> nodes;
        auto cur = head;
        while (cur) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        sort(nodes.begin(), nodes.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i]->next = i + 1 < nodes.size() ? nodes[i + 1] : nullptr;
        }
        return nodes.empty() ? nullptr : nodes[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

