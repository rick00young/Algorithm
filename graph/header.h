typedef char VertexType;//顶点类型
typedef int EdgeType;//边上的权值
#define MAXVEX 100 //最大顶点数
#define INFINITY 65535//正无穷

typedef int Boolean;
#define TRUE 1
#define FALSE 0

//邻接矩阵
typedef struct
{
    VertexType vexs[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵,可看作边表
    int numVertexes, numEdges;//图中当前顶点数和边数
}MGraph;

//邻接表
typedef struct EdgeNode//边表结点
{
    int adjvex;//邻接点域,存储该顶点对应的下标
    EdgeType weight;//用于存储权值,对于非网图可以不需要
    struct EdgeNode *next;//链域,指向下一个邻接点
}EdgeNode;

typedef struct VertexNode//顶点表结点
{
    VertexType data;//顶点域,存储顶点信息
    EdgeNode *firstedge;//边表指针
}VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;//图中当前顶点数和边数
}GraphAdjList;