#include "random.h"
#include <iostream>
#include <bits/stdc++.h>
const int tiny_data = 60;
const int mid_data = 40;
const int huge_data = 40;

using namespace std;

int main()
{
    System_Control sc;
    sc.AddCount();
    GetNumber gn1(10, 1000);
    GetNumber gn2(1000, 10000);
    GetNumber gn3(10000, 100000);

    auto n = gn1.GetNumberList(tiny_data, 10, 1000);
    for (auto i : n)
    {
        cout << i << endl;
    }
    cout << "----------------" << endl;
    sort(n.begin(), n.end());
    for (auto i : n)
    {
        cout << i << endl;
    }
    for (int i = 0; i < mid_data; i++)
    {
        auto n = gn2.GetSingleNumber();
        cout << n << endl;
    }
    for (int i = 0; i < huge_data; i++)
    {
        auto n = gn3.GetSingleNumber();
        cout << n << endl;
    }
}