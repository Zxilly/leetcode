#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#else
#define dbg(...)
#endif
#ifdef LC_LOCAL

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
    vector<int> yzs(int n, int mx)
    {
        vector<int> divisors;
        for (int d = 1; d <= sqrt(n); ++d)
        {
            if (n % d == 0)
            {
                if (d <= mx)
                    divisors.emplace_back(d);
                if (n / d != d && n / d <= mx)
                    divisors.emplace_back(n / d);
            }
        }
        return divisors;
    }

    // 给你一个整数数组 nums。
    // 请你统计所有满足一下条件的 非空 子序列对 (seq1, seq2) 的数量：
    // 子序列 seq1 和 seq2 不相交，意味着 nums 中 不存在 同时出现在两个序列中的下标。
    // seq1 元素的 GCD 等于 seq2 元素的 GCD。
    // 返回满足条件的子序列对的总数。
    // 由于答案可能非常大，请返回其对 10^9 + 7 取余 的结果。
    // gcd(a, b) 表示 a 和 b 的 最大公约数。
    // 子序列 是指可以从另一个数组中删除某些或不删除元素得到的数组，并且删除操作不改变其余元素的顺序。
    int subsequencePairCount(vector<int> &nums)
    {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1, 0);
        for (auto&& num : nums)
        {
            for (auto&& d : yzs(num, mx))
            {
                cnt[d]++;
            }
        }

        vector<mint> cntsq(mx + 1, 1);
        for (int i = 1; i <= mx; ++i)
        {
            cntsq[i] = cntsq[i - 1] * 2;
        }

        vector<mint> f(mx + 1, 0);
        for (int d = mx; d >= 1; --d)
        {
            f[d] = cntsq[cnt[d]] - mint(1);
            for (int m = 2 * d; m <= mx; m += d)
            {
                f[d] = f[d] - f[m];
            }
        }

        vector<mint> g(mx + 1, 0);
        for (int d = mx; d >= 1; --d)
        {
            g[d] = f[d] * f[d];
            for (int m = 2 * d; m <= mx; m += d)
            {
                g[d] = g[d] - g[m];
            }
        }

        mint ans = 0;
        for (int d = 1; d <= mx; ++d)
        {
            ans = ans + g[d];
        }
        return ans.val();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // exec(&Solution::addTwoNumbers); // CHANGE FOR PROBLEM
}
#endif
