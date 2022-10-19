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
    Tp vector<T> GetNumberList(int len, int l, int r, double per = 1);
    Tp bool check(vector<T> &ans);
    long long GetSingleNumber(int l = -1, int r = -1, double sign = 1.0);
    double GetSingleDouble(int l = -1, int r = -1, double sign = 1.0);
    Tp vector<T> GetUniqueNumberList(int len, int l = -1, int r = -1);
    GetNumber(int a, int b, int c = 0)
    {
        rangehigh = b;
        rangelow = a;
        len = c;
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
        GetCount();
        AddCount();
    }

private:
    int GetCount();
    void AddCount();
};

// extra content
//  Tp void StandardPrint(vector<T>);

double Variance(vector<int> &data);

Tp vector<T> Input(int length);

Tp void LCStandardPrint(vector<T> &data, bool space_allow = 1);

Tp void StandardPrint(T, bool space_allow = 1);

Tp void StandardPrint(vector<T> &data, bool space_allow = 1);