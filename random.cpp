#include "random.h"



string GetString::GetBalanceString(int len =40,
                                   int t =30)
{
    int n = use.size();
    random_device rd;
    default_random_engine en{rd()};
    uniform_int_distribution<int> dis(0, n - 1);
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        ans += use[dis(en)];
    }
    map<char, int> mp;
    vector<int> analysis(n);
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
        return GetBalanceString(len, t);
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
void GetString::print(string s)
{
    cout << s << endl;
}
void GetString::receive(vector<char> t)
{
    //    len = n;
//    use.resize(n);
    GetString::use.clear();
    for(auto &k:t)
    {
        GetString::use.push_back(k);
    }
}

vector<int> GetNumber::GetNumberList(int len = -1, int l = -1, int r = -1)
{
    if (len == -1)
        len = GetNumber::len;
    vector<int> ans(len);
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }

    random_device rd;
    default_random_engine en{rd()};
    uniform_int_distribution<int> dis(l + 1, r - 1);
    for (int i = 0; i < len; i++)
    {
        ans[i] = dis(en);
    }

    if (!check(ans))
        return GetNumberList(len, l, r);
    return ans;
}
Tp bool GetNumber::check(vector<T> &ans)
{
    int limit = pow((rangehigh - rangelow), 1.5);
    int n = ans.size();
    map<int, int> vis;
    for (auto &now : ans)
    {
        vis[now]++;
    }
    ll tot = 0;
    vector<T> test;
    for (auto &now : vis)
    {
        test.push_back(now.second);
    }
    return Variance(test) <= limit;
}
int GetNumber::GetSingleNumber(int l = -1, int r = -1)
{
    if (l == -1)
    {
        l = rangelow;
    }
    if (r == -1)
    {
        r = rangehigh;
    }
    random_device rd;
    default_random_engine en{rd()};
    uniform_int_distribution<int> dis(l, r);
    return dis(en);
}

double Variance(vector<int> &data)
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

Tp void StandardPrint(vector<T>& data)
{
    //标准LC Json输入
    cout << "[" << endl;
    for (auto &d : data)
    {
        cout << d << ",";
    }
    cout << "]";
}




void StringOutPut(string s)
{
    cout<<"\""<<s<<"\""<<endl;
}
