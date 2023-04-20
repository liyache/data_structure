//
// Created by LittleChen on 2023/2/24.
//

#ifndef DATA_STRUCTURE_SEQUENTIALSTACK_H
#define DATA_STRUCTURE_SEQUENTIALSTACK_H

#endif //DATA_STRUCTURE_SEQUENTIALSTACK_H

#define MaxSize 50
typedef int ElemType;

//顺序栈
typedef struct stack {
    ElemType data[MaxSize];
    int tip;
} SqStack;

//初始化栈
bool InitStack(SqStack *&S);

//销毁栈
bool Destroy(SqStack *&S);

//判断栈是否为空
bool StackEmpty(SqStack *S);

//进栈操作
bool Push(SqStack *&S, ElemType exa);

//出栈操作
bool Pop(SqStack *&S, ElemType &exa);

//取栈顶元素
bool GetTop(SqStack *S, ElemType &exa);

//输出栈
bool PrintStack(SqStack *S);