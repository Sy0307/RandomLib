#include "random.h"

using namespace std;
// string GetString::GetBalanceString(int len = 40,
//                                    int t = 30)
// {
//     int n = use.size();
//     random_device rd;
//     default_random_engine en((time(0)));
//     uniform_int_distribution<int> dis(0, n - 1);
//     string ans = "";
//     for (int i = 0; i < len; i++)
//     {
//         ans += use[dis(en)];
//     }
//     map<char, int> mp;
//     vector<int> analysis(n);
//     for (int i = 0; i < len; i++)
//     {
//         mp[ans[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         analysis[i] = mp[use[i]];
//     }
//     if (Variance(analysis) < t)
//     {
//         return GetBalanceString(len, t);
//     }
//     return ans;
// }

// Tp void GetString::print()
// {
//     for (auto i : use)
//     {
//         cout << i << " ";
//     }
//     cout << endl;
// }
// void GetString::print(string s)
// {
//     cout << s << endl;
// }
// void GetString::receive(vector<char> t)
// {
//     //    len = n;
//     //    use.resize(n);
//     GetString::use.clear();
//     for (auto &k : t)
//     {
//         GetString::use.push_back(k);
//     }
// }

// to fix bugs
int GetNumber::GetSingleNumber(int l, int r, double per)
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
    int ans = abs(rnd.randInt());

    ans = ans % (r - l + 1) + l;
    int percent = rnd.randUnsigned() % (10000 - 1) + 1;
    if (percent < per * 10000)
    {
        return abs(ans);
    }
    return -abs(ans);
    //   return sign==1?ans:abs(ans);
}
vector<int> GetNumber::GetNumberList(int len, int l, int r, double per) //per = 负数几率
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
    for (int i = 0; i < len; i++)
    {
        ans[i] = GetSingleNumber(l, r, per);
    }

    // if (!check(ans))
    //     return GetNumberList(len, l, r);

    // not check variance now
    return ans;
}
Tp bool GetNumber::check(vector<T> &ans)
{
    int limit = pow((rangehigh - rangelow), 3);
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

// Tp void StandardPrint(vector<T> &data)
// {
//     //标准LC Json输入
//     cout << "[" << endl;
//     for (auto &d : data)
//     {
//         cout << d << ",";
//     }
//     cout << "]";
// }

void StringOutPut(string s)
{
    cout << "\"" << s << "\"" << endl;
}

vector<int> GetNumber::GetUniqueNumberList(int len, int l, int r)
{

    vector<int> temp;
    map<int, int> mp;
    mp.clear();
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
    random_shuffle(temp.begin(), temp.end());
    vector<int> ans(len);
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
