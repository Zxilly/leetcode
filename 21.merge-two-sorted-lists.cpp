/*
 * @lc app=leetcode.cn id=21 lang=cpp
 * @lcpr version=30204
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 && !list2) {
            return nullptr;
        }

        if (!list1) {
            return list2;
        }

        if (!list2) {
            return list1;
        }

        ListNode* cur = nullptr;
        if (list1->val < list2->val) {
            cur = list1;
            list1 = list1->next;
        } else {
            cur = list2;
            list2 = list2->next;
        }

        ListNode* head = cur;

        while(list1 || list2) {
            if (list1 && list2) {
                if (list1->val < list2->val) {
                    cur->next = list1;
                    list1 = list1->next;
                } else {
                    cur->next = list2;
                    list2 = list2->next;
                }
            } else if (list1) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */

