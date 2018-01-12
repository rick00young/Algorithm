//多路查找树,其每一个结点的孩子数可以多于两个,且每一个结点处可以存储多个元素
//
//2-3树: 其中的每一个结点都具有两个孩子或三个孩子.
//  一个2结点包含一个元素和两个孩子或是没有孩子.
//  一个3结点包含一大一小两个元素和三个元素或没有孩子.


//2-3-4树,扩展4结点,一个4结点包含小中大三个元素和四个孩子或没有孩子

/*
B树
    (B-tree)是一种平衡的多路查找树,2-3,2-3-4树都是B树的特例
    B树减少了访问结点和数据块的数量,从而提高了性能

B+树
    B+树是应文件系统所需而出的一种B树的变形.
    B+树的结构特别适合带有范围的查找
/*