//
// Created by LittleChen on 2023/2/24.
//

#include <cstdlib>
#include "stdio.h"
#include "linkedStack.h"

//初始化栈
bool InitStack(LinkStNode *&S) {
    S = (LinkStNode *) malloc(sizeof(LinkStNode));
    S->next = NULL;
    S->data = 0;
    return true;
};

//销毁栈
bool DestroyStack(LinkStNode *&S) {
    LinkStNode *temporary;
    temporary = S->next;
//    关于这里需要说明一下，俩个指针同时指向一个点，用free函数释放其中一个，会导致另一个也无法访问该点。
    while (S->next != NULL) {
        free(S);
        S = temporary;
        temporary = temporary->next;
    }
    free(S);
    return true;
};

//进栈
bool Push(LinkStNode *&S, ElemType exa) {
    LinkStNode *temporary;
    temporary = (LinkStNode *) malloc(sizeof(LinkStNode));
    temporary->data = exa;

    temporary->next = S->next;
    S->next = temporary;
    return true;
};

//出栈
bool Pop(LinkStNode *&S, ElemType &exa) {
    exa = S->next->data;
    S->next = S->next->next;
    return true;
};

//取栈顶元素
bool GetTop(LinkStNode *S, ElemType &exa) {
    exa = S->next->data;
    return true;
};

//输出栈
bool PrintStack(LinkStNode *S){
    while (S != NULL){
        printf(" %d |",S->data);
        S = S->next;
    }
    return true;
};