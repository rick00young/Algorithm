/**
 * 拓扑排序:
 * 在一个表示工程的有向图中,用顶点表示活动,用弧表示活动之间的优先关系,
 * 这样的有向图为顶点表示活动的网,称为AOV网(Activity On Vertex Network)
 *
 * 设G=(V,E)是一个具有n个顶点的有向图,V中的顶点序列v1,v2,...,vn,满足若从
 * 顶点vi到vj有一条路径,则在顶点序列中顶点vi必在顶点vj之前,则称这样的顶点序列为
 * 一个拓扑结构.
 *
 * 所谓拓扑排序,其实就是对一个有向图构造拓扑序列的过程.
 *     构造时会有两个结点,如果此网的全部顶点都被输出,则说明它是不存在环(回路)
 *     的AOV网;如果输出顶点数减少了,则该网存在环(回路),不是AOV网.
 *
 * 拓扑排序算法:
 *     从AOV网中选择一个入度为0的顶点输出,然后删去此顶点,并删除以此项点为尾的
 *     弧,继续重复此步骤,直到输出全部顶点或者AOV网中不存在入度为0的顶点为止.
 *
 * 关键路径:
 * 在一个表示工程的带权有向图中,用顶点表示事件,用有向边表示活动,用边上的权值表示
 * 活动的持续时间,这种有向图的边表示活动的网,称之为AOE网(Activity On Edge Network)
 *
 * AOE网中没有入边的顶点称为始点或是源点,没有出边的顶点称之为终点或汇点
 *
 * 路径上各个活动所持续的时间之和称为路径长度,从源点到汇点具有最大长度的路径叫
 * 关键路径,在关键路径上的活动叫做关键活动.
 *
 *
 * AOV网是顶点表示活动的网,它只描述活动之间的制约关系;
 * 而AOE网是边表示活动的网,边上的权值表示活动持续的时间.
 *
 */

/* 边表结点 */
typedef struct EdgeNode
{
    /* 邻接点域，存储该顶点对应的下标 */
    int adjvex;
    /* 用于存储权值，对于非网图可以不需要 */
    int weight;
    /* 链域，指向下一个邻接点 */
    struct EdgeNode *next;
} EdgeNode;
/* 顶点表结点 */
typedef struct VertexNode
{
    /* 顶点入度*/
    int in;
    /* 顶点域，存储顶点信息 */
    int data;
    /* 边表头指针 */
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    /* 图中当前顶点数和边数 */
    int numVertexes,numEdges;
} graphAdjList, *GraphAdjList;


/* 拓扑排序，若GL无回路，则输出拓扑排序序列并
   返回OK，若有回路返回ERROR
   算法复杂法为O(n+e), e入度减1的操作执行了e次
   */
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    /* 用于栈指针下标 */
    int top = 0;
    /* 用于统计输出顶点的个数 */
    int count = 0;
    /* 建栈存储入度为0的顶点 */
    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
       if (GL->adjList[i].in == 0)
           /* 将入度为0的顶点入栈 */
           stack[++top] = i;
    while (top != 0)
    {
        /* 出栈 */
        gettop = stack[top--];
        /* 打印此顶点 */
        printf("%d -> ", GL->adjList[gettop].data);
        /* 统计输出顶点数 */
        count++;
        /* 对此顶点弧表遍历 */

        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            /* 将k号顶点邻接点的入度减1 */
            if (!(--GL->adjList[k].in))
                /*若为0则入栈，以便于下次循环输出 */
                stack[++top] = k;
        }
    }
    /*如果count小于顶点数，说明存在环 */
    if (count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}


int *etv, *ltv;    /* 事件最早发生时间和最迟发生时间数组 */
int *stack2;       /* 用于存储拓扑序列的栈 */
int top2;          /* 用于stack2的指针 */

/* 拓扑排序，用于关键路径计算
 *
 */
Status TopologicalSort(GraphAdjList GL)
 {
    EdgeNode *e;
    int i, k, gettop;
    /* 用于栈指针下标 */
    int top = 0;
    /* 用于统计输出顶点的个数 */
    int count = 0;
    /* 建栈将入度为0的顶点入栈 */

    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
       if (0 == GL->adjList[i].in)
           stack[++top] = i;
    /* 初始化为0 */
    top2 = 0;
    /* 事件最早发生时间 */
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        /* 初始化为0 */
        etv[i] = 0;                                           \
    /* 初始化 */
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));
    while (top != 0)
    {
        gettop = stack[top--];
        count++;

        /* 将弹出的顶点序号压入拓扑序列的栈 */
        stack2[++top2] = gettop;
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))
                stack[++top] = k;
            /* 求各顶点事件最早发生时间值 */
            if ((etv[gettop] + e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        }
    }
    if (count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}


/* 求关键路径，GL为有向网，输出GL的各项关键活动
 * 算法复杂法为O(n+e)
 */
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i, gettop, k, j;
    /* 声明活动最早发生时间和最迟发生时间变量 */
    int ete, lte;
    /* 求拓扑序列，计算数组etv和stack2的值 */
    TopologicalSort(GL);
    /* 事件最晚发生时间 */
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
        /* 初始化ltv */
        ltv[i] = etv[GL->numVertexes - 1];
    /* 计算ltv */
    while (top2 != 0)
    {
        /* 将拓扑序列出栈，后进先出 */
        gettop = stack2[top2--];
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            /* 求各顶点事件的最迟发生时间ltv值 */
            k = e->adjvex;
            /* 求各顶点事件最晚发生时间ltv */
            if (ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }
    /* 求ete，lte和关键活动 */
    for (j = 0; j < GL->numVertexes; j++)
    {
        for (e = GL->adjList[j].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            /* 活动最早发生时间 */
            ete = etv[j];
            /* 活动最迟发生时间 */
            lte = ltv[k] - e->weight;
            * 两者相等即在关键路径上 */
            if (ete == lte)                                /
                printf("<v%d,v%d> length: %d , ",
                    GL->adjList[j].data, GL->adjList[k].data, e->weight);
        }
    }
}

