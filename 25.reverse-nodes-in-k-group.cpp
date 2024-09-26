/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30204
 *
 * [25] K 个一组翻转链表
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
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        auto pre = tail->next;
        auto cur = head;
        while (pre != tail) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(0, head);
        auto pre = dummy;
        while (head) {
            auto tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummy->next;
                }
            }
            auto next = tail->next;
            auto [newHead, newTail] = reverse(head, tail);
            pre->next = newHead;
            newTail->next = next;
            pre = newTail;
            head = next;
        }

        return dummy->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

