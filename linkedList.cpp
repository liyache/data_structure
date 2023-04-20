//
// Created by LittleChen on 2023/2/23.
//

#include <cstdlib>
#include "stdio.h"
#include "linkedList.h"

//创建单链表（头插法）
bool CreateListSH(LinkNode *&L, ElemType exa[], int n) {
    LinkNode *temporary;

    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = NULL;

    for (int i = 0; i < n; i++) {
        temporary = (LinkNode *) malloc(sizeof(LinkNode));
        temporary->data = exa[i];

        temporary->next = L->next;
        L->next = temporary;
    }
    return true;
};

//创建单链表（尾插法）
bool CreateListST(LinkNode *&L, ElemType exa[], int n) {
    LinkNode *temporary;
    LinkNode *head;

    L = (LinkNode *) malloc(sizeof(LinkNode));
    head = (LinkNode *) malloc(sizeof(LinkNode));

    L->next = NULL;
    head = L;
    for (int i = 0; i < n; i++) {
        temporary = (LinkNode *) malloc(sizeof(LinkNode));
        temporary->data = exa[i];

        head->next = temporary;
        head = head->next;
    }
    head->next = NULL;
    return true;
};

//初始化单链表
bool InitListS(LinkNode *&L) {
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = NULL;
    L->data = 0;
    return true;
};

//销毁单链表
bool DestroyListS(LinkNode *&L) {
    LinkNode *temporary;
    temporary = L->next;
    while (temporary != NULL) {
        free(L);
        L = temporary;
        temporary = temporary->next;
    }
    free(L);
    return true;
};

//判断单链表是否为空
bool ListEmptyS(LinkNode *L) {
    if (L->next != NULL) {
        return false;
    } else {
        return true;
    }
};

//求单链表长度
int ListLengthS(LinkNode *L) {
    int result = 0;
    LinkNode *temporary;
    temporary = L;
    while (temporary != NULL) {
        result += 1;
        temporary = temporary->next;
    }
    return result;
};

//输出单链表
bool PrintListS(LinkNode *L) {
    LinkNode *temporary;
    temporary = L;

    while (temporary != NULL) {
        printf(" %d ->", temporary->data);
        temporary = temporary->next;
    }
    printf("\n");
    return true;
};

//取第i个位置的值
bool GetElemS(LinkNode *L, int i, ElemType &e) {
    LinkNode *temporary;

    temporary = L;
    for (int kiss = 0; kiss < i; kiss++) {
        temporary = temporary->next;
    }
    e = temporary->data;
    return true;
};

//求值为e的元素的位置
int LocateElemS(LinkNode *L, ElemType e) {
    LinkNode *temporary;

    temporary = L;
    int record = 0;
    while (temporary->data != e) {
        temporary = temporary->next;
        record += 1;
    }
    return record;
};

//插入元素
bool InsertListS(LinkNode *&L, int i, ElemType e) {
    LinkNode *location;
    LinkNode *storage;

    location = L;
    storage = (LinkNode *) malloc(sizeof(LinkNode));
    storage->data = e;

    for (int kiss = 0; kiss < i; kiss++) {
        location = location->next;
    }
    storage->next = location->next;
    location->next = storage;

    return true;
};

//删除元素
bool DeleteListS(LinkNode *&L, int i, ElemType &e) {
    LinkNode *location;
    location = L;

    for (int kiss = 0; kiss < (i - 1); kiss++) {
        location = location->next;
    }
    location->next = location->next->next;
    return true;
};

//建立双链表（头插法）
bool CreateListDH(DLinkNode *&L, ElemType exa[], int n) {
    L = (DLinkNode *) malloc(sizeof(DLinkNode));
    L->front = NULL;
    L->next = NULL;
    DLinkNode *temporary;

    for (int i = 0; i < n; i++) {
        temporary = (DLinkNode *) malloc(sizeof(DLinkNode));
        temporary->data = exa[i];

        if (L->next == NULL) {
            temporary->next = L->next;
            L->next = temporary;
            temporary->front = L;
        } else {
            L->next->front = temporary;
            temporary->next = L->next;
            L->next = temporary;
            temporary->front = L;
        }
    }
    return true;
};

//建立双链表（尾插法）
bool CreateListDT(DLinkNode *&L, ElemType exa[], int n) {
    DLinkNode *temporary;
    DLinkNode *location;

    L = (DLinkNode *) malloc(sizeof(DLinkNode));
    L->next = NULL;
    L->front = NULL;
    location = L;

    for (int i = 0; i < n; i++) {
        temporary = (DLinkNode *) malloc(sizeof(DLinkNode));
        temporary->data = exa[i];

        location->next = temporary;
        temporary->front = location;
        location = location->next;
    }
    location->next = NULL;
    return true;
};

//输出双链表
bool PrintListD(DLinkNode *L) {
    DLinkNode *location;
    location = L;

    while (location->next != NULL) {
        printf(" %d -> ", location->data);
        location = location->next;
    }
    printf("\n");
    while (location->front != NULL) {
        printf("%d <- ", location->data);
        location = location->front;
    }
    return true;
};

//双链表插入元素
bool InsertListD(DLinkNode *&L, int i, ElemType e) {
    DLinkNode *location;
    DLinkNode *temporary;

    location = L;
    temporary = (DLinkNode *) malloc(sizeof(DLinkNode));
    temporary->data = e;
    for (int kiss = 0; kiss < i; kiss++) {
        location = location->next;
    }
    temporary->next = location->next;
    location->next->front = temporary;
    location->next = temporary;
    temporary->front = location;
};

//双链表删除元素
bool DeleteListD(DLinkNode *&L, int i, ElemType &e) {
    DLinkNode *location;
    location = L;

    for (int kiss = 0; kiss < (i - 1); kiss++) {
        location = location->next;
    }
    location->next->next->front = location;
    location->next = location->next->next;

    return true;
};
