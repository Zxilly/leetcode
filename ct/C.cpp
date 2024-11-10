#include <bits/stdc++.h>
using namespace std;
#ifdef LC_LOCAL
#include "leetcode/parser.hpp"
#else
#define dbg(...)
#endif
#ifdef LC_LOCAL

using ll = long long;

template <typename T>
class modular
{
    static constexpr auto mod() { return T::value; }
    static constexpr auto norm(integral auto x)
    {
        if (!(-mod() <= x && x < mod()))
            x %= mod();
        if (x < 0)
            x += mod();
        return x;
    }
    int x;

public:
    modular() : x() {}
    modular(const auto &x) : x(norm(x)) {}
    explicit operator auto() const { return x; }
    auto operator()() const { return x; }
    auto operator^(integral auto rhs) const
    {
        modular a = *this, res = 1;
        for (; rhs; rhs >>= 1, a *= a)
            if (rhs & 1)
                res *= a;
        return res;
    }
    auto operator~() const { return *this ^ (mod() - 2); }
    auto operator<=>(const modular &rhs) const = default;
    auto operator-() const { return modular(-x); }
    auto &operator+=(const modular &rhs)
    {
        if ((x += rhs.x) >= mod())
            x -= mod();
        return *this;
    }
    auto &operator-=(const modular &rhs)
    {
        if ((x -= rhs.x) < 0)
            x += mod();
        return *this;
    }
    auto &operator*=(const modular &rhs) { return *this = (ll)x * rhs.x; }
    auto &operator/=(const modular &rhs) { return *this *= (~rhs); }
    friend auto operator+(modular lhs, const modular &rhs) { return lhs += rhs; }
    friend auto operator-(modular lhs, const modular &rhs) { return lhs -= rhs; }
    friend auto operator*(modular lhs, const modular &rhs) { return lhs *= rhs; }
    friend auto operator/(modular lhs, const modular &rhs) { return lhs /= rhs; }
    friend auto &operator>>(istream &is, modular &rhs)
    {
        is >> rhs.x;
        rhs.x = norm(rhs.x);
        return is;
    }
    friend auto &operator<<(ostream &os, const modular &rhs) { return os << rhs.x; }
};
template <typename T>
struct std::formatter<modular<T>> : formatter<string>
{
    auto format(const modular<T> &m, format_context &ctx) const
    {
        return format_to(ctx.out(), "{}", m());
    }
};

constexpr int mod = 1e9 + 7;
using mint = modular<integral_constant<int, mod>>;

class Solution
{
public:
    // 给你一个整数数组 nums。好子序列 的定义是：子序列中任意 两个 连续元素的绝对差 恰好 为 1。
    // 子序列 是指可以通过删除某个数组的部分元素（或不删除）得到的数组，并且不改变剩余元素的顺序。
    // 返回 nums 中所有 可能存在的 好子序列的 元素之和。
    // 因为答案可能非常大，返回结果需要对 109 + 7 取余。
    // 注意，长度为 1 的子序列默认为好子序列。
    int sumOfGoodSubsequences(vector<int> &nums)
    {
        map<int, pair<mint, mint>> dp;
        mint ans = 0;

        for (auto num : nums)
        {
            mint c1 = dp.contains(num - 1) ? dp[num - 1].first : 0;
            mint s1 = dp.contains(num - 1) ? dp[num - 1].second : 0;
            mint c2 = dp.contains(num + 1) ? dp[num + 1].first : 0;
            mint s2 = dp.contains(num + 1) ? dp[num + 1].second : 0;

            mint new_count = c1 + c2 + 1;
            mint new_sum = s1 + s2 + num * (c1 + c2) + num;

            dp[num].first += new_count;
            dp[num].second += new_sum;
            ans += new_sum;
        }

        return ans();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // exec(&Solution::addTwoNumbers); // CHANGE FOR PROBLEM
}
#endif
