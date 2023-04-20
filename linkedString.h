//
// Created by LittleChen on 2023/3/2.
//

#ifndef DATA_STRUCTURE_LINKEDSTRING_H
#define DATA_STRUCTURE_LINKEDSTRING_H

#endif //DATA_STRUCTURE_LINKEDSTRING_H

typedef struct strNode {
    char data;
    struct strNode *next;
} LkString;

//生成串
bool StrAssign(LkString *&L, char exa[]);

//销毁串
bool DestroyStr(LkString *&L);

//串的复制
bool StrCopy(LkString *&L, LkString *T);

//判断串是否相等
bool StrEqual(LkString *L, LkString *T);

//求串的长度
int StrLength(LkString *L);

//串的连接
LkString *Concat(LkString *L, LkString *T);

//求子串
LkString *SubStr(LkString *L, int i, int j);

//插入子串
LkString *InsStr(LkString *L, int i, LkString *T);

//删除子串
LkString *DelStr(LkString *L, int i, int j);

//替换子串
LkString *RepStr(LkString *L, int i, int j, LkString *T);

//输出子串
bool PrintStr(LkString *L);