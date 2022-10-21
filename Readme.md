# Sy 随手写的一个随机数生成库

尝试更好的造数据的方式，以及为了一些随机化算法做准备。

不管怎么说已经在更新了。会越来越好用的。

优点是保证了随机性。并且提供了一些基本的方法，帮助快速生成数据。

## 具体用法

你需要写一个main.cpp 文件，然后使用相关API来写你的数据生成文件。
最终使用start.cmd来编译以及生成批量生成数据。
start.cmd 会自动调用编译器，然后调用生成的exe文件，生成数据。
**start.cmd 的具体说明**

```plain
按0 清除所有已经生成的数据
按1 选择生成的数据的数量
按2 退出该成或许
按3 重新编译（如有报错会输出报错信息）
```

**以下是详细的API和使用方法**
**如果你觉得太冗长可以直接跳到末尾的示例。**

## 功能整理

### 必须添加的内容

```cpp
System_Control sc; // 系统控制，用于IO操作
```

### GetString 字符生成类

```cpp
string Get_Balance_String(int len,int t)

获取一个较为平衡的字符串
len = 长度，t  = 方差，默认参数为30，正常情况下不需要调整;

void receive(vector<char>) 

指定字符串中可能出现的字符;
在划定后，生成的字符串中只会出现这些字符

```

### GetNumber 数字生成类（包括int,double,float,long long）

### 成员

```cpp

int rangelow; 生成数据的下界
int rangehigh; 生成数据的上界
int len; 生成数据的长度

上述仅仅支持int类
```

### 方法

```cpp

GetNumber::Get_Single_Number(int l, int r, double per)

生成一个单个的数字 参数为：长度，左边界，正数概率（支持int,double,float,long long）

Get_Number_List(int len = -1, int l = -1, int r = -1)

生成一个vector数组 参数为：长度，左边界，右边界

Get_Unique_Number_List(int len,int l,int r,int&seed);

生成一个不重复的数组，参数为：长度，左边界，右边界，种子，默认参数为-1

GetNumber::GetNumber(int l = -1, int r = -1,int per)

生成一个数字（int或者double） 参数为：l=左边界,r = 右边界，per = 生成数字为正数的概率，默认参数为 1 ，即100%生成正数。
```

## 额外方法

### 输出系列

```cpp
StandardPrint(T,bool space_allow=1);

输出一个变量 T，space_allow 为是否允许输出空格，默认为1，即允许输出空格

StandardPrint(vector<T> &data, bool space_allow = 1);

输出一个数组，space_allow 为是否允许输出空格，默认为1，即允许输出空格

Tp void LCStandardPrint(vector<T> &data, bool space_allow = 1);

按输出任意类型的数组，参数为：是否允许空格，默认为1
```

## 使用方法

点击 `start.cmd` 并且开始按照提示运行即可。
数据均生成在`DATA`文件夹下。

## main.cpp示例

```cpp
#include "./scripts/random.hpp"

int main()
{
    System_Control sc;
    //==========================================================================
    // Write your Code below
    GetNumber gn1;
    auto t1 = gn1.Get_Number_List<int>(1, 10, 10);
    // 生成一个随机正数int数组，长度为10，范围为1-10（包含）
    auto t2 = gn1.Get_Number_List<double>(1, 10, 10, 0.5);
    // 生成一个随机double数组，长度为10，范围为1-10（包含），其中50%为正数，50%为负数
    auto t3 = gn1.Get_Unique_Number_List(10, 1, 1000);
    // 生成一个随机正数int数组，长度为10，范围为1-10（包含），其中不会有重复的数字
    //注意 如果分配错误会抛出异常

    GetString gs1;
    auto t4 = gs1.Get_Balance_String(10, 10);
    // 生成一个随机字符串，但是这个字符串较为平衡，
    // 后一个参数越大会让这个字符串越不平衡
    // 第二个参数由于bug暂时弃用
    gs1.receive({'a', 'b', 'c', 'd'});
    //指定字符串中出现的字符
    auto t5 = gs1.Get_Balance_String(10, 10);
    //输出仅仅包含上述字符的随机字符串
    Standard_Print(t3);
    //默认输出，结尾不带有空格，第二个参数默认为1，代表自带换行符
    String_Print(t5, 1);
    // 默认输出，结尾不带有空格，但是行尾不包含换行

    // Write your Code above
    //==========================================================================
    fclose(stdin);
    fclose(stdout);
}
```
