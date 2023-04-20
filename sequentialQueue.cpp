//
// Created by LittleChen on 2023/2/27.
//
#include <cstdlib>
#include "stdio.h"
#include "sequentialQueue.h"

//初始化队列
bool InitQueue(SqQueue *&Q) {
    Q = (SqQueue *) malloc(sizeof(SqQueue));

    Q->front = 0;
    Q->rear = 0;
    return true;
};

//销毁队列
bool DestroyQueue(SqQueue *&Q) {
    free(Q);
    return true;
};

//进队列
bool enQueue(SqQueue *&Q, ElemType exa) {
    if (Q->front == (Q->rear + 1) % Maxsize) {
        return false;
    } else {
        Q->rear = (Q->rear + 1) % Maxsize;
        Q->data[Q->rear] = exa;
        return true;
    }
};

//出队列
bool deQueue(SqQueue *&Q, ElemType &exa) {
    if (Q->front == Q->rear) {
        return false;
    } else {
        Q->front = (Q->front + 1) % Maxsize;
        exa = Q->data[Q->front];
        return true;
    }
};

//输出队列
bool PrintQueue(SqQueue *Q) {
    int temporary;
    temporary = Q->front;

    while (temporary != Q->rear) {
        printf(" %d <-", Q->data[temporary]);
        temporary++;
    }
    printf(" %d\n", Q->data[temporary]);
    return true;
}