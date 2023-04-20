//
// Created by LittleChen on 2023/2/24.
//

#include <cstdlib>
#include "stdio.h"
#include "sequentialStack.h"

//初始化栈
bool InitStack(SqStack *&S) {
    S = (SqStack *) malloc(sizeof(SqStack));
    S->tip = -1;
};

//销毁栈
bool Destroy(SqStack *&S) {
    free(S);
};

//判断栈是否为空
bool StackEmpty(SqStack *S) {
    if (S->tip == -1) {
        return true;
    } else {
        return false;
    }
};

//进栈操作
bool Push(SqStack *&S, ElemType exa) {
    if (S->tip == MaxSize - 1) {
        return false;
    } else {
        S->tip++;
        S->data[S->tip] = exa;
        return true;
    }
};

//出栈操作
bool Pop(SqStack *&S, ElemType &exa) {
    if (S->tip == -1) {
        return false;
    } else {
        exa = S->data[S->tip];
        S->tip--;
        return true;
    }
};

//取栈顶元素
bool GetTop(SqStack *S, ElemType &exa) {
    if (S->tip == -1) {
        return false;
    } else {
        exa = S->data[S->tip];
    }
};

//输出栈
bool PrintStack(SqStack *S) {
    if (S->tip == -1) {
        printf("\n 栈是空的哦 \n");
        return false;
    } else {
        for (int i = 0; i <= S->tip; i++) {
            printf(" %d |", S->data[i]);
        }
        return true;
    }
};