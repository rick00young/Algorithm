# 克鲁斯卡尔  (Kruskal)
INFINITY = 65535
import numpy as np

M = [
    [0, 10, INFINITY,INFINITY,INFINITY, 11, INFINITY,INFINITY,INFINITY],
    [10, 0, 18, INFINITY, INFINITY,INFINITY, 16, INFINITY, 12],
    [INFINITY,18,0, 22, INFINITY,INFINITY,INFINITY,INFINITY, 8],
    [INFINITY,INFINITY,22, 0, 20, INFINITY, 24, 16, 21],
    [INFINITY, INFINITY, INFINITY, 20, 0, 26, INFINITY, 7, INFINITY],
    [11, INFINITY,INFINITY,INFINITY, 26, 0, 17, INFINITY,INFINITY],
    [INFINITY, 16, INFINITY,24,INFINITY, 17, 0, 19, INFINITY],
    [INFINITY,INFINITY,INFINITY, 16, 7, INFINITY, 19, 0, INFINITY],
    [INFINITY, 12, 8, 21, INFINITY,INFINITY,INFINITY,INFINITY,0]
]

def convert_edges(M):
    edges = []
    l = len(M)
    key_set = set()
    for i in range(l):
        for j in range(l):
            if M[i][j] == INFINITY or 0 == M[i][j]:
                continue
            _key = '%s-%s' % (max(i, j), min(i,j))
            print(_key)
            if _key in key_set:
                continue
            key_set.add(_key)
            edges.append([i, j, M[i][j]])

    return edges


def mini_span_kruskal(data=[], edges=[]):
    max_edge = len(edges)
    max_vex = len(data)
    parent = [0 for i in range(max_vex)]

    for i in range(max_vex):
        n = find(parent, edges[i][0])
        m = find(parent, edges[i][1])

        if n != m:
            parent[n] = m
            print("(%d, %d) %d" % (n, m , edges[i][2]))

    print('parent', parent)

def find(parent, f):
    while parent[f] > 0:
        f = parent[f]
    return f

if '__main__' == __name__:
    print(np.array(M))
    edges = convert_edges(M)
    edges = sorted(edges, key=lambda x: x[2])
    print(np.array(edges))
    mini_span_kruskal(data=M, edges=edges)