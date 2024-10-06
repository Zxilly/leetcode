/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=30204
 *
 * [208] 实现 Trie (前缀树)
 */

// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class Trie
{
public:
    unordered_map<char, Trie *> children;
    bool isEnd;

    Trie()
    {
        this->isEnd = false;
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (!node->children.contains(c))
            {
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            if (!node->children.count(c))
            {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
