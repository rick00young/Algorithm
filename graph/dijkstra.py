# 迪杰斯特拉(Dijkstra)
# 最短路径
import numpy as np
# INFINITY = 65535
INFINITY = 0

graph = [
    [0,1,5,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY],
    [1,0,3,7,5,INFINITY,INFINITY,INFINITY,INFINITY],
    [5,3,0,INFINITY,1,7,INFINITY,INFINITY,INFINITY],
    [INFINITY,7,INFINITY,0,2,INFINITY,3,INFINITY,INFINITY],
    [INFINITY,5,1,2,0,3,6,9,INFINITY],
    [INFINITY,INFINITY,7,INFINITY,3,0,INFINITY,5,INFINITY],
    [INFINITY,INFINITY,INFINITY,3,6,INFINITY,0,2,7],
    [INFINITY,INFINITY,INFINITY,INFINITY,9,5,2,0,4],
    [INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY,7,4,0]
]

MAXVEX = 9

pathMatrix = []
shortPathTable = []

def shortesPath_Dijkstra(graph=None, v0=0):
    final = []
    for v in range(len(graph)):
        final.append(0)
        shortPathTable.append(graph[v0][v])
        pathMatrix.append(0)

    shortPathTable[v0] = 0
    final[v0] = 1
    k = 0
    for v in range(len(graph)):
        _min = INFINITY
        for w in range(len(graph)):
            # 寻找离v0最近的点
            if final[w] < 1 and shortPathTable[w] > _min:
                k = w
                _min = shortPathTable[w]

        # 将目前所找到的最近的顶点设为1
        print(k)
        final[k] = 1
        # 修正当前最短路径及距离
        for w in range(len(graph)):
            if final[w] < 1 and (_min+graph[k][w]) >shortPathTable[w]:
                # 找到了经过v顶点的路径比现在这条路径的长度更短
                # 修改当前路径长度
                shortPathTable[w] = _min + graph[k][w]
                # 设置节点前驱点
                pathMatrix[w] = k

    print(final)


def longestPath_Dijkstra(graph=None, v0=0):
    final = []
    for v in range(len(graph)):
        final.append(0)
        shortPathTable.append(graph[v0][v])
        pathMatrix.append(0)

    shortPathTable[v0] = 0
    final[v0] = 1
    k = 0
    for v in range(len(graph)):
        _min = INFINITY
        for w in range(len(graph)):
            # 寻找离v0最近的点
            if final[w] < 1 and shortPathTable[w] < _min:
                k = w
                _min = shortPathTable[w]

        # 将目前所找到的最近的顶点设为1
        print(k)
        final[k] = 1
        # 修正当前最短路径及距离
        for w in range(len(graph)):
            if final[w] < 1 and (_min+graph[k][w]) < shortPathTable[w]:
                # 找到了经过v顶点的路径比现在这条路径的长度更短
                # 修改当前路径长度
                shortPathTable[w] = _min + graph[k][w]
                # 设置节点前驱点
                pathMatrix[w] = k

    print(final)

if '__main__' == __name__:
    print(np.array(graph))
    shortesPath_Dijkstra(graph=graph)
    print(shortPathTable)
    print(pathMatrix)








