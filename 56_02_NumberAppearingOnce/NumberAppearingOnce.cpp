/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include <cstdio>
#include <exception>
#include <stdexcept>

int FindNumberAppearingOnce(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0)
        throw  std::invalid_argument("Invalid input.");

    int bitSum[32] = {0};
    for(int i = 0; i < length; ++i)
    {
        int bitMask = 1;
        for(int j = 31; j >= 0; --j)
        {
            int bit = numbers[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;

            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for(int i = 0; i < 32; ++i)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }

    return result;
}

// ====================测试代码====================
void test(const char* testName, int numbers[], int length, int expected)
{
    int result = FindNumberAppearingOnce(numbers, length);
    if(result == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

// 所有数字都是正数，唯一的数字是最小的
void test1()
{
    int numbers[] = { 1, 1, 2, 2, 2, 1, 3 };
    int expected = 3;
    test((char *)"test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字的大小位于中间
void test2()
{
    int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
    int expected = 4;
    test((char *)"test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是正数，唯一的数字是最大的
void test3()
{
    int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
    int expected = 7;
    test((char *)"test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 唯一的数字是负数
void test4()
{
    int numbers[] = { -10, 214, 214, 214 };
    int expected = -10;
    test((char *)"Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 除了唯一的数字，其他数字都是负数
void test5()
{
    int numbers[] = { -209, 3467, -209, -209 };
    int expected = 3467;
    test((char *)"Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 重复的数字有正数也有负数
void test6()
{
    int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
    int expected = 1023;
    test((char *)"Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 所有数字都是负数
void test7()
{
    int numbers[] = { -1024, -1024, -1024, -1023 };
    int expected = -1023;
    test((char *)"Test7", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 唯一的数字是0
void test8()
{
    int numbers[] = { -23, 0, 214, -23, 214, -23, 214 };
    int expected = 0;
    test((char *)"Test8", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 除了唯一的数字，其他数字都是0
void test9()
{
    int numbers[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
    int expected = 3467;
    test((char *)"Test9", numbers, sizeof(numbers) / sizeof(int), expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}
