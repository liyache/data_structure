//
// Created by LittleChen on 2023/3/27.
//

#ifndef DATA_STRUCTURE_ADJACENCYMATRIX_H
#define DATA_STRUCTURE_ADJACENCYMATRIX_H

#endif //DATA_STRUCTURE_ADJACENCYMATRIX_H

#include "iostream"

#define MaxV 10
#define INF 32767

namespace adjacencyMatrix {
    //邻接矩阵定义
    typedef struct {
        int no;
        std::string info;
    } VertexType;
    typedef struct {
        int edges[MaxV][MaxV];
        int n, e;
        VertexType vex[MaxV];
    } MatGraph;

    class matrix {
    private:
        MatGraph *G;

        bool DisPath(int dist[], int path[], int S[], int v);

        bool DisPath(int A[][MaxV], int path[][MaxV]);

    public:
        matrix(int A[][MaxV], int n, int e, int const no[]);

        ~matrix();

        bool Prim(int v);

        bool Kruskal();

//        最短路径
        bool Dijkstra(int v);

        bool Floyd();
    };

    matrix::matrix(int A[][MaxV], int n, int e, int const *no) {
        this->G = new MatGraph;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                this->G->edges[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            this->G->vex[i].no = no[i];
        }
        this->G->n = n;
        this->G->e = e;
    }

    matrix::~matrix() {
        delete this->G;
    }

    bool matrix::Prim(int v) {
        int lowCost[MaxV]; //保存最小边的权重
        int closest[MaxV]; //保存最小边对应的顶点

        int MIN;
        int i, j, k;

        for (i = 0; i < G->n; i++) {
            lowCost[i] = G->edges[v][i];
            closest[i] = v;
        }
        for (i = 1; i < G->n; i++) {
            MIN = INF;
            for (j = 0; j < G->n; j++) {
                if (lowCost[j] != 0 && lowCost[j] < MIN) {
                    MIN = lowCost[j];
                    k = j;
                }
            }
            std::cout << "边 " << closest[k] << "->" << k << " 的权重为：" << MIN << std::endl;
            lowCost[k] = 0;
            for (j = 0; j < G->n; j++) {
                if (lowCost[j] != 0 && G->edges[k][j] < lowCost[j]) {
                    lowCost[j] = G->edges[k][j];
                    closest[j] = k;
                }
            }
        }
        return true;
    }

    bool matrix::Kruskal() {
        return false;
    }

    bool matrix::Dijkstra(int v) {
        int dist[MaxV], path[MaxV];
        int S[MaxV];
        int MINdis, i, j, u;

        for (i = 0; i < G->n; ++i) {
            //初始化dist和path列表
            dist[i] = G->edges[v][i];
            S[i] = 0;
            if (G->edges[v][i] < INF) {
                path[i] = v;
            } else
                path[i] = -1;
        }
        //源点加入S
        S[v] = 1;
        path[v] = 0;
        for (i = 0; i < G->n - 1; i++) {
            MINdis = INF;
            //选取不在S中且具有最小路径长度的点
            for (j = 0; j < G->n; j++) {
                if (S[j] == 0 && dist[j] < MINdis) {
                    u = j;
                    MINdis = dist[u];
                }
            }
            //将其加入S
            S[u] = 1;
            //修改不在S中的顶点的最短路径
            for (j = 0; j < G->n; j++) {
                if (S[j] == 0)
                    if (G->edges[u][j] < INF && dist[u] + G->edges[u][j] < dist[j]) {
                        dist[j] = dist[u] + G->edges[u][j];
                        path[j] = u;
                    }
            }
        }
        DisPath(dist, path, S, v);
        return true;
    }

    bool matrix::DisPath(int *dist, int *path, int *S, int v) {
        int i, j, k;
        int aPath[MaxV], d;

        for (i = 0; i < G->n; i++) {
            if (S[i] == 1 && i != v) {
                std::cout << "从顶点 " << v << " 到顶点 " << i << "的路径长度为: " << dist[i];
                d = 0;
                aPath[d] = i;
                k = path[i];
                if (k == -1)
                    std::cout << "没有路径哦😯";
                else {
                    while (k != v) {
                        d++;
                        aPath[d] = k;
                        k = path[k];
                    }
                    d++;
                    aPath[d] = v;
                    std::cout << " 路径为: ";
                    while (d != -1) {
                        std::cout << aPath[d] << " ";
                        d--;
                    }
                }
                std::cout << std::endl;
            }
        }
        return true;
    }

    bool matrix::Floyd() {
        int A[MaxV][MaxV], path[MaxV][MaxV];
        int i, j, k;
        for (i = 0; i < G->n; i++) {
            for (j = 0; j < G->n; j++) {
                A[i][j] = G->edges[i][j];
                if (i != 1 && G->edges[i][j] < INF) {
                    path[i][j] = i;
                } else
                    path[i][j] = -1;
            }
        }
        for (k = 0; k < G->n; k++) {
            for (i = 0; i < G->n; i++)
                for (j = 0; j < G->n; j++) {
                    if (A[i][j] > A[i][k] + A[k][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                        path[i][j] = path[k][j];
                    }
                }
        }
        DisPath(A, path);
        return true;
    }

    bool matrix::DisPath(int (*A)[10], int (*path)[10]) {
        int i, j, k, s;
        int aPath[MaxV], d;

        for (i = 0; i < G->n; i++)
            for (j = 0; j < G->n; j++) {
                if (A[i][j] != INF && i != j) {
                    std::cout << "from " << i << " to " << j << " 's road: ";
                    k = path[i][j];
                    d = 0;
                    aPath[d] = j;
                    while (k != -1 && k != i) {
                        d++;
                        aPath[d] = k;
                        k = path[i][k];
                    }
                    d++;
                    aPath[d] = i;
                    while (d != -1) {
                        std::cout << aPath[d];
                        d--;
                    }
                    std::cout << " the distance is: " << A[i][j] << std::endl;
                }
            }
        return true;
    }
}