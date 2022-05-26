#include "random.h"
const int tiny_data = 40;
const int huge_data = 10;
using namespace std;

map<int, int> recordK;
class Solution
{
public:
   int ShinyGem(int k, vector<int> &s)
   {
      int n = s.size();
      map<int, int> mp;
      for (int i = 0; i < n; i++)
      {
         mp[s[i]]++;
      }
      int tmp = k, mex;
      for (int i = 0;; i++)
      {
         if (!mp.count(i))
         {
            if (tmp)
            {
               tmp--;
            }
            else
            {
               mex = i;
               break;
            }
         }
      }
      set<pair<int, int>> sp;
      for (auto &[x, y] : mp)
      {
         if (x > mex)
         {
            sp.insert({y, x});
         }
      }

      while (sp.size() && k >= sp.begin()->first)
      {
         k -= sp.begin()->first;
         sp.erase(sp.begin());
      }
      return -sp.size();
   }
};

void tiny_make()
{
   GetNumber Gn(20, 2 * 100000 - 1);
   auto n = Gn.GetSingleNumber();
   GetNumber gk(10, n);
   auto k = gk.GetSingleNumber(1, 100);
   // cout << k << endl;
   int size = gk.GetSingleNumber(10, 20);
   vector<int> tot(0);
   while (size--)
   {
      int tmp = gk.GetSingleNumber(20, 50);
      auto kk = Gn.GetNumberList(tmp, 0, 200);
      tot.insert(tot.end(), kk.begin(), kk.end());
   }
   Solution s;
   if (s.ShinyGem(k, tot) == 0 || recordK[k])
   {
      tiny_make();
      return;
   }
   else
   {
      recordK[k]++;
      cout << k << endl;
      StandardPrint(tot);
   }
}

void huge_make()
{
   GetNumber Gn(20, 2 * 100000 - 1);
   auto n = Gn.GetSingleNumber();
   GetNumber gk(10, n);
   auto k = gk.GetSingleNumber(20, 1000);
   //  cout << k << endl;
   int size = gk.GetSingleNumber(20, 100);
   vector<int> tot(0);
   while (size--)
   {
      int tmp = gk.GetSingleNumber(100, 200);
      auto kk = Gn.GetNumberList(tmp, 0, 1000);
      tot.insert(tot.end(), kk.begin(), kk.end());
   }
 //  StandardPrint(tot);
   Solution s;
   if (s.ShinyGem(k, tot) == 0 || recordK[k])
   {
      huge_make();
      return;
   }
   else
   {
      recordK[k]++;
      cout << k << endl;
      StandardPrint(tot);
   }
}

int main()
{
   freopen("data2.txt", "w", stdout);
   //    cout<<1<<endl;
   GetNumber Gn(20, 2 * 100000 - 1);
   auto n = Gn.GetSingleNumber();
   GetNumber gk(10, n);

   for (int i = 0; i < tiny_data; i++)
   {
      tiny_make();
   }
   recordK.clear();
   for (int i = 0; i < huge_data; i++)
   {
      huge_make();
   }
}