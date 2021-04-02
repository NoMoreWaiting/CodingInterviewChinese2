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

// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <stdio.h>

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
    if(str == nullptr)
        return false;

    bool numeric = scanInteger(&str);

    // 如果出现'.'，接下来是数字的小数部分
    if(*str == '.')
    {
        ++str;

        // 下面一行代码用||的原因：
        // 1. 小数可以没有整数部分，例如.123等于0.123；
        // 2. 小数点后面可以没有数字，例如233.等于233.0；
        // 3. 当然小数点前面和后面可以有数字，例如233.666
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
    if(*str == 'e' || *str == 'E')
    {
        ++str;

        // 下面一行代码用&&的原因：
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    // 当str中存在若干0-9的数字时，返回true
    return *str > before;
}

// 整数的格式可以用[+|-]B表示, 其中B为无符号整数
bool scanInteger(const char** str)
{
    if(**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}

// ====================测试代码====================
void test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    test((char *)"test1", "100", true);
    test((char *)"test2", "123.45e+6", true);
    test((char *)"test3", "+500", true);
    test((char *)"Test4", "5e2", true);
    test((char *)"Test5", "3.1416", true);
    test((char *)"Test6", "600.", true);
    test((char *)"Test7", "-.123", true);
    test((char *)"Test8", "-1E-16", true);
    test((char *)"Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    test((char *)"Test10", "12e", false);
    test((char *)"Test11", "1a3.14", false);
    test((char *)"Test12", "1+23", false);
    test((char *)"Test13", "1.2.3", false);
    test((char *)"Test14", "+-5", false);
    test((char *)"Test15", "12e+5.4", false);
    test((char *)"Test16", ".", false);
    test((char *)"Test17", ".e1", false);
    test((char *)"Test18", "e1", false);
    test((char *)"Test19", "+.", false);
    test((char *)"Test20", "", false);
    test((char *)"Test21", nullptr, false);

    return 0;
}
