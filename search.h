//
// Created by LittleChen on 2023/4/1.
//

#ifndef DATA_STRUCTURE_SEARCH_H
#define DATA_STRUCTURE_SEARCH_H

#endif //DATA_STRUCTURE_SEARCH_H
//数据结构查找部分的集合
#include "iostream"

namespace search {
    template<typename T>
    struct KeyType {
        T key;
        std::string something;
    };

    template<typename T>
    class seaList {
    private:
        KeyType<T> *keyList;

    public:
        explicit seaList(const T list[], int n) {
            this->keyList = new KeyType<T>[n];
            for (int i = 0; i < n; ++i) {
                this->keyList[i].key = list[i];
            }
        }

//        顺序查找
        int SeqSearch(T target, int n) {
            int i = 0;
            while (i < n && keyList[i].key != target) {
                i++;
            }
            if (i >= n)
                return -1;
            else
                return i;
        };

//        折半查找 要求是有序表，否则不好使
        int halfSearch(T target, int n) {
            int low = 0, high = n - 1, mid;
            while (low <= high) {
                mid = (low + high) / 2;
                if (target == keyList[mid].key)
                    return mid;
                if (target < keyList[mid].key)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return -1;
        };

        friend std::ostream &operator<<(std::ostream &os, const seaList &list) {

            return os;
        }
    };

    template<typename T>
    struct BSTNode {
        T data;
        BSTNode *lChild, *rChild;
    };

    template<typename T>
    class seaBinary {
    private:
        BSTNode<T> *bstNode;

        bool InsertBST(BSTNode<T> *&bt, T k) {
            if (bt == NULL) {
                bt = new BSTNode<T>;
                bt->data = k;
                bt->lChild = bt->rChild = NULL;
                return true;
            } else if (k == bt->data) {
                return false;
            } else if (k < bt->data) {
                return InsertBST(bt->lChild, k);
            } else
                return InsertBST(bt->rChild, k);
        };

    public:
        seaBinary(T A[], int n) {
            bstNode = NULL;
            int i = 0;
            while (i < n) {
                InsertBST(bstNode, A[i]);
                i++;
            }
        };

        BSTNode<int> *getBstNode() const {
            return bstNode;
        }

        BSTNode<T> *&SearchBST(BSTNode<T> *&bt, T k) {
            if (bt == NULL || bt->data == k) {
                return bt;
            }
            if (k < bt->data) {
                return SearchBST(bt->lChild, k);
            } else
                return SearchBST(bt->rChild, k);
        };
    };
}