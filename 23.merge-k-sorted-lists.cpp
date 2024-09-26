/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for (auto list : lists) {
            while(list != nullptr) {
                pq.push(list);
                list = list->next;
            }
        }

        ListNode dummy;
        auto cur = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
        }
        cur->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

