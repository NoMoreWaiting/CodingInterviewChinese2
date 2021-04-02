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

// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include <cstdio>
#include "StackWithMin.h"

void test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    test((char *)"test1", stack, 3);

    stack.push(4);
    test((char *)"test2", stack, 3);

    stack.push(2);
    test((char *)"test3", stack, 2);

    stack.push(3);
    test((char *)"Test4", stack, 2);

    stack.pop();
    test((char *)"Test5", stack, 2);

    stack.pop();
    test((char *)"Test6", stack, 3);

    stack.pop();
    test((char *)"Test7", stack, 3);

    stack.push(0);
    test((char *)"Test8", stack, 0);

    return 0;
}

