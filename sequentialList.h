//
// Created by LittleChen on 2023/2/22.
//

#ifndef DATA_STRUCTURE_SEQUENTIALLIST_H
#define DATA_STRUCTURE_SEQUENTIALLIST_H

#endif //DATA_STRUCTURE_SEQUENTIALLIST_H

//规定顺序表元素的最大宽度 50
#define MaxSize 50

typedef int ElemType;

//规定顺序表元素结构
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

//创建顺序表
bool CreateList(SqList *&L,ElemType exa[],int n);

//初始化顺序表
bool InitList(SqList *&L);

//销毁顺序表
bool DestroyList(SqList *&L);

//判断顺序表是否为空
bool ListEmpty(SqList *L);

//求线性表长度
int ListLength(SqList *L);

//输出线性表
bool PrintList(SqList *L);

//求线性表中的某个元素值
bool GetElem(SqList *L,int i,ElemType &e);

//按元素值查找，返回逻辑序号
int LocateElem(SqList *L,ElemType e);

//插入数据元素
bool ListInsert(SqList *&L,int i,ElemType e);

//删除数据元素
bool ListDelete(SqList *&L,int i,ElemType &e);


