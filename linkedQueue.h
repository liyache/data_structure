//
// Created by LittleChen on 2023/2/27.
//

#ifndef DATA_STRUCTURE_LINKEDQUEUE_H
#define DATA_STRUCTURE_LINKEDQUEUE_H

#endif //DATA_STRUCTURE_LINKEDQUEUE_H

typedef int ElemType;

typedef struct qNode {
    ElemType data;
    qNode *next;
} DataNode;

typedef struct {
    DataNode *front;
    DataNode *rear;
} LinkQueue;

//只带一个尾指针的队列
typedef struct {
    DataNode *rear;
} SingleRear;

//初始化队列
bool InitQueue(LinkQueue *&Q);

//销毁队列
bool DestroyQueue(LinkQueue *&Q);

//进队列
bool enQueue(LinkQueue *&Q, ElemType eva);

//出队列
bool deQueue(LinkQueue *&Q, ElemType &eva);

//输出队列
bool PrintQueue(LinkQueue *Q);

//尾指针初始化
bool InitQueue(SingleRear *&Q);

//销毁单尾指针队列
bool DestroyQueue(SingleRear *&Q);

//进单尾指针队列
bool enQueue(SingleRear *&Q, ElemType eva);

//出单尾指针队列
bool deQueue(SingleRear *&Q, ElemType &eva);

//输出单尾指针队列
bool PrintQueue(SingleRear *Q);