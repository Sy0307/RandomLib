// Author =  Sy03
//  C++ standard  = C++20
//  Recommend compiler = g++
#pragma once
#include <vector>
#include <assert.h>
#include <windows.h>
#include <wincrypt.h>
#include <string>
#include <map>
#include <iostream>
#include <random>
#include <algorithm>
#define Tp template <typename T>
using ll = long long;

class WinRandom
{
    HCRYPTPROV handle;

public:
    WinRandom()
    {
        handle = NULL;
        CryptAcquireContext(
            (HCRYPTPROV *)&handle, NULL, NULL,
            PROV_RSA_FULL, 0);
    }
    ~WinRandom()
    {
        if (handle != NULL)
            CryptReleaseContext(handle, 0);
    }
    bool randBuf(void *dest, int len)
    {
        if (handle == NULL)
            return false;
        return CryptGenRandom(handle, len, (BYTE *)dest);
    }
#define _(func, typ)                                \
    typ func()                                      \
    {                                               \
        typ ret = 0;                                \
        assert(randBuf((void *)&ret, sizeof(ret))); \
        return ret;                                 \
    }
    _(randInt, int)
    _(randLong, long long)
    _(randUnsigned, unsigned)
    _(randUnsignedLong, unsigned long long)
    _(randShort, short)
    _(randUnsignedShort, unsigned short)
    _(randChar, char)
    _(randUnsignedChar, unsigned char)
    _(randSignedChar, signed char)
};

class GetString
{
public:
    std::string Get_Balance_String(int len,
                                   int t);

    Tp void print();
    void print(std::string s);
    void receive(std::vector<char>);
    //  void StandardPrint(){}

private:
    std::vector<char> use;
    int len;
};

class GetNumber
{
public:
    Tp std::vector<T> Get_Number_List(int len, int l, int r, double per = 1);
    Tp bool check(std::vector<T> &ans);
    long long GetSingleNumber(ll l = -1, ll r = -1, double sign = 1.0);
    double GetSingleNumber(double l = -1, double r = -1, double sign = 1.0);
    int GetSingleNumber(int l = -1, int r = -1, double sign = 1.0);
    double GetSingleDouble(int l = -1, int r = -1, double sign = 1.0);
    Tp std::vector<T> GetUniqueNumberList(int len, int l = -1, int r = -1);
    GetNumber(int _rangelow, int _rangehigh, int _len = 0)
    {
        rangehigh = _rangehigh;
        rangelow = _rangelow;
        len = _len;
    }
    GetNumber()
    {
    }

private:
    int rangelow;
    int rangehigh;
    int len;
};

class System_Control
{
public:
    System_Control()
    {
        // GetCount();
        AddCount();
    }
    int GetCount();
    void AddCount();

private:
};

// extra content

double Variance(std::vector<int> &data);

Tp std::vector<T> Input(int length);

Tp void LCStandardPrint(std::vector<T> &data, bool space_allow = 1);

Tp void StandardPrint(T, bool space_allow = 1);

Tp void StandardPrint(std::vector<T> data, bool space_allow);

// definition

std::string GetString::Get_Balance_String(int len = 40,
                                          int t = 30)
{
    int n = this->use.size();
    random_device rd;
    default_random_engine en((time(0)));
    uniform_int_distribution<int> dis(0, n - 1);
    std::string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += use[dis(en)];
    }
    map<char, int> mp;
    std::vector<int> analysis(n);
    for (int i = 0; i < len; i++)
    {
        mp[ans[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        analysis[i] = mp[use[i]];
    }
    if (Variance(analysis) < t)
    {
        return Get_Balance_String(len, t);
    }
    return ans;
}

Tp void GetString::print()
{
    for (auto i : use)
    {
        cout << i << " ";
    }
    cout << endl;
}
void GetString::print(std::string s)
{
    cout << s << endl;
}
void GetString::receive(std::vector<char> t)
{
    //    len = n;
    //    use.resize(n);
    this->use.clear();
    for (auto &k : t)
    {
        GetString::use.push_back(k);
    }
}

// to fix bugs
ll GetNumber::GetSingleNumber(ll l, ll r, double per)
{
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }
    WinRandom rnd;
    ll ans = abs(rnd.randLong());

    ans = ans % (r - l + 1) + l;
    int percent = rnd.randUnsigned() % (10000 - 1) + 1;
    if (percent < per * 10000)
    {
        return abs(ans);
    }
    return -abs(ans);
    //   return sign==1?ans:abs(ans);
}
double GetNumber::GetSingleNumber(double l, double r, double per)
{
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }
    WinRandom rnd;
    double ans = abs(rnd.randInt());
    int bias = abs(rnd.randInt() % 8 + 4);
    ans = ans / pow(10, bias);
    int percent = rnd.randUnsigned() % (10000 - 1) + 1;
    if (percent < per * 10000)
    {
        return abs(ans);
    }
    return -abs(ans);
    //   return sign==1?ans:abs(ans);
}
Tp std::vector<T> GetNumber::Get_Number_List(int len, int l, int r, double per) // per = 负数几率
{
    if (len == -1)
        len = GetNumber::len;
    std::vector<T> ans(len);
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }
    for (int i = 0; i < len; i++)
    {
        ans[i] = GetSingleNumber(l, r, per);
        // fix bugs
        // ans[i] = 1;
    }

    // if (!check(ans))
    //     return Get_Number_List(len, l, r);

    // not check variance now
    //  return ans;
    return ans;
}

// ban for now ,but maybe reused in next version
// Tp bool GetNumber::check(std::vector<T> &ans)
// {
//     int limit = pow((rangehigh - rangelow), 3);
//     int n = ans.size();
//     map<int, int> vis;
//     for (auto &now : ans)
//     {
//         vis[now]++;
//     }
//     ll tot = 0;
//     std::vector<T> test;
//     for (auto &now : vis)
//     {
//         test.push_back(now.second);
//     }
//     return Variance(test) <= limit;
// }

double Variance(std::vector<int> &data)
{
    // 计算方差
    double sum = 0;
    for (auto &d : data)
    {
        sum += d;
    }
    double mean = sum / data.size();
    double variance = 0;
    for (auto &d : data)
    {
        variance += (d - mean) * (d - mean);
    }
    return variance / data.size();
}

// void std::stringOutPut(std::string s)
// {
//     cout << "\"" << s << "\"" << endl;
// }

Tp std::vector<T> GetNumber::GetUniqueNumberList(int len, int l, int r)
{
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }
    std::vector<int> temp;
    map<int, int> mp;
    mp.clear();
    if (is_same<T, long long>::value)
    { // is_same<T, int>::value ||
        for (int i = 0; i < len; ++i)
        {
            int t = GetSingleNumber(l, r) + rand();
            while (mp[t] != 0 || t < l || t > r)
            {
                t = GetSingleNumber(l, r) + rand();
            }
            mp[t]++;
            temp.push_back(t);
        }
    }
    random_shuffle(temp.begin(), temp.end());
    std::vector<int> ans(len);
    for (int i = 0; i < len; i++)
    {
        ans[i] = temp[i];
    }
    return ans;
}

void System_Control::AddCount()
{
    freopen("DATA\\count.txt", "r", stdin);
    int n;
    cin >> n;
    fclose(stdin);
    freopen("DATA\\count.txt", "w", stdout);
    cout << n + 1 << endl;
    fclose(stdout);
    //   cout<<1<<endl;
    auto path = "Data\\Data" + to_string(n + 1) + ".txt";
    //  cout<<1<<endl;
    freopen(path.c_str(), "w", stdout);
}

int System_Control::GetCount()
{
    freopen("count", "r", stdin);
    int n;
    cin >> n;
    fclose(stdin);
    return n;
}

Tp void StandardPrint(T x, bool space_allow)
{
    cout << x;
    if (space_allow)
        cout << "\n";
}

Tp std::vector<T> Input(int length)
{
    std::vector<T> ans;
    for (int i = 0; i < length; i++)
    {
        T x;
        cin >> x;
        ans.push_back(x);
    }
    return ans;
}

Tp void LCStandardPrint(std::vector<T> &data, bool space_allow)
{
    //标准LC Json输入
    cout << "[";
    for (int i = 0; i < data.size(); i++)
    {
        auto d = data[i];
        if (i != data.size() - 1)
            cout << d << ",";
        else
            cout << d;
    }
    cout << "]";
    if (space_allow)
        cout << endl;
}

Tp void StandardPrint(std::vector<T> &data, bool space_allow)
{
    //标准输出
    for (int i = 0; i < data.size(); i++)
    {
        auto d = data[i];
        if (i != data.size() - 1)
            cout << d << " ";
        else
            cout << d;
    }
    if (space_allow)
        cout << endl;
}

Tp void StandardPrint(T x, bool space_allow)
{
    cout << x;
    if (space_allow)
        cout << endl;
}
