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

// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

#include <cstdio>
#include "../Utilities/BinaryTree.h"

const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k);

const BinaryTreeNode* KthNode(const BinaryTreeNode* pRoot, unsigned int k)
{
    if(pRoot == nullptr || k == 0)
        return nullptr;

    return KthNodeCore(pRoot, k);
}

const BinaryTreeNode* KthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k)
{
    const BinaryTreeNode* target = nullptr;

    if(pRoot->m_pLeft != nullptr)
        target = KthNodeCore(pRoot->m_pLeft, k);

    if(target == nullptr)
    {
        if(k == 1)
            target = pRoot;

        k--;
    }

    if(target == nullptr && pRoot->m_pRight != nullptr)
        target = KthNodeCore(pRoot->m_pRight, k);

    return target;
}

// ====================测试代码====================
void test(const char* testName, const BinaryTreeNode* pRoot, unsigned int k, bool isNull, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    const BinaryTreeNode* pTarget = KthNode(pRoot, k);
    if((isNull && pTarget == nullptr) || (!isNull && pTarget->m_nValue == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    test((char *)"TestA0", pNode8, 0, true, -1);
    test((char *)"TestA1", pNode8, 1, false, 5);
    test((char *)"TestA2", pNode8, 2, false, 6);
    test((char *)"TestA3", pNode8, 3, false, 7);
    test((char *)"TestA4", pNode8, 4, false, 8);
    test((char *)"TestA5", pNode8, 5, false, 9);
    test((char *)"TestA6", pNode8, 6, false, 10);
    test((char *)"TestA7", pNode8, 7, false, 11);
    test((char *)"TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);

    printf("\n\n");
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void TestB()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    test((char *)"TestB0", pNode5, 0, true, -1);
    test((char *)"TestB1", pNode5, 1, false, 1);
    test((char *)"TestB2", pNode5, 2, false, 2);
    test((char *)"TestB3", pNode5, 3, false, 3);
    test((char *)"TestB4", pNode5, 4, false, 4);
    test((char *)"TestB5", pNode5, 5, false, 5);
    test((char *)"TestB6", pNode5, 6, true, -1);

    DestroyTree(pNode5);

    printf("\n\n");
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void TestC()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    test((char *)"TestC0", pNode1, 0, true, -1);
    test((char *)"TestC1", pNode1, 1, false, 1);
    test((char *)"TestC2", pNode1, 2, false, 2);
    test((char *)"TestC3", pNode1, 3, false, 3);
    test((char *)"TestC4", pNode1, 4, false, 4);
    test((char *)"TestC5", pNode1, 5, false, 5);
    test((char *)"TestC6", pNode1, 6, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// There is only one node in a tree
void TestD()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    test((char *)"TestD0", pNode1, 0, true, -1);
    test((char *)"TestD1", pNode1, 1, false, 1);
    test((char *)"TestD2", pNode1, 2, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// empty tree
void TestE()
{
    test((char *)"TestE0", nullptr, 0, true, -1);
    test((char *)"TestE1", nullptr, 1, true, -1);

    printf("\n\n");
}

int main(int argc, char* argv[])
{
    TestA();
    TestB();
    TestC();
    TestD();
    TestE();
}
