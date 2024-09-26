/*
 * @lc app=leetcode.cn id=234 lang=cpp
 * @lcpr version=30204
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while(head) {
            vec.push_back(head->val);
            head = head->next;
        }
        int n = vec.size();
        int l = 0, r = n - 1;
        while(l < r) {
            if(vec[l] != vec[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

