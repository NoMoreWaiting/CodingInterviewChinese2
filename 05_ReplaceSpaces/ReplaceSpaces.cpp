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

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <cstdio>
#include <cstring>

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;

    /*originalLength 为字符串str的实际长度*/
    int originalLength = 0;
    int numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;

        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;
    }

    /*newLength 为把空格替换成'%20'之后的长度*/
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;
    }
}

// ====================测试代码====================
void test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void test1()
{
    const int length = 100;

    char str[length] = "hello world";
    test((char *)"test1", str, length, (char *)"hello%20world");
}

// 空格在句子开头
void test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    test((char *)"test2", str, length, (char *)"%20helloworld");
}

// 空格在句子末尾
void test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    test((char *)"Test3", str, length, (char *)"helloworld%20");
}

// 连续有两个空格
void test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    test((char *)"Test4", str, length, (char *)"hello%20%20world");
}

// 传入nullptr
void test5()
{
    test((char *)"Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void test6()
{
    const int length = 100;

    char str[length] = "";
    test((char *)"Test6", str, length, (char *)"");
}

//传入内容为一个空格的字符串
void test7()
{
    const int length = 100;

    char str[length] = " ";
    test((char *)"Test7", str, length, (char *)"%20");
}

// 传入的字符串没有空格
void test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    test((char *)"Test8", str, length, (char *)"helloworld");
}

// 传入的字符串全是空格
void test9()
{
    const int length = 100;

    char str[length] = "   ";
    test((char *)"Test9", str, length, (char *)"%20%20%20");
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

    return 0;
}

