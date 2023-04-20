//
// Created by LittleChen on 2023/2/27.
//

#ifndef DATA_STRUCTURE_SEQUENTIALQUEUE_H
#define DATA_STRUCTURE_SEQUENTIALQUEUE_H

#endif //DATA_STRUCTURE_SEQUENTIALQUEUE_H

#define Maxsize 50

typedef int ElemType;

typedef struct {
    ElemType data[Maxsize];
    int front, rear;
} SqQueue;

//初始化队列
bool InitQueue(SqQueue *&Q);

//销毁队列
bool DestroyQueue(SqQueue *&Q);

//进队列
bool enQueue(SqQueue *&Q, ElemType exa);

//出队列
bool deQueue(SqQueue *&Q, ElemType &exa);

//输出队列
bool PrintQueue(SqQueue *Q);