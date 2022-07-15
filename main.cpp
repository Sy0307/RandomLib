#include "random.h"
#include <windows.h>
const int tiny_data = 40;
const int huge_data = 10;
using namespace std;

int seed = time(NULL);
void tiny_make(int n, int l)
{
   GetNumber gk(0, n - 1);
   auto k = gk.GetSingleNumber(0, n - 1);
   cout << l << endl;
   cout << k << endl;

   GetNumber gpos(1, l - 1);

   auto pos = gpos.GetUniqueNumberList(n - 1, 1, l - 1,seed+=10);
   pos.push_back(0);
   sort(pos.begin(), pos.end());
   StandardPrint(pos);
   int size = pos.size();

   GetNumber gtime(1, 10000);
   auto time = gtime.GetNumberList(size, 1, 100,seed+=10);
   //  cout<<size<<" "<<time.size()<<endl;
   StandardPrint(time);
}
void huge_make(int n, int l)
{
   GetNumber gk(0, n - 1);
   auto k = gk.GetSingleNumber(0, n - 1);
   cout << l << endl;
   cout << k << endl;

   GetNumber gpos(1, l - 1);
   auto pos = gpos.GetUniqueNumberList(n - 1, 1, l - 1,seed+=10);
   pos.push_back(0);
   sort(pos.begin(), pos.end());
   StandardPrint(pos);
   int size = pos.size();

   GetNumber gtime(1, 10000);
   auto time = gtime.GetNumberList(size, 1, 200,seed+=10);
   //  cout<<size<<" "<<time.size()<<endl;
   StandardPrint(time);
}
int main()
{
   System_Control sc;
 //  sc.clear();
   sc.AddCount();
   //    cout<<1<<endl;
   GetNumber ginc(10, 30);
   GetNumber gn(100, 10000);
   //  auto n = gn.GetSingleNumber();
   for (int i = 0; i < tiny_data; i++)
   {
      srand(seed);
      seed += 10;
      auto n = rand() % 200 + 10;
      auto l = rand() % 500 + 10;
      while(n>l)
      {
         n = rand() % 200 + 10;
         l = rand() % 500 + 10;
         seed+=10;
      }
      tiny_make(n, l);
      //   cout<<"Rank = "<<i<<endl;
      //   tiny_make(gn.GetSingleNumber(10,max(n,500)));
   }
   for (int i = 0; i < huge_data; i++)
   {
      srand(seed);
      seed += 10;
      auto n = rand() % 300 + 100;
      auto l = rand() % 9500 + 500;
      huge_make(n, l);
   }
}