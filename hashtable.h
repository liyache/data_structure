//
// Created by LittleChen on 2023/4/17.
//

#ifndef DATA_STRUCTURE_HASHTABLE_H
#define DATA_STRUCTURE_HASHTABLE_H

#endif //DATA_STRUCTURE_HASHTABLE_H

#include "iostream"

namespace hash {
    constexpr int NullKey = -1;
    constexpr int DelKey = -2;
    typedef int KeyType;

    struct HashTableOpen {
        KeyType key;
        int count;
    };

    struct HashTableZ {
        KeyType key;
        HashTableZ *next;
    };

    struct HashTableZipper {
        HashTableZ *first;
    };

    class HashTable {
    private:
        HashTableOpen *open;
        HashTableZipper *zipper;

        bool InsertHT(int m, int p, KeyType k) {
            int i, address;
            address = k % p;
            if (open[address].key == NullKey || open[address].key == DelKey) {
                open[address].key = k;
                open[address].count = 1;
            } else {
                i = 1;
                do {
                    address = (address + 1) % m;
                    i++;
                } while (open[address].key != NullKey && open[address].key != DelKey);
                open[address].key = k;
                open[address].count = i;
            }
        };

        bool InsertHT(int p, KeyType k) {
            int address;
            address = k % p;
            HashTableZ *q;
            q = new HashTableZ;
            q->key = k;
            q->next = NULL;
            if (zipper[address].first == NULL) {
                zipper[address].first = q;
            } else {
                q->next = zipper[address].first;
                zipper[address].first = q;
            }
        };
    public:
        HashTable(int m, int p, KeyType keys[], int n) {
            open = new HashTableOpen[m];
            for (int i = 0; i < m; ++i) {
                open[i].key = NullKey;
                open[i].count = 0;
            }

            zipper = new HashTableZipper[m];
            for (int i = 0; i < m; ++i) {
                zipper->first = NULL;
            }

            for (int i = 0; i < n; ++i) {
                InsertHT(m, p, keys[i]);
            }

            for (int i = 0; i < n; ++i) {
                InsertHT(p, keys[i]);
            }
        };

        bool DeleteHT(int m, int p, KeyType k) {
            int address;
            address = k % p;

            while (open[address].key != NullKey && open[address].key != k) {
                address = (address + 1) % m;
            }
            if (open[address].key == k) {
                open[address].key = DelKey;
                return true;
            } else
                return false;
        };

        bool DeleteHT(int p, KeyType k) {
            int address;
            address = k % p;
            HashTableZ *q, *pre;

            q = zipper[address].first;
            if (q == nullptr) {
                return false;
            }
            if (q->key == k) {
                zipper[address].first = q->next;
                delete q;
                return true;
            }
            pre = q;
            q = q->next;
            while (q != nullptr) {
                if (q->key == k)
                    break;
                pre = q;
                q = q->next;
            }
            if (q != nullptr) {
                pre->next = q->next;
                delete q;
                return true;
            } else
                return false;
        }

        bool SearchHT(int m, int p, KeyType k) {
            int i = 1, address;
            address = k % p;
            while (open[address].key != NullKey && open[address].key != k) {
                i++;
                address = (address + 1) % m;
            }
            using namespace std;
            if (open[address].key == k) {
                cout << "successfully,key: " << open[address].key << "compared: " << open[address].count << endl;
            } else
                cout << "failure,key: " << k << "compared: " << i << endl;

            {
                i = 0;
                address = k % p;
                HashTableZ *q;
                q = zipper[address].first;
                while (q != nullptr) {
                    i++;
                    if (q->key == k) {
                        break;
                    }
                    q = q->next;
                }
                if (q != nullptr)
                    cout << "successfully,key: " << q->key << "compared: " << i << endl;
                else
                    cout << "failure,key: " << k << "compared: " << i << endl;
            }
        };

        ~HashTable() {
            delete[] open;
            delete[] zipper;
        };
    };

}
