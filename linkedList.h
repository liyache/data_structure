//
// Created by LittleChen on 2023/2/23.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H

#endif //DATA_STRUCTURE_LINKEDLIST_H

//单链表部分
typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
} LinkNode;

//创建单链表（头插法）
bool CreateListSH(LinkNode *&L, ElemType exa[], int n);

//创建单链表（尾插法）
bool CreateListST(LinkNode *&L, ElemType exa[], int n);

//初始化单链表
bool InitListS(LinkNode *&L);

//销毁单链表
bool DestroyListS(LinkNode *&L);

//判断单链表是否为空
bool ListEmptyS(LinkNode *L);

//求单链表长度
int ListLengthS(LinkNode *L);

//输出单链表
bool PrintListS(LinkNode *L);

//取第i个位置的值
bool GetElemS(LinkNode *L, int i, ElemType &e);

//求值为e的元素的位置
int LocateElemS(LinkNode *L, ElemType e);

//插入元素
bool InsertListS(LinkNode *&L, int i, ElemType e);

//删除元素
bool DeleteListS(LinkNode *&L, int i, ElemType &e);

//双链表部分
typedef struct Dnode {
    ElemType data;
    struct Dnode *front;
    struct Dnode *next;
} DLinkNode;

//建立双链表（头插法）
bool CreateListDH(DLinkNode *&L, ElemType exa[], int n);

//建立双链表（尾插法）
bool CreateListDT(DLinkNode *&L, ElemType exa[], int n);

//输出双链表
bool PrintListD(DLinkNode *L);

//双链表插入元素
bool InsertListD(DLinkNode *&L, int i, ElemType e);

//双链表删除元素
bool DeleteListD(DLinkNode *&L, int i, ElemType &e);