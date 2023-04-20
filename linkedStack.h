//
// Created by LittleChen on 2023/2/24.
//

#ifndef DATA_STRUCTURE_LINKEDSTACK_H
#define DATA_STRUCTURE_LINKEDSTACK_H

#endif //DATA_STRUCTURE_LINKEDSTACK_H

typedef int ElemType;

typedef struct Stack {
    ElemType data;
    struct Stack *next;
} LinkStNode;

//初始化栈
bool InitStack(LinkStNode *&S);

//销毁栈
bool DestroyStack(LinkStNode *&S);

//进栈
bool Push(LinkStNode *&S,ElemType exa);

//出栈
bool Pop(LinkStNode *&S,ElemType &exa);

//取栈顶元素
bool GetTop(LinkStNode *S,ElemType &exa);

//输出栈
bool PrintStack(LinkStNode *S);