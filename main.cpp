#include <iostream>
#include "sequentialList.h"
#include "linkedList.h"
#include "sequentialStack.h"
#include "linkedStack.h"
#include "sequentialQueue.h"
#include "linkedQueue.h"
#include "sequentialString.h"
#include "linkedString.h"
#include "matchString.h"
#include "linkedBinaryTree.h"
#include "huffmanTree.h"
#include "adjacencyList.h"
#include "adjacencyMatrix.h"
#include "search.h"
#include "hashtable.h"
#include "sort.h"
#include "algorithm"

int main() {
    std::cout << "Hello, World!" << std::endl;

    ElemType exa[] = {5, 2, 0, 1, 3, 1, 4, 9, 9, 9};
    SqList *List;
    int length = sizeof(exa) / sizeof(int);
//    bool result;

    InitList(List);
    CreateList(List, exa, length);
    PrintList(List);

    int result;
    int set = 2;

    int resNum = LocateElem(List, 0);
    printf("\n 此元素在第 %d 个位置上", resNum);

    GetElem(List, set, result);
    printf("\n 第 %d 个元素为: %d\n", set, result);

    ListInsert(List, 4, 6);
    PrintList(List);

    int resDel;
    ListDelete(List, 4, resDel);
    printf("\n 被删除的元素为: %d\n", resDel);
    PrintList(List);

    DestroyList(List);

    printf("\n****************************************\n");

    LinkNode *LinkH;
    CreateListSH(LinkH, exa, length);
    LinkNode *LinkT;
    CreateListST(LinkT, exa, length);

    PrintListS(LinkH);
    PrintListS(LinkT);

    int resultH, resultT;

    int address = 3;
    GetElemS(LinkH, address, resultH);
    GetElemS(LinkT, address, resultT);
    printf("\n 头插法结果是: %d, 尾插法结果是: %d\n", resultH, resultT);

    int recordH = LocateElemS(LinkH, 5);
    int recordT = LocateElemS(LinkT, 5);

    printf("\n 头插法中的位置是: %d, 尾插法中的位置是: %d\n", recordH, recordT);

    InsertListS(LinkH, 2, 6);
    InsertListS(LinkT, 3, 2);

    PrintListS(LinkH);
    PrintListS(LinkT);

    int rushH, rushT;
    DeleteListS(LinkH, 3, rushH);
    DeleteListS(LinkT, 4, rushT);
    PrintListS(LinkH);
    PrintListS(LinkT);

    printf("\n*********************************\n");
    DLinkNode *DLinkH;
    DLinkNode *DLinkT;
    CreateListDH(DLinkH, exa, length);
    CreateListDT(DLinkT, exa, length);
    PrintListD(DLinkH);
    printf("\n");
    PrintListD(DLinkT);

    printf("\n*********************************\n");
    InsertListD(DLinkH, 2, 12);
    InsertListD(DLinkT, 3, 66);

    PrintListD(DLinkH);
    printf("\n");
    PrintListD(DLinkT);

    printf("\n*********************************\n");
    int numberH, numberT;
    DeleteListD(DLinkH, 1, numberH);
    DeleteListD(DLinkT, 1, numberT);

    PrintListD(DLinkH);
    printf("\n");
    PrintListD(DLinkT);

    printf("\n ********** 以下是栈的部分 ************\n");
    SqStack *Stack;
    InitStack(Stack);
    for (int i = 0; i < length; i++) {
        Push(Stack, exa[i]);
    }
    PrintStack(Stack);

    int temporary;
    Pop(Stack, temporary);
    printf("\n 出来的元素是: %d\n", temporary);
    PrintStack(Stack);

    printf("\n****************************\n");
    LinkStNode *LinkStack;
    InitStack(LinkStack);
    for (int i = 0; i < length; i++) {
        Push(LinkStack, exa[i]);
    }
    PrintStack(LinkStack);
    Pop(LinkStack, temporary);
    printf("\n");
    PrintStack(LinkStack);

    printf("\n****************************\n");
    SqQueue *Q;
    InitQueue(Q);
    for (int i = 0; i < length; i++) {
        enQueue(Q, exa[i]);
    }
    PrintQueue(Q);
    deQueue(Q, temporary);
    PrintQueue(Q);
    printf("\n %d \n", temporary);

    printf("\n****************************\n");
    LinkQueue *Lq;
    InitQueue(Lq);
    for (int i = 0; i < length; i++) {
        enQueue(Lq, exa[i]);
    }
    PrintQueue(Lq);
    deQueue(Lq, temporary);
    PrintQueue(Lq);

    printf("\n****************************\n");
    SingleRear *Sr;
    InitQueue(Sr);
    for (int i = 0; i < length; i++) {
        enQueue(Sr, exa[i]);
    }
    PrintQueue(Sr);
    deQueue(Sr, temporary);
    PrintQueue(Sr);

    printf("\n****************************\n");
    char string[] = "WoAiNi";
    char LString[] = "Bu";
    char TString[] = "Miss";
    SqString example, suchAs, exm;
    StrAssign(example, string);
    StrAssign(suchAs, LString);
    StrAssign(exm, TString);
    PrintStr(example);
    example = InsStr(example, 3, suchAs);
    PrintStr(example);
    example = DelStr(example, 3, 2);
    PrintStr(example);
    example = RepStr(example, 3, 2, exm);
    PrintStr(example);

    printf("\n****************************\n");
    LkString *a, *b, *c, *d;
    StrAssign(a, string);
    StrAssign(b, LString);
    StrAssign(d, TString);
    PrintStr(a);
    c = Concat(a, b);
    PrintStr(c);
    c = SubStr(a, 3, 2);
    PrintStr(c);
    c = InsStr(a, 3, b);
    PrintStr(c);
    c = DelStr(c, 3, 2);
    PrintStr(c);
    c = RepStr(a, 3, 2, b);
    PrintStr(c);

    using std::cout;
    using std::endl;
    matchString match = matchString("ILoveYou", "Il");
    result = match.Kmp();
    match.BF();
    cout << result << endl;

    using namespace BinaryTree;
    binaryTree tree = binaryTree("A(B(D,E(H)),C(F(I,J),G(,K))");
    BtNode *node = tree.getBtNode();
    tree.printTree(node);
    BtNode *re = tree.findNode(node, 'H');
    cout << endl << re->data << endl;
    int rq = tree.printHeight(node);
    cout << "这颗树🌲的高度是:" << rq << endl;

    tree.preOrder(node);
    cout << endl;
    tree.inOrder(node);
    cout << endl;
    tree.postOrder(node);
    cout << endl;
    tree.preOrderNoRecur(node);
    cout << endl;
    tree.inOrderNoRecur(node);
    cout << endl;
    tree.postOrderNoRecur(node);
    cout << endl;
    tree.levelOrder(node);

    using namespace HuffmanTree;
    char nodes[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    double weights[] = {0.07, 0.19, 0.02, 0.06, 0.32, 0.03, 0.21, 0.10};
    huffmanTree hTree = huffmanTree(nodes, weights, 8);
    hTree.createHT();
    hTree.createHCode();
    hTree.printHCode();

    using namespace adjacencyList;
    int A[][5] = {{0, 1, 0, 1, 1},
                  {1, 0, 1, 1, 0},
                  {0, 1, 0, 1, 1},
                  {1, 1, 1, 0, 1},
                  {1, 0, 1, 1, 0}};
    adjacency adj = adjacency(A, 5, 8);
    adj.printAdj();
    AdjGraph *some = adj.getG();
    adj.DFS(some, 2);
    cout << endl;
    adj.BFS(2);

    using namespace adjacencyMatrix;
    int B[][MaxV] = {
            {0,   28,  INF, INF, INF, 10,  INF},
            {28,  0,   16,  INF, INF, INF, 14},
            {INF, 16,  0,   12,  INF, INF, INF},
            {INF, INF, 12,  0,   22,  INF, 18},
            {INF, INF, INF, 22,  0,   25,  24},
            {10,  INF, INF, INF, 25,  0,   INF},
            {INF, 14,  INF, 18,  24,  INF, 0}
    };
    int C[] = {0, 1, 2, 3, 4, 5, 6};
    matrix mat = matrix(B, 7, 9, C);
    mat.Prim(0);

    int D[][MaxV] = {{0,   4,   6, 6,     INF, INF, INF},
                     {INF, 0,   1,   INF, 7,   INF, INF},
                     {INF, INF, 0,   INF, 6,   4,   INF},
                     {INF, INF, 2, 0,     INF, 5,   INF},
                     {INF, INF, INF, INF, 0,   INF, 6},
                     {INF, INF, INF, INF, 1,   0,   8},
                     {INF, INF, INF, INF, INF, INF, 0}
    };
    matrix matB = matrix(D, 7, 12, C);
    matB.Dijkstra(1);
    matB.Floyd();

    using namespace search;
    int temp[] = {1, 9, 2, 6, 3, 8, 5, 7, 0};
    seaList<int> sea1 = seaList<int>(temp, 9);
    int res = sea1.SeqSearch(8, 9);
    seaList<int> sea2 = seaList<int>(C, 7);
    int res2 = sea2.halfSearch(5, 7);
    cout << "匹配结果是" << res << " 另一种匹配结果是" << res2 << endl;

    int temp2[] = {5, 2, 0, 1, 3, 1, 4};
    seaBinary<int> sea3 = seaBinary<int>(temp2, 7);
    BSTNode<int> *tem = sea3.getBstNode();
    BSTNode<int> *res3 = sea3.SearchBST(tem, 0);
    cout << "查询的结果为" << res3->data << endl;

    using namespace hash;
    int keys[] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    HashTable hashTable = HashTable(13, 13, keys, 11);
    hashTable.DeleteHT(13, 13, 90);
    hashTable.DeleteHT(13, 77);
    hashTable.SearchHT(13, 13, 90);

    using namespace sort;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    SortNum sortNum = SortNum(arr, n);
    sortNum.bubbleSort();
    sortNum.insertionSort();
    sortNum.selectionSort();

    int *temA = sortNum.getArr();
    int *temB = new int[7];
    for (int i = 0; i < 7; ++i) {
        temB[i] = temA[i];
    }
    sortNum.mergeSort(temB, 0, 6);
    for (int i = 0; i < 7; ++i) {
        cout << temB[i] << " ";
    }
    cout << endl;
    int *temC = new int[7];
    for (int i = 0; i < 7; ++i) {
        temC[i] = temA[i];
    }
    sortNum.quickSort(temC, 0, 6);
    for (int i = 0; i < 7; ++i) {
        cout << temC[i] << " ";
    }
    cout << endl;
    sortNum.heapSort();
    sortNum.radixSort();
    sortNum.countingSort();
    return 0;
}
