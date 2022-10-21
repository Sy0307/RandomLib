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
using namespace std;

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
    void receive(std::vector<char> &&v);
    GetString()
    {
        use.clear();
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            use.push_back(c);
        }
    }
    //  void StandardPrint(){}

private:
    std::vector<char> use;
    int len;
};

class GetNumber
{
public:
    Tp std::vector<T> Get_Number_List(int len, int l, int r, double per = 1);
    long long Get_Single_Number(ll l = -1, ll r = -1, double per = 1.0);
    double Get_Single_Number(double l = -1, double r = -1, double per = 1.0);
    int Get_Single_Number(int l = -1, int r = -1, double per = 1.0);
    // double Get_Single_Double(int l = -1, int r = -1, double per = 1.0);
    vector<int> Get_Unique_Number_List(int len, int l = -1, int r = -1);
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
    Tp bool check(std::vector<T> &ans);
    int rangelow;
    int rangehigh;
    int len;
    WinRandom rnd;
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

// Tp std::vector<T> Input(int length);

// Tp void LCStandardPrint(std::vector<T> &data, bool space_allow = 1);

// definition

string GetString::Get_Balance_String(int len = 40,
                                     int t = 30)
{
    int n = use.size();
    WinRandom rnd;
    std::string ans = "";
    for (int i = 0; i < len; i++)
    {
        int x = rnd.randUnsigned() % n;
        ans += use[x];
    }
    // map<char, int> mp;
    // std::vector<int> analysis(n);
    // for (int i = 0; i < len; i++)
    // {
    //     mp[ans[i]]++;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     analysis[i] = mp[use[i]];
    // }
    // if (Variance(analysis) < t)
    // {
    //     return Get_Balance_String(len, t);
    // }
    return ans;
}

Tp void GetString::print()
{
    for (auto i : use)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
void GetString::print(std::string s)
{
    std::cout << s << "\n";
}
void GetString::receive(std::vector<char> &&v)
{
    //    len = n;
    //    use.resize(n);
    use.clear();
    for (auto &k : v)
    {
        GetString::use.push_back(k);
    }
}

// to fix bugs

int GetNumber::Get_Single_Number(int l, int r, double per)
{

    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    };
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
long long GetNumber::Get_Single_Number(ll l, ll r, double per)
{
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    };
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
double GetNumber::Get_Single_Number(double l, double r, double per)
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
        ans[i] = Get_Single_Number(l, r, per);
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
//     std::cout << "\"" << s << "\"" << "\n";
// }

std::vector<int> GetNumber::Get_Unique_Number_List(int len, int l, int r)
{
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }
    // if (r - l + 1 < len)
    // {
    //     assert(0);
    // }
    std::vector<int> temp;
    map<int, int> mp;
    mp.clear();
    for (int i = 0; i < len; ++i)
    {
        int t = Get_Single_Number(l, r) + rand();
        while (mp[t] != 0 || t < l || t > r)
        {
            t = Get_Single_Number(l, r) + rand();
        }
        mp[t]++;
        temp.push_back(t);
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
    std::cout << n + 1 << "\n";
    fclose(stdout);
    //   std::cout<<1<<"\n";
    auto path = "Data\\Data" + to_string(n + 1) + ".txt";
    //  std::cout<<1<<"\n";
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
    std::cout << "[";
    for (int i = 0; i < data.size(); i++)
    {
        auto d = data[i];
        if (i != data.size() - 1)
            std::cout << d << ",";
        else
            std::cout << d;
    }
    std::cout << "]";
    if (space_allow)
        std::cout << "\n";
}

Tp void Standard_Print(vector<T> &data, bool space_allow = 1)
{
    //标准输出
    for (int i = 0; i < (int)data.size(); i++)
    {
        int d = data[i];
        if (i != data.size() - 1)
            cout << d << " ";
        else
            cout << d;
    }
    if (space_allow)
        std::cout << "\n";
}

void String_Print(string str, bool space_allow = 1)
{
    //标准输出
    cout << str;
    if (space_allow)
        std::cout << "\n";
}
