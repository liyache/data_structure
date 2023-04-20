//
// Created by LittleChen on 2023/2/28.
//
#include "stdio.h"
#include "sequentialString.h"

//生成串
bool StrAssign(SqString &S, char str[]) {
    int temporary = 0;
    while (str[temporary] != '\0') {
        S.data[temporary] = str[temporary];
        temporary++;
    }
    S.length = temporary;
    return true;
};

//复制串
bool StrCopy(SqString &S, SqString T) {
    int temporary;
    while (T.data[temporary] != '\0') {
        S.data[temporary] = T.data[temporary];
        temporary++;
    }
    S.length = T.length;
    return true;
};

//判断串相等
bool StrEqual(SqString S, SqString T) {
    if (S.length != T.length) {
        return false;
    } else {
        int temporary = 0;
        while (S.data[temporary] == T.data[temporary]) {
            temporary++;
        }
        if (S.data[temporary] == T.data[temporary] == '\0') {
            return true;
        } else {
            return false;
        }
    }
};

//求串长
int StrLength(SqString S) {
    return S.length;
};

//串的连接
SqString Concat(SqString S, SqString T) {
    SqString result;
    int temF, temS;
    for (temF = 0; temF < S.length; temF++) {
        result.data[temF] = S.data[temF];
    }
    for (temS = 0; temS < T.length; temS++) {
        result.data[temF + temS] = T.data[temS];
    }
    result.length = S.length + T.length;
    return result;
};

//求子串
SqString SubStr(SqString S, int i, int j) {
    SqString result;
    for (int temporary = 0; temporary < j; temporary++) {
        result.data[temporary] = S.data[temporary + i - 1];
    }
    result.length = j;
    return result;
};

//插入子串
SqString InsStr(SqString S, int i, SqString T) {
    SqString result;
    int temporary, tem, record;
    for (temporary = 0; temporary < i - 1; temporary++) {
        result.data[temporary] = S.data[temporary];
    }
    for (tem = 0; tem < T.length; tem++) {
        result.data[temporary + tem] = T.data[tem];
        record = temporary + tem;
    }
    for (temporary; temporary < S.length; temporary++) {
        result.data[++record] = S.data[temporary];
    }
    result.length = S.length + T.length;
    return result;
};

//删除子串
SqString DelStr(SqString S, int i, int j) {
    SqString result;
    int temporary;
    int zero = 0;
    for (temporary = 0; temporary < i - 1; temporary++) {
        result.data[temporary] = S.data[temporary];
    }
    while (zero < j) {
        zero++;
        temporary++;
    }
    for (temporary; temporary < S.length; temporary++) {
        result.data[temporary - j] = S.data[temporary];
    }
    result.length = S.length - j;
    return result;
};

//替换子串
SqString RepStr(SqString S, int i, int j, SqString T) {
    SqString result;
    int temporary;
    for (temporary = 0; temporary < i - 1; temporary++) {
        result.data[temporary] = S.data[temporary];
    }
    int brevity;
    for (brevity = 0; brevity < T.length; brevity++) {
        result.data[brevity + temporary] = T.data[brevity];
    }
    int num = brevity + temporary;
    for (int interim = temporary + j; interim < S.length; interim++) {
        result.data[num++] = S.data[interim];
    }
    result.length = S.length - j + T.length;
    return result;
};

//输出子串
bool PrintStr(SqString S) {
    printf("\"");
    for (int i = 0; i < S.length; i++) {
        printf("%c", S.data[i]);
    }
    printf("\"\n");
    return true;
};
