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

// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#include <algorithm>
#include <cstring>
#include <cstdio>

int compare(const void *strNumber1, const void *strNumber2);

// int 型整数用十进制表示最多只有 10 位
const int g_MaxNumberLength = 10;

void printMinNumber(const int *numbers, int length) {
    if (numbers == nullptr || length <= 0)
        return;

    char **strNumbers = new char *[length];
    for (int i = 0; i < length; ++i) {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        memset(strNumbers[i], 0, g_MaxNumberLength + 1);
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char *), compare);

    for (int i = 0; i < length; ++i)
        printf("%s", strNumbers[i]);
    printf("\n");

    for (int i = 0; i < length; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

// 如果[strNumber1][strNumber2] > [strNumber2][strNumber1], 返回值大于0
// 如果[strNumber1][strNumber2] = [strNumber2][strNumber1], 返回值等于0
// 如果[strNumber1][strNumber2] < [strNumber2][strNumber1], 返回值小于0
int compare(const void *strNumber1, const void *strNumber2) {
    static const int allLength = g_MaxNumberLength * 2 + 1;
    static char *g_StrCombine1 = new char[allLength];
    static char *g_StrCombine2 = new char[allLength];
    memset(g_StrCombine1, 0, allLength);
    memset(g_StrCombine2, 0, allLength);

    // [strNumber1][strNumber2]
    strcpy(g_StrCombine1, *(const char **) strNumber1);
    strcat(g_StrCombine1, *(const char **) strNumber2);

    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char **) strNumber2);
    strcat(g_StrCombine2, *(const char **) strNumber1);

    // printf("compare g_StrCombine1: %s, g_StrCombine2: %s\n", g_StrCombine1, g_StrCombine2);

    return strcmp(g_StrCombine1, g_StrCombine2);
}

// ====================测试代码====================
void test(const char *testName, int *numbers, int length, const char *expectedResult) {
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    if (expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    printMinNumber(numbers, length);

    printf("\n");
}

void test1() {
    int numbers[] = {3, 5, 1, 4, 2};
    test((char *) "test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void test2() {
    int numbers[] = {3, 32, 321};
    test((char *) "test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void test3() {
    int numbers[] = {3, 323, 32123};
    test((char *) "test3", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void test4() {
    int numbers[] = {1, 11, 111};
    test((char *) "Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

// 数组中只有一个数字
void test5() {
    int numbers[] = {321};
    test((char *) "Test5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void test6() {
    test((char *) "Test6", nullptr, 0, "Don't print anything.");
}


int main(int argc, char *argv[]) {
    printf("sizeof(bool*): %lu\n", sizeof(bool *));

    printf("sizeof(bool): %lu\n", sizeof(bool));
    printf("sizeof(char): %lu\n", sizeof(char));
    printf("sizeof(wchar_t): %lu\n", sizeof(wchar_t));
    printf("sizeof(int): %lu\n", sizeof(int));
    printf("sizeof(long): %lu\n", sizeof(long));
    printf("sizeof(float): %lu\n", sizeof(float));
    printf("sizeof(double): %lu\n", sizeof(double));
    printf("sizeof(long int): %lu\n", sizeof(long int));
    printf("sizeof(long long): %lu\n", sizeof(long long));
    printf("sizeof(long double): %lu\n", sizeof(long double));

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}

