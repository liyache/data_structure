//
// Created by LittleChen on 2023/3/25.
//

#ifndef DATA_STRUCTURE_HUFFMANTREE_H
#define DATA_STRUCTURE_HUFFMANTREE_H

#endif //DATA_STRUCTURE_HUFFMANTREE_H

#include "iostream"

namespace HuffmanTree {
    typedef struct {
        char data;
        double weight;
        int parent;
        int lChild;
        int rChild;
    } HTNode;

    typedef struct {
        char code[20]; //当在动态分配指针数组里面再动态分配数组会导致内部动态分配调用后丢失。
        int start;
    } HCode;

    class huffmanTree {
    private:
        HTNode *ht;
        int n0;
        HCode *hcd;
    public:
        huffmanTree(char nodes[], double weights[], int n0);

        bool createHT();

        bool createHCode();

        bool printHCode();
    };

    huffmanTree::huffmanTree(char *nodes, double *weights, int n0) {
        this->ht = new HTNode[2 * n0 - 1];
        this->n0 = n0;
        this->hcd = new HCode[n0];
        for (int i = 0; i < n0; i++) {
            this->ht[i].data = nodes[i];
            this->ht[i].weight = weights[i];
        }
        for (int i = 0; i < 2 * n0 - 1; i++) {
            this->ht[i].parent = -1;
            this->ht[i].lChild = -1;
            this->ht[i].rChild = -1;
        }
    }

    bool huffmanTree::createHT() {
        int i, k, lNode, rNode;
        double min1, min2;
        for (i = this->n0; i <= (2 * (this->n0) - 2); i++) {
            min1 = min2 = INT_MAX;
            lNode = rNode = -1;
            for (k = 0; k <= i - 1; k++) {
                if (this->ht[k].parent == -1) {
                    if (this->ht[k].weight < min1) {
                        min2 = min1;
                        rNode = lNode;
                        min1 = this->ht[k].weight;
                        lNode = k;
                    } else if (this->ht[k].weight < min2) {
                        min2 = this->ht[k].weight;
                        rNode = k;
                    }
                }
            }
            this->ht[i].weight = this->ht[lNode].weight + this->ht[rNode].weight;
            this->ht[i].lChild = lNode;
            this->ht[i].rChild = rNode;
            this->ht[lNode].parent = i;
            this->ht[rNode].parent = i;
        }
        return true;
    }

    bool huffmanTree::createHCode() {
        HCode hc;
        int i, f, c;
        for (i = 0; i < n0; i++) {
            hc.start = n0 - 1;
            c = i;
            f = this->ht[i].parent;
            while (f != -1) {
                int temporary = this->ht[f].lChild;
                if (temporary == c) {
                    hc.code[hc.start--] = '0';
                } else {
                    hc.code[hc.start--] = '1';
                }
                c = f;
                f = this->ht[f].parent;
            }
            hc.start++;
            this->hcd[i] = hc;
        }
        return true;
    }

    bool huffmanTree::printHCode() {
        std::cout << std::endl;
        for (int i = 0; i < this->n0; i++) {
            std::cout << this->ht[i].data << " : ";
            for (int j = hcd[i].start; j < this->n0; j++) {
                std::cout << this->hcd[i].code[j];
            }
            std::cout << std::endl;
        }
        return true;
    }
}