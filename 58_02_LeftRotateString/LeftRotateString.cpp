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

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <cstdio>
#include "StringUtil.h"
#include <string.h>

char* LeftRotateString(char* pStr, int n)
{
    if(pStr != nullptr)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // 翻转字符串的前面n个字符
            Reverse(pFirstStart, pFirstEnd);
            // 翻转字符串的后面部分
            Reverse(pSecondStart, pSecondEnd);
            // 翻转整个字符串
            Reverse(pFirstStart, pSecondEnd);
        }
    }

    return pStr;
}

// ====================测试代码====================
void test(const char* testName, char* input, int num, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试
void test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    test((char *)"test1", input, 2, expected);
}

// 边界值测试
void test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    test((char *)"test2", input, 1, expected);
}

// 边界值测试
void test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    test((char *)"test3", input, 6, expected);
}

// 鲁棒性测试
void test4()
{
    test((char *)"Test4", nullptr, 6, nullptr);
}

// 鲁棒性测试
void test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    test((char *)"Test5", input, 0, expected);
}

// 鲁棒性测试
void test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    test((char *)"Test6", input, 7, expected);
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

