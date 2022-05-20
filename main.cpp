#include "random.h"
const int tiny_data = 100;
const int huge_data = 50;
int n;

int main()
{
   freopen("data.txt", "w", stdout);
   ios::sync_with_stdio(false);
   GetString gs;
   GetNumber gn(20, 200);
 //  cin >> n;
   vector<char> charuse = {'A','B'};
   gs.receive(charuse);

   auto tmp = gn.GetNumberList(tiny_data, 20, 100);
   // 小数据 长度
   for (int i = 0; i < tiny_data; i++)
   {

      int len = tmp[i];
      //    cout<<len<<endl;
      StringOutPut(gs.GetBalanceString(len, 30));
   }

   tmp = gn.GetNumberList(huge_data, 2000, 200000);
   for (int i = 0;i<huge_data;i++)
   {
      int len = tmp[i];
      StringOutPut(gs.GetBalanceString(len, 30));
   }
}