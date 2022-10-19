#include "./scripts/random.h"
#include <iostream>
#include <bits/stdc++.h>
const int tiny_data = 60;
const int mid_data = 40;
const int huge_data = 40;

using namespace std;

int main()
{
    System_Control sc;
    GetNumber gn1(1,5);
    gn1.GetUniqueNumberList<int>(5);
    // for (auto i : n)
    // {
    //     cout << i << endl;
    // }
    // cout << "----------------" << endl;
    // sort(n.begin(), n.end());
    // for (auto i : n)
    // {
    //     cout << i << endl;
    // }
    // for (int i = 0; i < mid_data; i++)
    // {
    //     auto n = gn2.GetSingleNumber();
    //     cout << n << endl;
    // }
    // for (int i = 0; i < huge_data; i++)
    // {
    //     auto n = gn3.GetSingleNumber();
    //     cout << n << endl;
    // }
}