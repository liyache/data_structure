//
// Created by LittleChen on 2023/3/26.
//

#ifndef DATA_STRUCTURE_ADJACENCYLIST_H
#define DATA_STRUCTURE_ADJACENCYLIST_H

#endif //DATA_STRUCTURE_ADJACENCYLIST_H

#include "iostream"

#define MaxV 5
#define INF 32767

namespace adjacencyList {

//邻接表定义
    typedef struct ANode {
        int adjVex; //该边邻接点编号
        ANode *nextArc; //指向下一条边的指针
        int weight; //该边的权重
    } ArcNode;
    struct VNode {
        std::string info; //顶点的其他信息说明
        ArcNode *firstArc; //指向第一个边结点
    };
    typedef struct {
        VNode adjList[MaxV]; //邻接表的头结点数组
        int n, e; //邻接表的顶点树和边树
    } AdjGraph;

    struct queue {
        int data[MaxV];
        int rear, font;
    };

//类定义
    class adjacency {
    private:
        AdjGraph *G;
        int visited[MaxV] = {0};
        queue SQueue;

        bool InitQueue() {
            this->SQueue.rear = this->SQueue.font = -1;
        }

        bool enQueue(int v) {
            if (this->SQueue.rear < MaxV) {
                this->SQueue.rear++;
                this->SQueue.data[this->SQueue.rear] = v;
            }
        };

        bool deQueue(int &v) {
            if (this->SQueue.font != this->SQueue.rear) {
                this->SQueue.font++;
                v = this->SQueue.data[this->SQueue.font];
            }
        }

        bool queueEmpty() {
            if (this->SQueue.font == this->SQueue.rear)
                return true;
            else
                return false;
        }

    public:
        adjacency(int A[MaxV][MaxV], int n, int e); //构造函数创造图

        AdjGraph *getG() const; //get方法获取G图

        bool printAdj(); //输出图

        bool DFS(AdjGraph *G, int v); //深度优先遍历

        bool BFS(int v); //广度优先遍历

        ~adjacency(); //析构函数销毁图
    };

    AdjGraph *adjacency::getG() const {
        return G;
    }

    adjacency::adjacency(int A[MaxV][MaxV], int n, int e) {
        int i, j;
        ArcNode *p;
        this->G = new AdjGraph;
        for (i = 0; i < n; i++) {
            this->G->adjList[i].firstArc = NULL;
        }
        for (i = 0; i < n; i++)
            for (j = n - 1; j >= 0; j--)
                if (A[i][j] != 0 && A[i][j] != INF) {
                    p = new ArcNode;
                    p->adjVex = j;
                    p->weight = A[i][j];
                    p->nextArc = this->G->adjList[i].firstArc;
                    this->G->adjList[i].firstArc = p;
                }
        this->G->n = n;
        this->G->e = e;
    }

    bool adjacency::printAdj() {
        using namespace std;
        int i;
        ArcNode *p;
        for (i = 0; i < this->G->n; ++i) {
            p = this->G->adjList[i].firstArc;
            cout << i;
            while (p != NULL) {
                cout << " -> " << p->adjVex;
                p = p->nextArc;
            }
            cout << endl;
        }
        return true;
    }

    bool adjacency::DFS(AdjGraph *G, int v) {
        using namespace std;
        ArcNode *p;
        visited[v] = 1;
        cout << v;
        p = G->adjList[v].firstArc;
        while (p != NULL) {
            if (visited[p->adjVex] == 0)
                DFS(G, p->adjVex);
            p = p->nextArc;
        }
        return true;
    }

    bool adjacency::BFS(int v) {
        using namespace std;
        int w, i;
        ArcNode *p;
        InitQueue();
        for (i = 0; i < this->G->n; i++)
            this->visited[i] = 0;
        cout << v;
        this->visited[v] = 1;
        enQueue(v);
        while (!queueEmpty()) {
            deQueue(w);
            p = G->adjList[w].firstArc;
            while (p != NULL) {
                if (visited[p->adjVex] == 0) {
                    cout << p->adjVex;
                    visited[p->adjVex] = 1;
                    enQueue(p->adjVex);
                }
                p = p->nextArc;
            }
        }
        cout << endl;
        return true;
    }

    adjacency::~adjacency() {
        int i;
        ArcNode *pre, *p;
        for (i = 0; i < this->G->n; i++) {
            pre = this->G->adjList[i].firstArc;
            if (pre != NULL) {
                p = pre->nextArc;
                while (p != NULL) {
                    delete pre;
                    pre = p;
                    p = p->nextArc;
                }
                delete pre;
            }
        }
        delete this->G;
    }
}