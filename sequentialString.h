//
// Created by LittleChen on 2023/2/28.
//

#ifndef DATA_STRUCTURE_SEQUENTIALSTRING_H
#define DATA_STRUCTURE_SEQUENTIALSTRING_H

#endif //DATA_STRUCTURE_SEQUENTIALSTRING_H

#define MaxSize 50

typedef struct {
    char data[MaxSize];
    int length;
} SqString;

//生成串
bool StrAssign(SqString &S, char str[]);

//复制串
bool StrCopy(SqString &S, SqString T);

//判断串相等
bool StrEqual(SqString S, SqString T);

//求串长
int StrLength(SqString S);

//串的连接
SqString Concat(SqString S, SqString T);

//求子串
SqString SubStr(SqString S, int i, int j);

//插入子串
SqString InsStr(SqString S, int i, SqString T);

//删除子串
SqString DelStr(SqString S, int i, int j);

//替换子串
SqString RepStr(SqString S, int i, int j, SqString T);

//输出子串
bool PrintStr(SqString S);