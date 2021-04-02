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

// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include <cstdio>
#include <cstdlib>

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int* numbers, int length)
{
    if(numbers == nullptr || length < 1)
        return false;

    qsort(numbers, length, sizeof(int), Compare);

    int numberOfZero = 0;
    int numberOfGap = 0;

    // 统计数组中0的个数
    for(int i = 0; i < length && numbers[i] == 0; ++i)
        ++numberOfZero;

    // 统计数组中的间隔数目
    int small = numberOfZero;
    int big = small + 1;
    while(big < length)
    {
        // 两个数相等，有对子，不可能是顺子
        if(numbers[small] == numbers[big])
            return false;

        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }

    return (numberOfGap > numberOfZero) ? false : true;
}

int Compare(const void *arg1, const void *arg2)
{
    return *(int*) arg1 - *(int*) arg2;
}

// ====================测试代码====================
void test(const char* testName, int* numbers, int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsContinuous(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
    test((char *)"test1", numbers, sizeof(numbers) / sizeof(int), true);
}

void test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    test((char *)"test2", numbers, sizeof(numbers) / sizeof(int), false);
}

void test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    test((char *)"test3", numbers, sizeof(numbers) / sizeof(int), true);
}

void test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    test((char *)"Test4", numbers, sizeof(numbers) / sizeof(int), false);
}

void test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    test((char *)"Test5", numbers, sizeof(numbers) / sizeof(int), true);
}

void test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    test((char *)"Test6", numbers, sizeof(numbers) / sizeof(int), false);
}

void test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    test((char *)"Test7", numbers, sizeof(numbers) / sizeof(int), true);
}

void test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    test((char *)"Test8", numbers, sizeof(numbers) / sizeof(int), false);
}

void test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    test((char *)"Test9", numbers, sizeof(numbers) / sizeof(int), true);
}

void test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    test((char *)"Test10", numbers, sizeof(numbers) / sizeof(int), true);
}

// 有对子
void test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    test((char *)"Test11", numbers, sizeof(numbers) / sizeof(int), false);
}

// 鲁棒性测试
void test12()
{
    test((char *)"Test12", nullptr, 0, false);
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
    test10();
    test11();
    test12();

    return 0;
}

