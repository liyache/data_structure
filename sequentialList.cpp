//
// Created by LittleChen on 2023/2/22.
//

#include <stdio.h>
#include <cstdlib>
#include "sequentialList.h"

//实现所有接口

//创建顺序表
bool CreateList(SqList *&L, ElemType exa[], int n) {
    L = (SqList *) malloc(sizeof(SqList));
    int i = 0, j = 0;
    while (j < n) {
        L->data[i] = exa[j];
        i++;
        j++;
    }
    L->length = i;
    return true;
}

//初始化顺序表
bool InitList(SqList *&L) {
    L = (SqList *) malloc(sizeof(SqList));
    L->length = 0;
    for (int i = 0; i < MaxSize; i++) {
        L->data[i] = 0;
    }
    return true;
};

//销毁顺序表
bool DestroyList(SqList *&L) {
    if (L == NULL) {
        return false;
    } else {
        free(L);
        return true;
    }
};

//判断顺序表是否为空
bool ListEmpty(SqList *L) {
    if (L->length != 0 && (sizeof(L->data) / sizeof(ElemType)) != 0) {
        return false;
    } else {
        return true;
    }
};

//求线性表长度
int ListLength(SqList *L) {
    if (L->length == sizeof(L->data) / sizeof(ElemType)) {
        return L->length;
    } else {
        return -1;
    }
};

//输出线性表
bool PrintList(SqList *L) {
    for (int i = 0; i < L->length; i++) {
        printf(" %d ", L->data[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    return true;
};

//求线性表中的某个元素值
bool GetElem(SqList *L, int i, ElemType &e) {
    if (i > L->length || i < 1) {
        return false;
    } else {
        e = L->data[i - 1];
    }
};

//按元素值查找，返回逻辑序号
int LocateElem(SqList *L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i + 1;
        }
    }
    return -1;
};

//插入数据元素
bool ListInsert(SqList *&L, int i, ElemType e) {
    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length += 1;
    return true;
};

//删除数据元素
bool ListDelete(SqList *&L, int i, ElemType &e) {
    e = L->data[i-1];
    for (int j = i - 1; j < L->length; j++) {
        L->data[j] = L->data[j + 1];
    }
    L->length -= 1;
};
