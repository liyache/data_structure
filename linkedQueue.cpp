//
// Created by LittleChen on 2023/2/27.
//
#include <cstdlib>
#include "stdio.h"
#include "linkedQueue.h"

//初始化队列
bool InitQueue(LinkQueue *&Q) {
    Q = (LinkQueue *) malloc(sizeof(LinkQueue));
//    注意看这里要给指针的指针的指针来分配内存，否则Q->front->next就会找不到，报错。
    Q->front = (DataNode *) malloc(sizeof(DataNode));
    Q->rear = (DataNode *) malloc(sizeof(DataNode));
    Q->front->next = NULL;
    Q->rear->next = NULL;
    return true;
};

//销毁队列
bool DestroyQueue(LinkQueue *&Q) {
    DataNode *temporary, *store;
    temporary = Q->front;

    while (temporary->next != Q->rear->next) {
        store = temporary->next;
        free(temporary);
        temporary = store;
    };
    free(temporary->next);
    free(Q->rear->next);
    return true;
};

//进队列
bool enQueue(LinkQueue *&Q, ElemType eva) {
    DataNode *temporary;
    temporary = (DataNode *) malloc(sizeof(DataNode));
    temporary->data = eva;

    if (Q->front->next == NULL) {
        Q->front->next = Q->rear->next = temporary;
        Q->rear = Q->rear->next;
    } else {
        Q->rear->next = temporary;
        Q->rear = temporary;
    }
    return true;
};

//出队列
bool deQueue(LinkQueue *&Q, ElemType &eva) {
    if (Q->front->next == NULL) {
        return false;
    } else {
        eva = Q->front->next->data;
        Q->front->next = Q->front->next->next;
    }
    return true;
};

//输出队列
bool PrintQueue(LinkQueue *Q) {
    DataNode *temporary;
    temporary = Q->front;
    while (temporary->next != NULL) {
        printf(" %d <-", temporary->next->data);
        temporary = temporary->next;
    }
    printf("\n");
    return true;
};

//尾指针初始化
bool InitQueue(SingleRear *&Q) {
    Q = (SingleRear *) malloc(sizeof(SingleRear));
    Q->rear == NULL;
    return true;
};

//销毁单尾指针队列
bool DestroyQueue(SingleRear *&Q) {
    DataNode *temporary;
    temporary = Q->rear->next;

    while (temporary != NULL) {
        free(Q->rear);
        Q->rear = temporary;
        temporary = temporary->next;
    }
    free(Q->rear);
    return true;
};

//进单尾指针队列
bool enQueue(SingleRear *&Q, ElemType eva) {
    DataNode *temporary;
    temporary = (DataNode *) malloc(sizeof(DataNode));

    temporary->data = eva;
    if (Q->rear == NULL) {
        temporary->next = temporary;
        Q->rear = temporary;
    } else {
        temporary->next = Q->rear->next;
        Q->rear->next = temporary;
        Q->rear = temporary;
    }
    return true;
};

//出单尾指针队列
bool deQueue(SingleRear *&Q, ElemType &eva) {
    DataNode *temporary;

    if (Q->rear->next == Q->rear) {
        eva = Q->rear->data;
        Q->rear == NULL;
    } else {
        temporary = Q->rear->next;
        eva = temporary->data;
        Q->rear->next = Q->rear->next->next;
    }
    return true;
};

//输出单尾指针队列
bool PrintQueue(SingleRear *Q) {
    DataNode *temporary;
    temporary = Q->rear->next;
    while (temporary != Q->rear) {
        printf(" %d <-", temporary->data);
        temporary = temporary->next;
    }
    printf(" %d \n", temporary->data);
    return true;
};