# import numpy as np
# Max     = 100
# v_len   = 4
# edge    = np.mat([[0,1,Max,4],[Max,0,9,2],[3,5,0,8],[Max,Max,6,0]])
# A       = edge[:]
# path    = np.zeros((v_len,v_len))


# def Folyd():
#     for i in range(v_len):
#         for j in range(v_len):
#             if(edge[i,j] != Max and edge[i,j] != 0):
#                 path[i][j] = i

#     print('init:')
#     print(A,'\n',path)
#     for a in range(v_len):
#         for b in range(v_len):
#             for c in range(v_len):
#                 if(A[b,a]+A[a,c]<A[b,c]):
#                     A[b,c] = A[b,a]+A[a,c]
#                     path[b][c] = path[a][c]
#     print('result:' )
#     print(A,'\n')
#     print(path)


# if __name__ == "__main__":
#     Folyd()
# import numpy as np
# t=0
# b=999
# G=[[0,1,5,b,b,b,b,b,b],\
#    [1,0,3,7,5,b,b,b,b],\
#    [5,3,0,b,1,7,b,b,b],\
#    [b,7,b,0,2,b,3,b,b],\
#    [b,5,1,2,0,3,6,9,b],\
#    [b,b,7,b,3,0,b,5,b],\
#    [b,b,b,3,6,b,0,2,7],\
#    [b,b,b,b,9,5,2,0,4],\
#    [b,b,b,b,b,b,7,4,0]]
# P=[[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],\
#    [0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],\
#    [0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0]]
# D=[[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],\
#    [0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],\
#    [0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0]]
# def Floyd(G,P,D):
#     t=0
#     for u in range(0,len(G)):
#         for s in range(0,len(G)):
#             D[u][s]=G[u][s]
#             P[u][s]=s
#     for k in range(0,len(G)):
#         for v in range(0,len(G)):
#             for w in range(0,len(G)):
#                 if D[v][w]>D[v][k]+D[k][w]:
#                     t=t+1
#                     D[v][w]=D[v][k]+D[k][w]
#                     P[v][w]=P[v][k]
# G = np.array(G)
# Floyd(G, P, D)
# print(np.array(G))
# print(np.array(P))
# print(np.array(D))

# def search(s,u):
#     lenth=D[s][u]
#     print("路径长度为",lenth)
#     f=P[s][u]
#     foot=[s,f]
#     if f==u:
#         print("无需规划，0步")
#     while f!=u:
#         f=P[f][u]
#         foot.append(f)
#     for i in range(0,len(foot)):
#         if i==0:
#             print("起     点____",foot[i])
#         elif i==len(foot)-1:
#             print("终     点____",foot[i],"步长___",G[foot[i-1]][foot[i]])
#         else:
#             print("第",i,"点____",foot[i],"步长___",G[foot[i-1]][foot[i]])
# print("邻接矩阵")
# for i in range(0,9):
#     print(G[i])
# s=input("请输入起点0-8\n")
# u=input("请输入终点0-8\n")
# Floyd(G, P, D)
# search(int(s),int(u))


def bellman_ford( graph, source ):

    distance = {}
    parent = {}

    for node in graph:
        distance[node] = float( 'Inf' )
        parent[node] = None
    distance[source] = 0

    for i in range( len( graph ) - 1 ):
        for from_node in graph:
            for to_node in graph[from_node]:
                if distance[to_node] > graph[from_node][to_node] + distance[from_node]:
                    distance[to_node] = graph[from_node][to_node] + distance[from_node]
                    parent[to_node] = from_node
    print(graph)
    for from_node in graph:
        for to_node in graph[from_node]:
            if distance[to_node] > distance[from_node] + graph[from_node][to_node]:
                return None, None

    return distance, parent

def test():
    graph = {
        'a': {'b': -1, 'c':  4},
        'b': {'c':  3, 'd':  2, 'e':  2},
        'c': {},
        'd': {'b':  1, 'c':  5},
        'e': {'d': -3}
    }
    distance, parent = bellman_ford( graph, 'a' )
    print(distance)
    print(parent)

if __name__ == '__main__':
    test()