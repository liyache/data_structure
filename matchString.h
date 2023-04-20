//
// Created by LittleChen on 2023/3/19.
//

#ifndef DATA_STRUCTURE_MATCHSTRING_H
#define DATA_STRUCTURE_MATCHSTRING_H

#endif //DATA_STRUCTURE_MATCHSTRING_H

#include "iostream"

class matchString {
private:
    std::string tarString;
    std::string patString;
    int result;
    int *next = new int[patString.length()];

    void getNext() {
        int j, k;
        j = 0;
        k = -1;
        next[0] = -1;
        while (j < patString.length() - 1) {
            if (k == -1 || patString[j] == patString[k]) {
                j++;
                k++;
                next[j] = k;
            } else
                k = next[k];
        }
    }

public:
    matchString(const std::string tarString, const std::string parString);

    matchString();

    int BF();

    int Kmp();

};

matchString::matchString(const std::string tarString, const std::string parString) {
    this->tarString = tarString;
    this->patString = parString;
    this->result = 0;
}

matchString::matchString() {
    this->tarString = "";
    this->patString = "";
    this->result = 0;
}


int matchString::BF() {
    int i = 0, j = 0;
    while (i < this->tarString.length() && j < this->patString.length()) {
        if (tarString[i] == patString[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= this->patString.length()) {
        this->result = i - this->patString.length();
        std::cout << "匹配成功喽" << std::endl;
        return this->result;
    } else {
        std::cout << "匹配失败啦" << std::endl;
        return -1;
    }
}

int matchString::Kmp() {
    int n = 0, m = 0;
    getNext();
    int tarLen = this->tarString.length();
    int patLen = this->patString.length();
//    这里有个不可预知bug，必须把俩字符串的长度存在变量里作为保存，循环判断才可进行，否则m=-1<patString.length()就自动退出了
    while (m < patLen && n < tarLen) {
        if (m == -1 || this->tarString[n] == this->patString[m]) {
            n++;
            m++;
        } else {
            m = next[m];
        }
    }
    if (m >= this->patString.length()) {
        std::cout << "successfully" << std::endl;
        return n - this->patString.length();
    } else {
        std::cout << "fail" << std::endl;
        return -1;
    }
}

