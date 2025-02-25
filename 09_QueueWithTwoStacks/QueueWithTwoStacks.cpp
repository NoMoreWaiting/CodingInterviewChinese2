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

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <cstdio>
#include "Queue.h"

// ====================测试代码====================
void test(char actual, char expected)
{
    if(actual == expected)
        printf("test passed.\n");
    else
        printf("test failed.\n");
}

int main(int argc, char* argv[])
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    test(head, 'a');

    head = queue.deleteHead();
    test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    test(head, 'd');

    head = queue.deleteHead();
    test(head, 'e');

    return 0;
}

