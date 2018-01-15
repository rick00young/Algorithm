'''
良好的分布式cahce系统中的一致性hash算法应该满足以下几个方面：

平衡性(Balance)
    平衡性是指哈希的结果能够尽可能分布到所有的缓冲中去，这样可以使得所有的缓冲空间都得到利用。
    很多哈希算法都能够满足这一条件。

单调性(Monotonicity)
    单调性是指如果已经有一些内容通过哈希分派到了相应的缓冲中，
    又有新的缓冲区加入到系统中，那么哈希的结果应能够保证原有已分配的内容可以被映射到新的缓冲区中去，
    而不会被映射到旧的缓冲集合中的其他缓冲区。简单的哈希算法往往不能满足单调性的要求，
    如最简单的线性哈希：x = (ax + b) mod (P)，在上式中，P表示全部缓冲的大小。
    不难看出，当缓冲大小发生变化时(从P1到P2)，原来所有的哈希结果均会发生变化，从而不满足单调性的要求。
    哈希结果的变化意味着当缓冲空间发生变化时，所有的映射关系需要在系统内全部更新。
    而在P2P系统内，缓冲的变化等价于Peer加入或退出系统，这一情况在P2P系统中会频繁发生，
    因此会带来极大计算和传输负荷。单调性就是要求哈希算法能够应对这种情况。

分散性(Spread)
    在分布式环境中，终端有可能看不到所有的缓冲，而是只能看到其中的一部分。
    当终端希望通过哈希过程将内容映射到缓冲上时，由于不同终端所见的缓冲范围有可能不同，
    从而导致哈希的结果不一致，最终的结果是相同的内容被不同的终端映射到不同的缓冲区中。
    这种情况显然是应该避免的，因为它导致相同内容被存储到不同缓冲中去，降低了系统存储的效率。
    分散性的定义就是上述情况发生的严重程度。
    好的哈希算法应能够尽量避免不一致的情况发生，也就是尽量降低分散性。

负载(Load)
    负载问题实际上是从另一个角度看待分散性问题。既然不同的终端可能将相同的内容映射到不同的缓冲区中，
    那么对于一个特定的缓冲区而言，也可能被不同的用户映射为不同的内容。
    与分散性一样，这种情况也是应当避免的，因此好的哈希算法应能够尽量降低缓冲的负荷。

平滑性(Smoothness)
    平滑性是指缓存服务器的数目平滑改变和缓存对象的平滑改变是一致的。
'''

from zlib import crc32
# import memcache

class HashConsistency(object):
    def __init__(self, nodes=None, replicas=5):
        # 虚拟节点与真实节点对应关系
        self.nodes_map = []
        # 真实节点与虚拟节点的字典映射
        self.nodes_replicas = {}
        # 真实节点
        self.nodes = nodes
        # 每个真实节点创建的虚拟节点的个数
        self.replicas = replicas

        if self.nodes:
            for node in self.nodes:
                self._add_nodes_map(node)
            self._sort_nodes()

    def get_node(self, key):
        """ 根据KEY值的hash值，返回对应的节点
        算法是： 返回最早比key_hash大的节点
        """
        key_hash = abs(crc32(key.encode('utf-8')))
        # print('%s' % key_hash)
        for node in self.nodes_map:
            if key_hash > node[0]:
                continue
            return node
        return node[0]

    def add_node(self, node):
        # 添加节点
        self._add_nodes_map(node)
        self._sort_nodes()

    def remove_node(self, node):
        # 删除节点
        if node not in self.nodes_replicas.keys():
            pass
        discard_rep_nodes = self.nodes_replicas[node]
        self.nodes_map = filter(lambda x: x[0] not in discard_rep_nodes, self.nodes_map)

    def _add_nodes_map(self, node):
        # 增加虚拟节点到nodes_map列表
        nodes_reps = []
        for i in range(self.replicas):
            rep_node = '%s_%d' % (node, i)
            node_hash = abs(crc32(rep_node.encode('utf-8')))
            self.nodes_map.append((node_hash, node))
            nodes_reps.append(node_hash)
        # 真实节点与虚拟节点的字典映射
        self.nodes_replicas[node] = nodes_reps

    def _sort_nodes(self):
        # 按顺序排列虚拟节点
        self.nodes_map = sorted(self.nodes_map, key=lambda x:x[0])


memcache_servers = [
    '127.0.0.1:7001',
    '127.0.0.1:7002',
    '127.0.0.1:7003',
    '127.0.0.1:7004',
]

h = HashConsistency(memcache_servers)

for k in h.nodes_map:
    print(k)

mc_servers_dict = {}
for ms in  memcache_servers:
    # mc = memcache.Client([ms], debug=0)
    mc_servers_dict[ms] = ms

# 循环10此给memcache 添加key，这里使用了一致性hash，那么key将会根据hash值落点到对应的虚拟节点上
for i in range(10):
    key = 'key_%s' % i
    print(key)
    server = h.get_node(key)
    print(server)
    # mc = mc_servers_dict[server]
    # mc.set(key, i)
    print('SERVER :', server)
    # print(mc)
