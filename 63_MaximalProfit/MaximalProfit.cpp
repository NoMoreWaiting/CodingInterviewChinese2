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

// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

#include <cstdio>

int MaxDiff(const int* numbers, unsigned length)
{
    if(numbers == nullptr && length < 2)
        return 0;

    int min = numbers[0];
    int maxDiff = numbers[1] - min;

    for(int i = 2; i < length; ++i)
    {
        if(numbers[i - 1] < min)
            min = numbers[i - 1];

        int currentDiff = numbers[i] - min;
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }

    return maxDiff;
}

// ==================== test Code ====================
void test(const char* testName, const int* numbers, unsigned int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(MaxDiff(numbers, length) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void test1()
{
    int numbers[] = { 4, 1, 3, 2, 5 };
    test((char *)"test1", numbers, sizeof(numbers) / sizeof(int), 4);
}

// 价格递增
void test2()
{
    int numbers[] = { 1, 2, 4, 7, 11, 16 };
    test((char *)"test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

// 价格递减
void test3()
{
    int numbers[] = { 16, 11, 7, 4, 2, 1 };
    test((char *)"test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

// 价格全部相同
void test4()
{
	int numbers[] = { 16, 16, 16, 16, 16 };
	test((char *)"Test4", numbers, sizeof(numbers) / sizeof(int), 0);
}

void test5()
{
    int numbers[] = { 9, 11, 5, 7, 16, 1, 4, 2 };
    test((char *)"Test5", numbers, sizeof(numbers) / sizeof(int), 11);
}

void test6()
{
    int numbers[] = { 2, 4 };
    test((char *)"Test6", numbers, sizeof(numbers) / sizeof(int), 2);
}

void test7()
{
    int numbers[] = { 4, 2 };
    test((char *)"Test7", numbers, sizeof(numbers) / sizeof(int), -2);
}

void test8()
{
	test((char *)"Test8", nullptr, 0, 0);
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

    return 0;
}
