/*
 * @lc app=leetcode.cn id=138 lang=cpp
 * @lcpr version=30204
 *
 * [138] 随机链表的复制
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        if (mp.count(head)) {
            return mp[head];
        }

        auto node = new Node(head->val);
        mp[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

 */

