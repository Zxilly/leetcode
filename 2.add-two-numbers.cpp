/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30203
 *
 * [2] 两数相加
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#else
#define dbg(...)
#endif
#ifdef LC_LOCAL
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    exec(&Solution::addTwoNumbers); // CHANGE FOR PROBLEM
}
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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int addNxt = 0;
        auto head = new ListNode();

        auto cur = head;

        while (l1 || l2 || addNxt)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + addNxt;

            addNxt = sum / 10;

            int val = sum % 10;

            cur->next = new ListNode(val);

            cur = cur->next;

            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }

        return head->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
