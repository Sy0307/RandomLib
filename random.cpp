#include "random.h"

class GetString
{
public:
    template <typename T>
    double Variance(vector<T> &data)
    {
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

    string GetBalanceString(vector<char> use, int len = 50,
                            int t = 30)
    {
        int n = use.size();
        default_random_engine en{time(nullptr) % 1000};
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
            return GetBalanceString(use, len, t);
        }
        return ans;
    }

    Tp void print(vector<T> &a)
    {
        for (auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void print(string s)
    {
        cout << s << endl;
    }
    Tp void recive(int n)
    {
        len = n;
        use.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> use[i];
        }
    }

private:
    vector<char> use;
    int len;
};

class GetNumber
{
public:
    Tp
        vector<T>
        GetNumberList(int len = -1, int l = -1, int r = -1)
    {
        auto ans = vector<T>();
        if (len == -1)
            len = GetNumber::len;
        ans.resize(len);
        if (l == -1)
        {
            l = rangelow;
        }
        if (r == -1)
        {
            r = rangehigh;
        }

        default_random_engine en{time(nullptr) % 1000};
        uniform_int_distribution dis(l, r);
        for (int i = 0; i < len; i++)
        {
            ans[i] = dis(en);
        }

        if (!check(ans))
            return GetNumberList(len, l, r);
        return ans;
    }
    Tp bool check(vector<T> &ans,int limit = -1)
    {
        if(limit ==-1)
        {
            limit = pow((rangehigh - rangelow),1.5); 
        }
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
        return Variance(test)<=limit;
    }
    int GetSingleNumber(int l = -1, int r = -1)
    {
        if (l == -1)
        {
            l = rangelow;
        }
        if (r == -1)
        {
            r = rangehigh;
        }
        default_random_engine en{time(nullptr) % 1000};
        uniform_int_distribution<int> dis(l, r);
        return dis(en);
    }
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

Tp void StandardPrint(vector<T> &data)
{
    //标准LC Json输入
    cout << "[" << endl;
    for (auto &d : data)
    {
        cout << d << ",";
    }
    cout << "]";
}

Tp double Variance(vector<T> &data)
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
