#include "random.h"
#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
const int tiny_data = 40;
const int huge_data = 10;
using namespace std;

class Solution
{
public:
   using ll = long long;
   template <typename T>
   struct ST
   {
      ST(T Signal[], int n)
      {
         siz = n;
         maxv.resize(n + 1);
         minv.resize(n + 1);
         int t = __lg(n) + 1;
         for (int i = 0; i <= n; i++)
            maxv[i].resize(t), minv[i].resize(t);
         for (int i = 0; i <= n; i++)
            maxv[i][0] = minv[i][0] = Signal[i];
         for (int j = 1; j < t; j++)
         {
            for (int i = 0; i <= n - (1 << j) + 1; i++)
            {
               maxv[i][j] = max(maxv[i][j - 1], maxv[i + (1 << (j - 1))][j - 1]);
               minv[i][j] = min(minv[i][j - 1], minv[i + (1 << (j - 1))][j - 1]);
            }
         }
      }
      T getmax(int l, int r)
      {
         int k = __lg(r - l + 1);
         return max(maxv[l][k], maxv[r - (1 << k) + 1][k]);
      }
      T getmin(int l, int r)
      {
         int k = __lg(r - l + 1);
         return min(minv[l][k], minv[r - (1 << k) + 1][k]);
      }

   private:
      int siz = 0;
      vector<vector<T>> maxv, minv;
   };

   bool SignalOverload(vector<int> &Signal)
   {
      int n = Signal.size();
      vector<int> left(n + 1, 0), right(n + 1, n + 1);
      stack<array<ll, 2>> st;
      for (int i = 1; i <= n; i++)
      {
         while (!st.empty() && st.top()[1] < Signal[i - 1])
            right[st.top()[0]] = i, st.pop();
         st.push({i, Signal[i - 1]});
      }
      while (!st.empty())
         st.pop();

      for (int i = n; i >= 1; i--)
      {
         while (!st.empty() && st.top()[1] < Signal[i - 1])
            left[st.top()[0]] = i, st.pop();
         st.push({i, Signal[i - 1]});
      }

      ll pre[n + 1];
      pre[0] = 0;
      for (int i = 1; i <= n; i++)
      {
         pre[i] = pre[i - 1] + Signal[i - 1];
      }
      ST<ll> s(pre, n);
      for (int i = 1; i <= n; i++)
      {
         ll p1 = s.getmin(left[i], i - 1), p2 = s.getmax(i, right[i] - 1);
         if (p2 - p1 > Signal[i - 1])
         {
            return true;
         }
      }
      return false;
   }
};

void Print(vector<int> &data, vector<vector<int>> &data2)
{
   for (int i = 0; i < data.size(); i++)
   {
      cout << data[i] << endl;
      StandardPrint(data2[i]);
   }
}
vector<int> make()
{
   GetNumber gn(1, 1000);
   GetNumber glen(100, 1000);
   vector<int> reclen;
   vector<vector<int>> rec;
   int right_ans = 0;
   while (1)
   {
      auto len = glen.GetSingleNumber(-1, -1, 1);
      //   while (len <= 0)
      // {
      //    len = glen.GetSingleNumber(-1,-1,0.1);
      // }
      //   cout<<1<<endl;
      //   cout<<len<<endl;
      auto Signal = gn.GetNumberList(len, -1, -1, 0.05);

      return (Signal);
   }
}
int main()
{
   System_Control sc;
   sc.AddCount();
   GetNumber glen(30,50);
   for(int i=0;i<2;i++)
   {
      auto len = glen.GetSingleNumber();
      cout<<'[';
      for(int j=0;j<len;j++)
      {
         auto now = make();
         StandardPrint(now,0);
         if(j!=len-1)
         {
            cout<<',';
         }
      }
      cout<<']'<<endl;

   }
}
