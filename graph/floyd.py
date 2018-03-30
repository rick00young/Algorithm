# 弗洛伊德  (Floyd)
# 最短路径

'''
v1->v0->v2
v1->v2
D[1][0]+D[0][2] = 1+2 = 3
D[1][2] = 5
=> D[1][2] = D[1][0]+D[0][2]

=> P[1][2] = v0

D[v][w] = min(D[v][w], D[v][0]+D[0][w])
'''

import numpy as np
INFINITY = 65535
# INFINITY = 0

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

# graph = [[INFINITY, 1, 1], [2, INFINITY, 2], [2, 2, INFINITY]]

MAXVEX = 9

# 路径矩阵
pathMatrix = []
# 权重矩阵
weightTable = []

def shortesPath_Floyd(graph=None):
    graph_len = len(graph)
    # 初始化矩阵
    for i in range(graph_len):
        _p = []
        _w = []
        for j in range(graph_len):
            _p.append(j)
            _w.append(graph[i][j])
        pathMatrix.append(_p)
        weightTable.append(_w)

    print('*'*10)
    print(np.array(weightTable))
    print(np.array(pathMatrix))
    print('*'*10)

    for k in range(graph_len):
        for v in range(graph_len):
            for w in range(graph_len):
                # 如查经过下标为k的顶点路径比原来两点间路径更短
                if weightTable[v][w] > (weightTable[v][k] + weightTable[k][w]):
                    # 将当前两点间权值设为更小的一个
                    weightTable[v][w] = weightTable[v][k] + weightTable[k][w]
                    # 路径设置经过下标为k的顶点
                    pathMatrix[v][w] = pathMatrix[v][k]


def longestPath_Floyd(graph=None):
    graph_len = len(graph)
    # 初始化矩阵
    for i in range(graph_len):
        _p = []
        _w = []
        for j in range(graph_len):
            _p.append(j)
            _w.append(graph[i][j])
        pathMatrix.append(_p)
        weightTable.append(_w)

    print('*'*10)
    print(np.array(weightTable))
    print(np.array(pathMatrix))
    print('*'*10)

    for k in range(graph_len):
        for v in range(graph_len):
            for w in range(graph_len):
                # 如查经过下标为k的顶点路径比原来两点间路径更短
                temp = INFINITY if (weightTable[v][w] == INFINITY or weightTable[k][w] == INFINITY) else weightTable[v][k] + weightTable[k][w]
                if weightTable[v][w] > (weightTable[v][k] + weightTable[k][w]):
                # if weightTable[v][w] > temp:
                    # print(weightTable[v][w])
                    # 将当前两点间权值设为更小的一个
                    weightTable[v][w] = weightTable[v][k] + weightTable[k][w]
                    # 路径设置经过下标为k的顶点
                    pathMatrix[v][w] = pathMatrix[v][k]

if '__main__' == __name__:
    graph = np.array(graph)
    print(graph)
    # shortesPath_Floyd(graph=graph)
    longestPath_Floyd(graph=graph)
    print(np.array(pathMatrix))
    print(np.array(weightTable))




