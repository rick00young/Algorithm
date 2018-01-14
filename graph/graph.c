#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//十字链表是针对有向图邻接表结构的优化,邻接多重表是针对
//无向图邻接表结构的优化


//建立无向网图的邻接矩阵
void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数与边数");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);

    //读入顶点信息,建立顶点表
    for (i = 0; i < G->numVertexes; i++){
        scanf(&G->vexs[i]);
    }
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = INFINITY;//邻接矩阵初始化
        }
    }
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi, vj)上的下标i, 下标j和权w:\n");
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];//无向图,矩阵对称
    }

}

//建立图的邻接表结构
void CreateAlGraph(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;
    printf("输入顶点数和边数\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        scanf("%c", &G->adjList[i].data);//输入顶点信息
        G->adjList[i].firstedge = NULL;//将边表置为空表
    }
    //建立边表
    for (k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi, vj)上的项点序号\n");
        scanf("%d,%d",&i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;//邻接序号为j
        //将e指针指向当前顶点指向的结点
        e->next = G->adjList[i].firstedge;
        //将当前的顶点的指针指向e
        G->adjList[i].firstedge = e;
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        //邻接序号为i
        e->adjvex =i;
        //将e指针指向当前顶点指向的结点
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;//将当前顶点的指针指向e
    }
}

/*
 * 图的遍历:
 *     图的遍历和树的遍历类似,从图中某一顶点出发访遍图中其余顶点
 *     且使每个顶点仅被访问一次,这一过程叫做图的遍历(Traversing Graph)
 */

/*
 * 深度优先遍历:(Depth First Search),类似于树的前序遍历
 */
int MAX = 200;
Boolean visited[MAX];
//邻接矩阵的深度优先递归算法
void DFS_matrix(MGraph G, int i){
    int j;
    visited[i] = TRUE;
    printf("%c\n", G.vexs[i]);
    for (j = 0; j < G.numVertexes; j++)
    {
        if(G.arc[i][j] == 1 && !visited[j]){
            //对为访问的邻接顶点递归调用
            DFS(G, j);
        }
    }
}

//邻接矩阵的深度遍历操作
void DFSTraverse_matrix(MGraph G){
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        //初始所有顶点状态都是未访问过状态
        visited[i] = FALSE;
    }
    for (i = 0; i < G.numVertexes; i++)
    {
        if(!visited[i]){
            //对未访问过的顶点调用DFS,若是连通图,只会执行一次
            DFS_matrix(G,i);
        }
    }
}


//邻接表的深度优先递归算法
void DFS_link(GraphAdjList GL, int i){
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c\n", GL->adjList[i].data);
    p = GL->adjList[i].firstedge;
    while(p){
        if(!visited[p->adjvex]){
            DFS_link(GL, p->adjvex);//对为访问的邻接顶点递归调用
        }
        p = p->next;
    }
}

//邻接表的深度遍历操作
void DFSTraverse_link(GraphAdjList GL){
    int i;
    for(i =0; i<GL.numVertexes, i++){
        visited[i] = FALSE;
    }
    for(i=0; i<GL.numVertexes; i++){
        if(!visited[i])
            DFS_link(GL, i);
    }
}

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
        visited[i] = FALSE;
    /* 初始化一辅助用的队列 */
    InitQueue(&Q);
    /* 对每一个顶点做循环 */
    for (i = 0; i < G.numVertexes; i++)
    {
        /* 若是未访问过就处理 */
        if (!visited[i])
        {
            /* 设置当前顶点访问过 */

            visited[i]=TRUE;
            /* 打印顶点，也可以其他操作 */
            printf("%c ", G.vexs[i]);
            /* 将此顶点入队列 */
            EnQueue(&Q,i);
            /* 若当前队列不为空 */
            while (!QueueEmpty(Q))
            {
                /* 将队中元素出队列，赋值给i */
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++)
                {
                    /* 判断其他顶点若与当前顶点存在边且未访问过 */
                    if (G.arc[i][j] == 1 && !visited[j])
                    {
                        /* 将找到的此顶点标记为已访问 */
                        visited[j]=TRUE;
                        /* 打印顶点 */

                        printf("%c ", G.vexs[j]);
                        /* 将找到的此顶点入队列 */
                        EnQueue(&Q,j);
                    }
                }
            }
        }
    }
}

/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            /* 打印顶点，也可以其他操作 */
            printf("%c ", GL->adjList[i].data);
            EnQueue(&Q, i);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i);
                /* 找到当前顶点边表链表头指针 */
                p = GL->adjList[i].firstedge;
                while (p)
                {
                    /* 若此顶点未被访问 */
                    if (!visited[p->adjvex])
                    {
                        visited[p->adjvex] = TRUE;

                        printf("%c ", GL->adjList[p->adjvex].data);
                        /* 将此顶点入队列 */
                        EnQueue(&Q, p->adjvex);
                    }
                    /* 指针指向下一个邻接点 */
                    p = p->next;
                }
            }
        }
    }
}



int main( int argc, char *argv[] ) /* 带参数形式 */
{

    return 0;
}