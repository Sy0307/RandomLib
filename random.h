// Author =  Sy03
//  C++ standard  = C++20
//  Recommand compiler = g++

#include <bits/stdc++.h>
#define Tp template <typename T>
using ll = long long;
using namespace std;

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
    vector<int> GetNumberList(int, int, int);
    Tp bool check(vector<T> &ans);
    int GetSingleNumber(int l, int r);
    GetNumber(int a, int b)
    {
        rangehigh = b;
        rangelow = a;
    }

private:
    int rangelow;
    int rangehigh;
    int len;
};

// Tp void StandardPrint(vector<T>);

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

Tp void StandardPrint(T);

void StringOutPut(string s);