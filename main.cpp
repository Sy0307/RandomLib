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