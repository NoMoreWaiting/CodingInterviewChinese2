#!/usr/bin/env bash

set -euxo pipefail

projects=(
  01_AssignmentOperator
  03_01_DuplicationInArray
  03_02_DuplicationInArrayNoEdit
  04_FindInPartiallySortedMatrix
  05_ReplaceSpaces
  06_PrintListInReversedOrder
  07_ConstructBinaryTree
  08_NextNodeInBinaryTrees
  09_QueueWithTwoStacks
  10_Fibonacci
  11_MinNumberInRotatedArray
  12_StringPathInMatrix
  13_RobotMove
  14_CuttingRope
  15_NumberOf1InBinary
  16_Power
  17_Print1ToMaxOfNDigits
  18_01_DeleteNodeInList
  18_02_DeleteDuplicatedNode
  19_RegularExpressionsMatching
  20_NumericStrings
  21_ReorderArray
  22_KthNodeFromEnd
  23_EntryNodeInListLoop
  24_ReverseList
  25_MergeSortedLists
  26_SubstructureInTree
  27_MirrorOfBinaryTree
  28_SymmetricalBinaryTree
  29_PrintMatrix
  30_MinInStack
  31_StackPushPopOrder
  32_01_PrintTreeFromTopToBottom
  32_02_PrintTreesInLines
  32_03_PrintTreesInZigzag
  33_SquenceOfBST
  34_PathInTree
  35_CopyComplexList
  36_ConvertBinarySearchTree
  37_SerializeBinaryTrees
  38_StringPermutation
  39_MoreThanHalfNumber
  40_KLeastNumbers
  41_StreamMedian
  42_GreatestSumOfSubarrays
  43_NumberOf1
  44_DigitsInSequence
  45_SortArrayForMinNumber
  46_TranslateNumbersToStrings
  47_MaxValueOfGifts
  48_LongestSubstringWithoutDup
  49_UglyNumber
  50_01_FirstNotRepeatingChar
  50_02_FirstCharacterInStream
  51_InversePairs
  52_FirstCommonNodesInLists
  53_01_NumberOfK
  53_02_MissingNumber
  53_03_IntegerIdenticalToIndex
  54_KthNodeInBST
  55_01_TreeDepth
  55_02_BalancedBinaryTree
  56_01_NumbersAppearOnce
  56_02_NumberAppearingOnce
  57_01_TwoNumbersWithSum
  57_02_ContinuousSquenceWithSum
  58_01_ReverseWordsInSentence
  58_02_LeftRotateString
  59_01_MaxInSlidingWindow
  59_02_QueueWithMax
  60_DicesProbability
  61_ContinousCards
  62_LastNumberInCircle
  63_MaximalProfit
  64_Accumulate
  65_AddTwoNumbers
  66_ConstuctArray
  67_StringToInt
  68_CommonParentInTree
)

build_path="cmake-build-debug"

if [ -d ${build_path} ];then
  rm -rf ${build_path}
fi

mkdir ${build_path}
cd ${build_path}

cmake ..

for project in ${projects[*]}
do
  cd ${project}
  make
  ./"${project}"
  cd ..
done

