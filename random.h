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
    vector<int> GetNumberList(int len, int l, int r, int &seed);
    Tp bool check(vector<T> &ans);
    int GetSingleNumber(int l = -1, int r = -1,int len = 0);
    vector<int> GetUniqueNumberList(int len, int l, int r, int &seed);
    GetNumber(int a, int b,int c = 0)
    {
        rangehigh = b;
        rangelow = a;
        len = c;
    }
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

Tp void StandardPrint(vector<T> &data)
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
    cout << "]" << endl;
}

void StringOutPut(string s);