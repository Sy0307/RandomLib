# Sy 随手写的一个随机数生成库

尝试更好的造数据的方式，以及为了一些随机化算法做准备。

不管怎么说已经在更新了。会越来越好用的。

优点是保证了随机性。并且提供了一些基本的方法，帮助快速生成数据。

## 具体用法

你需要写一个main.cpp 文件，然后使用相关API来写你的数据生成文件。
最终使用start.cmd来编译以及生成批量生成数据。

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
#include "Random.h"
#include<math>

using namespace std;

int main()
{
    
}
```
