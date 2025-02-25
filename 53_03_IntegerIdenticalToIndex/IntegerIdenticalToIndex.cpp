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

// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。

#include <cstdio>

int GetNumberSameAsIndex(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int left = 0;
    int right = length - 1;
    while(left <= right)
    {
        int middle = left + ((right - left) >> 1);
        if(numbers[middle] == middle)
            return middle;

        if(numbers[middle] > middle)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}

// ====================测试代码====================
void test(const char* testName, int numbers[], int length, int expected)
{
    if(GetNumberSameAsIndex(numbers, length) == expected)
        printf("%s passed.\n", testName);
    else
        printf("%s FAILED.\n", testName);
}

void test1()
{
    int numbers[] = { -3, -1, 1, 3, 5 };
    int expected = 3;
    test((char *)"test1", numbers, sizeof(numbers) / sizeof(int), expected);
}

void test2()
{
    int numbers[] = { 0, 1, 3, 5, 6 };
    int expected = 0;
    test((char *)"test2", numbers, sizeof(numbers) / sizeof(int), expected);
}

void test3()
{
    int numbers[] = { -1, 0, 1, 2, 4 };
    int expected = 4;
    test((char *)"test3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void test4()
{
    int numbers[] = { -1, 0, 1, 2, 5 };
    int expected = -1;
    test((char *)"Test4", numbers, sizeof(numbers) / sizeof(int), expected);
}

void test5()
{
    int numbers[] = { 0 };
    int expected = 0;
    test((char *)"Test5", numbers, sizeof(numbers) / sizeof(int), expected);
}

void test6()
{
    int numbers[] = { 10 };
    int expected = -1;
    test((char *)"Test6", numbers, sizeof(numbers) / sizeof(int), expected);
}

void test7()
{
    test((char *)"Test7", nullptr, 0, -1);
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

    return 0;
}