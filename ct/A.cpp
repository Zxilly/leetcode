#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "../leetcode/parser.hpp"
#else
#define dbg(...)
#endif
class Solution
{
public:
    // 给你一个字符串 target。

    // Alice 将会使用一种特殊的键盘在她的电脑上输入 target，这个键盘 只有两个 按键：

    // 按键 1：在屏幕上的字符串后追加字符 'a'。
    // 按键 2：将屏幕上字符串的 最后一个 字符更改为英文字母表中的 下一个 字符。例如，'c' 变为 'd'，'z' 变为 'a'。
    // 注意，最初屏幕上是一个空字符串 ""，所以她 只能 按按键 1。

    // 请你考虑按键次数 最少 的情况，按字符串出现顺序，返回 Alice 输入 target 时屏幕上出现的所有字符串列表。
    vector<string> stringSequence(string target)
    {
        vector<string> ans;
        vector<char> cur;
        for (char c : target)
        {
            cur.push_back('a');
            ans.push_back(string(cur.begin(), cur.end()));

            while (cur.back() != c)
            {
                cur.back()++;
                ans.push_back(string(cur.begin(), cur.end()));
            }
        }

        return ans;
    }
};
#ifdef LC_LOCAL
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
#endif
