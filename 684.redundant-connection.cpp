/*
 * @lc app=leetcode.cn id=684 lang=cpp
 * @lcpr version=30204
 *
 * [684] 冗余连接
 */


// @lcpr-template-start
#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#endif
// @lcpr-template-end
// @lc code=start
class dsu
{
private:
    vector<int> fa, siz;
    int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
public:
    dsu(int n)
    {
        fa.resize(n);
        siz.assign(n,1);
        iota(fa.begin(), fa.end(), 0);
    }
    bool merge(int x,int y)
    {
        x=find(x), y=find(y);
        if(x==y) return false;
        fa[x] = y;
        siz[y] += siz[x];
        return true;
    }
    int operator[](int x) { return find(x); }
    int size(int x) { return this->siz[x]; }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        dsu ufs(edges.size()+1);

        for(auto e: edges) {
            int x = e[0], y = e[1];
            if(!ufs.merge(x, y)) return {x, y};
        }

        return {};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2], [1,3], [2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
// @lcpr case=end

 */

