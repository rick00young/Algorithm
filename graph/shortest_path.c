/*
 * 迪杰斯特拉(Dijkstra)算法:
 *     1.先找到所给结点到下一个结点最短路径, 同时找到与刚才最短路径结点相连
 *     的其他的结点的最短路径,注意不要生成闭环
 *     2.重复1步骤,直到找到所给结点找到了到其他所有结点的最短路径.
 *     算法复杂法O(n^2)
 *
 * 费洛伊德(Floyd)算法:
 *     绘制所有顶点到顶点的最短路径权值和的矩阵
 *     绘制所有顶点的最小路径的前驱矩阵
 *     复杂复杂度为: O(n^3)
 */


#define MAXVEX 9
#define INFINITY 65535
typedef int
/* 用于存储最短路径下标的数组 */
Patharc[MAXVEX];
typedef int
/* 用于存储到各点最短路径的权值和 */
ShortPathTable[MAXVEX];
/* Dijkstra算法，求有向网G的v0顶点到其余顶点v最短路径P[v]及带权长度D[v] */
/* P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和。 */
void ShortestPath_Dijkstra(MGraph G, int v0,
                           Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    /* final[w]=1表示求得顶点v0至vw的最短路径 */
    int final[MAXVEX];
    /* 初始化数据 */
    for (v = 0; v < G.numVertexes; v++)
    {
        /* 全部顶点初始化为未知最短路径状态 */
        final[v] = 0;
        /* 将与v0点有连线的顶点加上权值 */
        (*D)[v] = G.arc[v0][v];
        /* 初始化路径数组P为-1 */
        (*P)[v] = -1;
    }
    /* v0至v0路径为0 */
    (*D)[v0] = 0;
    /* v0至v0不需要求路径 */
    final[v0] = 1;
    /* 开始主循环，每次求得v0到某个v顶点的最短路径 */
    for (v = 1; v < G.numVertexes; v++)
    {
        /* 当前所知离v0顶点的最近距离 */
        min=INFINITY;
        /* 寻找离v0最近的顶点 */
        for (w = 0; w < G.numVertexes; w++)

         {
            if (!final[w] && (*D)[w] < min)
            {
                k=w;
                /* w顶点离v0顶点更近 */
                min = (*D)[w];
            }
        }
        /* 将目前找到的最近的顶点置为1 */
        final[k] = 1;
        /* 修正当前最短路径及距离 */
        for (w = 0; w < G.numVertexes; w++)
        {
            /* 如果经过v顶点的路径比现在这条路径的长度短的话 */
            if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
            {
                /* 说明找到了更短的路径，修改D[w]和P[w] */
                /* 修改当前路径长度 */
                (*D)[w] = min + G.arc[k][w];

                (*P)[w]=k;
            }
        }
    }
}

typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
/* Floyd算法，求网图G中各顶点v到其余顶点w最短
   路径P[v][w]及带权长度D[v][w] */
void ShortestPath_Floyd(MGraph G, Pathmatirx *P, ShortPathTable *D)
{
    int v, w, k;
    /* 初始化D与P */
    for (v = 0; v < G.numVertexes; ++v)
    {
       for (w = 0; w < G.numVertexes; ++w)
        {
           /* D[v][w]值即为对应点间的权值 */
           (*D)[v][w] = G.matirx[v][w];
           /* 初始化P */
           (*P)[v][w] = w;
        }
    }
    for (k = 0; k < G.numVertexes; ++k)
    {
        for (v = 0; v < G.numVertexes; ++v)
        {
            for (w = 0; w < G.numVertexes; ++w)
            {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
                {
                    /* 如果经过下标为k顶点路径比原两点间路径更短 */
                    /* 将当前两点间权值设为更小的一个 */
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    /* 路径设置经过下标为k的顶点 */
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}

//求最短路径的显示代码
/*
for (v = 0; v < G.numVertexes; ++v)
{
    for (w = v + 1; w < G.numVertexes; w++)
    {
        printf("v%d-v%d weight: %d ", v, w, D[v][w]);
         // 获得第一个路径顶点下标
        k = P[v][w];
        // 打印源点
        printf(" path: %d", v);
         // 如果路径顶点下标不是终点
        while (k != w)
        {
             // 打印路径顶点
            printf(" -> %d", k);
             // 获得下一个路径顶点下标
            k = P[k][w];
        }
    }

}
*/
