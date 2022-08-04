// Author =  Sy03
//  C++ standard  = C++20
//  Recommand compiler = g++

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
    string GetBalanceString(int len,
                            int t);

    Tp void print();
    void print(string s);
    void receive(vector<char>);
    //  void StandardPrint(){}

private:
    vector<char> use;
    int len;
};

class GetNumber
{
public:
    vector<int> GetNumberList(int len, int l, int r, double per = 1);
    Tp bool check(vector<T> &ans);
    int GetSingleNumber(int l = -1, int r = -1, double sign = 1.0);
    vector<int> GetUniqueNumberList(int len, int l, int r);
    GetNumber(int a, int b, int c = 0)
    {
        rangehigh = b;
        rangelow = a;
        len = c;
    }
    int rangelow;
    int rangehigh;
    int len;
};

class System_Control
{
public:
    int GetCount();
    void AddCount();
};

// extra content
//  Tp void StandardPrint(vector<T>);

double Variance(vector<int> &data);

Tp vector<T> Input(int length)
{
    vector<T> ans;
    for (int i = 0; i < length; i++)
    {
        T x;
        cin >> x;
        ans.push_back(x);
    }
    return ans;
}

Tp void StandardPrint(vector<T> &data , bool f = 1)
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
    cout << "]" ;
    if(f)
        cout << endl;
}

void StringOutPut(string s);
