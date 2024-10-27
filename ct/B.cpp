#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "../leetcode/parser.hpp"
#else
#define dbg(...)
#endif

using ll = long long;

class mint
{
    const static ll mod = 1e9 + 7;
    ll x;
    void norm()
    {
        if (!(-mod <= x && x < mod))
            x %= mod;
        if (x < 0)
            x += mod;
    }

public:
    mint() : x(0) {}
    mint(ll x) : x(x) { norm(); }
    auto val() const { return x; }
    friend mint operator^(mint lhs, mint rhs)
    {
        mint res = 1;
        for (; rhs.x; rhs.x >>= 1)
        {
            if (rhs.x & 1)
                res *= lhs;
            lhs *= lhs;
        }
        return res;
    }
    mint operator~() { return (*this) ^ (mod - 2); }
    friend bool operator<(mint lhs, mint rhs) { return lhs.x < rhs.x; }
    friend bool operator==(mint lhs, mint rhs) { return lhs.x == rhs.x; }
    friend mint operator+=(mint &lhs, mint rhs) { return lhs = lhs.x + rhs.x; }
    friend mint operator+(mint lhs, mint rhs) { return lhs += rhs; }
    friend mint operator-=(mint &lhs, mint rhs) { return lhs = lhs.x - rhs.x; }
    friend mint operator-(mint lhs, mint rhs) { return lhs -= rhs; }
    friend mint operator*=(mint &lhs, mint rhs) { return lhs = lhs.x * rhs.x; }
    friend mint operator*(mint lhs, mint rhs) { return lhs *= rhs; }
    friend mint operator/=(mint &lhs, mint rhs) { return lhs *= (~rhs); }
    friend mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }
    friend istream &operator>>(istream &is, mint &rhs)
    {
        is >> rhs.x;
        rhs.norm();
        return is;
    }
    friend ostream &operator<<(ostream &os, mint rhs) { return os << rhs.x; }
};
template <>
struct std::formatter<mint> : std::formatter<ll>
{
    auto format(mint m, format_context &ctx) const
    {
        return std::formatter<ll>::format(m.val(), ctx);
    }
};

class Solution
{
public:
    // 给你一个字符串 s 和一个整数 t，表示要执行的 转换 次数。每次 转换 需要根据以下规则替换字符串 s 中的每个字符：

    // 如果字符是 'z'，则将其替换为字符串 "ab"。
    // 否则，将其替换为字母表中的下一个字符。例如，'a' 替换为 'b'，'b' 替换为 'c'，依此类推。
    // 返回 恰好 执行 t 次转换后得到的字符串的 长度。
    int lengthAfterTransformations(string s, int t)
    {
        vector<mint> dp(26, mint(1));

        for (int i = 1; i <= t; ++i)
        {
            vector<mint> dp_curr(26, mint(0));
            for (int c = 0; c < 26; ++c)
            {
                if (c != 25)
                {
                    dp_curr[c] += dp[c + 1];
                }
                else
                {
                    dp_curr[c] += dp[0] + dp[1]; // 'a'和'b'
                }
            }
            dp = dp_curr;
        }

        mint result = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            result += dp[c];
        }
        return result.val();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> nums = {105, 11};
}
