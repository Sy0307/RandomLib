#include "random.h"
#include <bits/stdc++.h>
#include <windows.h>
const int tiny_data = 20;
const int huge_data = 30;
using namespace std;

const int mod = 1e9 + 7;
class Solution
{
public:
    using ll = long long;
    using pii = pair<int, int>;
    ll n;
    ll dp[555][555];

    template <int T>
    struct ModInt
    {
        const static int MD = T;
        int x;
        ModInt(ll x = 0) : x(x % MD) {}
        int get() { return x; }
        ModInt operator+(const ModInt &that) const
        {
            int x0 = x + that.x;
            return ModInt(x0 < MD ? x0 : x0 - MD);
        }
        ModInt operator-(const ModInt &that) const
        {
            int x0 = x - that.x;
            return ModInt(x0 < MD ? x0 + MD : x0);
        }
        ModInt operator*(const ModInt &that) const { return ModInt((long long)x * that.x % MD); }
        ModInt operator/(const ModInt &that) const { return *this * that.inverse(); }
        void operator+=(const ModInt &that)
        {
            x += that.x;
            if (x >= MD)
                x -= MD;
        }
        void operator-=(const ModInt &that)
        {
            x -= that.x;
            if (x < 0)
                x += MD;
        }
        void operator*=(const ModInt &that) { x = (long long)x * that.x % MD; }
        void operator/=(const ModInt &that) { *this = *this / that; }
        ModInt inverse() const
        {
            int Dolls = x, b = MD, u = 1, v = 0;
            while (b)
            {
                int t = Dolls / b;
                Dolls -= t * b;
                std::swap(Dolls, b);
                u -= t * v;
                std::swap(u, v);
            }
            if (u < 0)
                u += MD;
            return u;
        }
    };
    typedef ModInt<mod> mint;
    mint mm;
    ll dfs(int L, int R, vector<int> &Dolls)
    {
        if ((R - L + 1) % 2)
            return 0;
        if (L > R)
            return 1;
        if (dp[L][R] != -1)
            return dp[L][R];
        mint res = 0;
        if (Dolls[L] == 0)
        {
            for (int i = L + 1; i <= R; i += 2)
            {
                if (Dolls[i] == 0)
                {
                    res += mm * dfs(i + 1, R, Dolls) * dfs(L + 1, i - 1, Dolls);
                }
                else if (Dolls[i] < 0)
                {
                    res += dfs(i + 1, R, Dolls) * dfs(L + 1, i - 1, Dolls);
                }
            }
        }
        else if (Dolls[L] > 0)
        {
            for (int i = L + 1; i <= R; i += 2)
            {
                if (Dolls[i] == 0)
                {
                    res += dfs(i + 1, R, Dolls) * dfs(L + 1, i - 1, Dolls);
                }
                else if (Dolls[i] == -Dolls[L])
                {
                    res += dfs(i + 1, R, Dolls) * dfs(L + 1, i - 1, Dolls);
                }
            }
        }
        return dp[L][R] = res.get();
    }
    int DollsSequence(int n, int m, vector<int> &Dolls)
    {
        mm = m;
        this->n = n;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = -1;
        return dfs(0, n - 1, Dolls);
    }
};

bool obey(int m, int x)
{
    if (abs(x) <= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Solution s;
vector<int> make(int maxn, int maxm)
{
    GetNumber gn(1, maxn);
    GetNumber gm(5, maxm);
    vector<int> ans;
    int n = gn.GetSingleNumber();
    int m = gm.GetSingleNumber();
    for (int i = 0; i < n; i++)
    {
        auto x = gn.GetSingleNumber(1, m, 0.7);
        while (!obey(m, x) || (i < n / 4 && x < 0))
        {
            x = gn.GetSingleNumber(1, m, 0.7);
        }
        ans.push_back(x);
    }
    auto list = gn.GetNumberList(n, -1, -1, 0.2);
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] < 0)
        {
            ans[i] = 0;
        }
    }
    if (s.DollsSequence(n, m, ans) == 0)
    {
        return make(maxn, maxm);
    }
    else
    {
        cout << n << endl;
        cout << m << endl;
        StandardPrint(ans);
    }
    return ans;
}
int main()
{
    System_Control sc;
    sc.AddCount();
    for (int i = 0; i < tiny_data; i++)
    {
        make(200, 100);
    }
    for (int i = 0; i < huge_data; i++)
    {
        make(500, 500000);
    }
}
