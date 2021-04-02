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

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <cstdio>

int GetMissingNumber(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;
    while(left <= right)
    {
        int middle = (right + left) >> 1;
        if(numbers[middle] != middle)
        {
            if(middle == 0 || numbers[middle - 1] == middle - 1)
                return middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }

    if(left == length)
        return length;

    // 无效的输入，比如数组不是按要求排序的，
    // 或者有数字不在0到n-1范围之内
    return -1;
}

// ====================测试代码====================
void test(const char* testName, int numbers[], int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    int result = GetMissingNumber(numbers, length);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 缺失的是第一个数字0
void test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
    int expected = 0;
    test((char *)"test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int expected = 5;
    test((char *)"test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
    int expected = 3;
    test((char *)"test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void test4()
{
    int numbers[] = { 1 };
    int expected = 0;
    test((char *)"Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void test5()
{
    int numbers[] = { 0 };
    int expected = 1;
    test((char *)"Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void test6()
{
    int expected = -1;
    test((char *)"Test6", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}
