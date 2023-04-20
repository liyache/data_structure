//
// Created by LittleChen on 2023/3/2.
//
#include <cstdlib>
#include "stdio.h"
#include "linkedString.h"

//生成串
bool StrAssign(LkString *&L, char exa[]) {
    L = (LkString *) malloc(sizeof(LkString));
    LkString *temporary, *location;
    location = L;
    int i = 0;
    while (exa[i] != '\0') {
        temporary = (LkString *) malloc(sizeof(LkString));
        temporary->data = exa[i];

        location->next = temporary;
        location = temporary;

        i++;
    }
    return true;
};

//销毁串
bool DestroyStr(LkString *&L) {
    LkString *temporary;
    temporary = L->next;
    while (L->next != NULL) {
        free(L);
        L = temporary;
        temporary = temporary->next;
    }
    free(L);
    return true;
};

//串的复制
bool StrCopy(LkString *&L, LkString *T) {
    LkString *temporary, *location, *TLocation;
    L = (LkString *) malloc(sizeof(LkString));
    location = L;
    TLocation = T->next;
    while (TLocation != NULL) {
        temporary = (LkString *) malloc(sizeof(LkString));
        temporary->data = TLocation->data;

        location->next = temporary;
        location = temporary;

        TLocation = TLocation->next;
    }
    return true;
};

//判断串是否相等
bool StrEqual(LkString *L, LkString *T) {
    LkString *location, *TLocation;
    location = L->next;
    TLocation = T->next;

    while (location->data == TLocation->data && location != NULL && TLocation != NULL) {
        location = location->next;
        TLocation = location->next;
    }
    if (location == NULL && TLocation == NULL) {
        return true;
    } else {
        return false;
    }
};

//求串的长度
int StrLength(LkString *L) {
    LkString *temporary;
    temporary = L->next;
    int result = 0;
    while (temporary != NULL) {
        result++;
        temporary = temporary->next;
    }
    return result;
};

//串的连接
LkString *Concat(LkString *L, LkString *T) {
    LkString *result, *RLocation, *location, *TLocation, *temporary;
    result = (LkString *) malloc(sizeof(LkString));
    RLocation = result;
    location = L->next;
    TLocation = T->next;

    while (location != NULL) {
        temporary = (LkString *) malloc(sizeof(LkString));
        temporary->data = location->data;

        RLocation->next = temporary;
        RLocation = temporary;
        location = location->next;
    }
    while (TLocation != NULL) {
        temporary = (LkString *) malloc(sizeof(LkString));
        temporary->data = TLocation->data;

        RLocation->next = temporary;
        RLocation = temporary;
        TLocation = TLocation->next;
    }
    RLocation->next = NULL;
    return result;
};

//求子串
LkString *SubStr(LkString *L, int i, int j) {
    LkString *result, *temporary, *shorTime, *RLocation;
    result = (LkString *) malloc(sizeof(LkString));
    temporary = L;
    RLocation = result;
    for (int location = 0; location < i; location++) {
        temporary = temporary->next;
    }
    for (int num = 0; num < j; num++) {
        shorTime = (LkString *) malloc(sizeof(LkString));
        shorTime->data = temporary->data;

        RLocation->next = shorTime;
        RLocation = shorTime;
        temporary = temporary->next;
    }
    return result;
};

//插入子串
LkString *InsStr(LkString *L, int i, LkString *T) {
    LkString *result, *temporary, *storage, *RLocation, *TLocation;
    result = (LkString *) malloc(sizeof(LkString));
    temporary = L->next;
    RLocation = result;
    TLocation = T->next;
    for (int num = 0; num < i - 1; num++) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = temporary->data;

        RLocation->next = storage;
        RLocation = storage;
        temporary = temporary->next;
    }
    while (TLocation != NULL) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = TLocation->data;

        RLocation->next = storage;
        RLocation = storage;
        TLocation = TLocation->next;
    }
    while (temporary != NULL) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = temporary->data;

        RLocation->next = storage;
        RLocation = storage;
        temporary = temporary->next;
    }
    return result;
};

//删除子串
LkString *DelStr(LkString *L, int i, int j) {
    LkString *result, *temporary, *location, *storage;
    result = (LkString *) malloc(sizeof(LkString));
    temporary = result;
    location = L->next;
    for (int num = 0; num < i-1; num++) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = location->data;

        temporary->next = storage;
        temporary = storage;
        location = location->next;
    }
    for (int num = 0; num < j; num++) {
        location = location->next;
    }
    while (location != NULL) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = location->data;

        temporary->next = storage;
        temporary = storage;
        location = location->next;
    }
    return result;
};

//替换子串
LkString *RepStr(LkString *L, int i, int j, LkString *T) {
    LkString *result, *temporary, *location, *TLocation, *storage;
    result = (LkString *) malloc(sizeof(LkString));
    temporary = result;
    location = L->next;
    TLocation = T->next;

    for (int num = 0; num < i - 1; num++) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = location->data;

        temporary->next = storage;
        temporary = storage;
        location = location->next;
    }
    while (TLocation != NULL) {
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = TLocation->data;

        temporary->next = storage;
        temporary = storage;
        TLocation = TLocation->next;
    }
    for (int num = 0; num < j; num++) {
        location = location->next;
    }
    while (location != NULL){
        storage = (LkString *) malloc(sizeof(LkString));
        storage->data = location->data;

        temporary->next = storage;
        temporary = storage;
        location = location->next;
    }
    return result;
};

//输出子串
bool PrintStr(LkString *L) {
    LkString *temporary;
    temporary = L->next;
    while (temporary != NULL) {
        printf("%c", temporary->data);
        temporary = temporary->next;
    }
    printf("\n");
    return true;
};