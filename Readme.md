# Sy 随手写的一个随机数生成库

尝试更好的造数据的方式，以及为了一些随机化算法做准备。

不管怎么说已经在更新了。会越来越好用的。

目前的功能整理：
## GetString 类型

string GetBalanceString(int len,int t) # len = 长度，t  = 方差，默认参数为30;
void receive(vector<char>) # 指定字符串中可能出现的字符;
print() 输出字符串;

## GetNumber 类型
### 成员
int rangelow; 左边界
int rangehigh; 右边界
int len; 长度

### 方法
vector<int> GetNumber::GetNumberList(int len = -1, int l = -1, int r = -1,int seed = 0) # 生成一个vector数组 参数为：长度，左边界，右边界，种子，默认参数为-1

vector<int> GetUniqueNumberList(int len,int l,int r,int&seed); #生成一个不重复的数组，参数为：长度，左边界，右边界，种子，默认参数为-1

