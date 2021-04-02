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

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <cstdio>

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 进入有限状态机的下一个状态
            return matchCore(str + 1, pattern + 2)
            // 继续留在有限状态机的当前状态 
            || matchCore(str + 1, pattern)
            // 略过一个'*' 
            || matchCore(str, pattern + 2);
        else
            // 略过一个'*'
            return matchCore(str, pattern + 2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}

// ====================测试代码====================
void test(const char* testName, const char* string, const char* pattern, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    test("Test01", "", "", true);
    test("Test02", "", ".*", true);
    test("Test03", "", ".", false);
    test("Test04", "", "c*", true);
    test("Test05", "a", ".*", true);
    test("Test06", "a", "a.", false);
    test("Test07", "a", "", false);
    test("Test08", "a", ".", true);
    test("Test09", "a", "ab*", true);
    test("Test10", "a", "ab*a", false);
    test("Test11", "aa", "aa", true);
    test("Test12", "aa", "a*", true);
    test("Test13", "aa", ".*", true);
    test("Test14", "aa", ".", false);
    test("Test15", "ab", ".*", true);
    test("Test16", "ab", ".*", true);
    test("Test17", "aaa", "aa*", true);
    test("Test18", "aaa", "aa.a", false);
    test("Test19", "aaa", "a.a", true);
    test("Test20", "aaa", ".a", false);
    test("Test21", "aaa", "a*a", true);
    test("Test22", "aaa", "ab*a", false);
    test("Test23", "aaa", "ab*ac*a", true);
    test("Test24", "aaa", "ab*a*c*a", true);
    test("Test25", "aaa", ".*", true);
    test("Test26", "aab", "c*a*b", true);
    test("Test27", "aaca", "ab*a*c*a", true);
    test("Test28", "aaba", "ab*a*c*a", false);
    test("Test29", "bbbba", ".*a*a", true);
    test("Test30", "bcbbabab", ".*a*a", false);

    return 0;
}

