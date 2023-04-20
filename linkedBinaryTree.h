//
// Created by LittleChen on 2023/3/20.
//

#ifndef DATA_STRUCTURE_LINKEDBINARYTREE_H
#define DATA_STRUCTURE_LINKEDBINARYTREE_H

#endif //DATA_STRUCTURE_LINKEDBINARYTREE_H

#include "iostream"

#define MaxSize 20
namespace BinaryTree {
    typedef struct node {
        char data;
        node *lChild;
        node *rChild;
    } BtNode;

    class binaryTree {
    private:
        BtNode *btNode;
    public:
//        无参构造器
        binaryTree();

//有参构造器，利用字符串生成树结构
        binaryTree(const std::string &str);

//递归销毁树
        bool destroyTree(BtNode *&btNode1);

//输出树结构
        bool printTree(BtNode *&btNode1);

//得到树根结点
        BtNode *const getBtNode() const;

//找到对应树结点
        BtNode *findNode(BtNode *node, char target);

//输出树高度
        int printHeight(BtNode *node);

//先序遍历树
        bool preOrder(BtNode *node);

//中序遍历树
        bool inOrder(BtNode *node);

//后序遍历树
        bool postOrder(BtNode *node);

//先序遍历非递归算法
        bool preOrderNoRecur(BtNode *node);

//中序遍历非递归算法
        bool inOrderNoRecur(BtNode *node);

//后序遍历非递归算法
        bool postOrderNoRecur(BtNode *node);

//层次遍历非递归算法
        bool levelOrder(BtNode *node);

//析构函数，调用销毁树方法，自动销毁树
        ~binaryTree();
    };

    binaryTree::binaryTree() {
        this->btNode = NULL;
    }

    binaryTree::binaryTree(const std::string &str) {
        BtNode *stack[MaxSize], *temporary;
        int top = -1, k, j = 0; //top为栈顶指针
        char ch;
        ch = str[j];
        this->btNode = NULL;
        while (ch != '\0') {
            switch (ch) {
                case '(':
                    top++;
                    stack[top] = temporary;
                    k = 1;
                    break;
                case ')':
                    top--;
                    break;
                case ',':
                    k = 2;
                    break;
                default:
                    temporary = new BtNode;
                    temporary->data = ch;
                    temporary->lChild = temporary->rChild = NULL;
                    if (this->btNode == NULL) {
                        this->btNode = temporary;
                    } else {
                        switch (k) {
                            case 1:
                                stack[top]->lChild = temporary;
                                break;
                            case 2:
                                stack[top]->rChild = temporary;
                                break;
                            default:
                                break;
                        }
                    }
            }
            j++;
            ch = str[j];
        }
    }

    binaryTree::~binaryTree() {
        destroyTree(this->btNode);
    }

    bool binaryTree::destroyTree(BtNode *&btNode1) {
        if (btNode1 != NULL) {
            destroyTree(btNode1->lChild);
            destroyTree(btNode1->rChild);
            delete btNode1;
        }
        return true;
    }

    bool binaryTree::printTree(BtNode *&btNode1) {
        using std::cout;
        if (btNode1 != NULL) {
            cout << btNode1->data;
            if (btNode1->lChild != NULL || btNode1->rChild != NULL) {
                cout << "(";
                printTree(btNode1->lChild);
                if (btNode1->rChild != NULL) {
                    cout << ",";
                }
                printTree(btNode1->rChild);
                cout << ")";
            }
        }
        return true;
    }

    BtNode *const binaryTree::getBtNode() const {
        return btNode;
    }

    BtNode *binaryTree::findNode(BtNode *node, char target) {
        BtNode *temporary;
        if (node == NULL) {
            return NULL;
        } else if (node->data == target) {
            return node;
        } else {
            temporary = findNode(node->lChild, target);
            if (temporary != NULL) {
                return temporary;
            } else {
                return findNode(node->rChild, target);
            }
        }
    }

    int binaryTree::printHeight(BtNode *node) {
        int lChild, rChild;
        if (node == NULL) {
            return 0;
        } else {
            lChild = printHeight(node->lChild);
            rChild = printHeight(node->rChild);
            return lChild > rChild ? (lChild + 1) : (rChild + 1);
        }
    }

    bool binaryTree::preOrder(BtNode *node) {
        using std::cout;
        if (node != NULL) {
            cout << node->data << " -> ";
            preOrder(node->lChild);
            preOrder(node->rChild);
        }
        return true;
    }

    bool binaryTree::inOrder(BtNode *node) {
        using std::cout;
        if (node != NULL) {
            inOrder(node->lChild);
            cout << node->data << " -> ";
            inOrder(node->rChild);
        }
        return true;
    }

    bool binaryTree::postOrder(BtNode *node) {
        using std::cout;
        if (node != NULL) {
            postOrder(node->lChild);
            postOrder(node->rChild);
            cout << node->data << " -> ";
        }
        return true;
    }

    bool binaryTree::preOrderNoRecur(BtNode *node) {
        using std::cout;

        BtNode *temporary;
        BtNode *stack[MaxSize];
        int k = -1;
        if (node != NULL) {
            k++;
            stack[k] = node;
            while (k != -1) {
                temporary = stack[k];
                k--;
                cout << temporary->data << " -> ";
                if (temporary->rChild != NULL) {
                    k++;
                    stack[k] = temporary->rChild;
                }
                if (temporary->lChild != NULL) {
                    k++;
                    stack[k] = temporary->lChild;
                }
            }
        }
        return true;
    }

    bool binaryTree::inOrderNoRecur(BtNode *node) {
        using std::cout;

        BtNode *temporary;
        BtNode *stack[MaxSize];
        int k = -1;
        temporary = node;

        while (k != -1 || temporary != NULL) {
            while (temporary != NULL) {
                k++;
                stack[k] = temporary;
                temporary = temporary->lChild;
            }
            if (k != -1) {
                temporary = stack[k];
                k--;
                cout << temporary->data << " -> ";
                temporary = temporary->rChild;
            }
        }
        return true;
    }

    bool binaryTree::postOrderNoRecur(BtNode *node) {
        using std::cout;

        BtNode *temporary, *record;
        BtNode *stack[MaxSize];
        int k = -1;

        temporary = node;
        bool flag;

        do {
            while (temporary != NULL) {
                k++;
                stack[k] = temporary;
                temporary = temporary->lChild;
            }
            record = NULL;
            flag = true;
            while (k != -1 && flag) {
                temporary = stack[k];
                if (temporary->rChild == record) {
                    cout << temporary->data << " -> ";
                    temporary = stack[k];
                    k--;
                    record = temporary;
                } else {
                    temporary = temporary->rChild;
                    flag = false;
                }
            }
        } while (k != -1);
        return true;
    }

    bool binaryTree::levelOrder(BtNode *node) {
        using std::cout;
        BtNode *temporary;
        BtNode *queue[MaxSize];

        int rear, font;
        rear = font = -1;

        rear++;
        queue[rear] = node;
        while (rear != font) {
            font++;
            temporary = queue[font];
            cout << temporary->data << " -> ";
            if (temporary->lChild != NULL) {
                rear++;
                queue[rear] = temporary->lChild;
            }
            if (temporary->rChild != NULL) {
                rear++;
                queue[rear] = temporary->rChild;
            }
        }
        return true;
    }
}
