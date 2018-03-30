#include <iostream>

using namespace std;
// const int rows=10;

// int length[rows][rows]={
//     {    0,    20,    10,    30,    0,    0,    0,    0,    0,    0    },
//     {    0,    0,    0,    0,    20,    15,    0,    0,    0,    0    },
//     {    0,    0,    0,    0,    20,    30,    20,    0,    0,    0    },
//     {    0,    0,    0,    0,    0,    10,    10,    0,    0,    0    },
//     {    0,    0,    0,    0,    0,    15,    0,    10,    0,    0    },
//     {    0,    0,    0,    0,    0,    0,    0,    20,    10,    0    },
//     {    0,    0,    0,    0,    0,    20,    0,    30,    20,    0    },
//     {    0,    0,    0,    0,    0,    0,    0,    0,    0,    20    },
//     {    0,    0,    0,    0,    0,    0,    0,    0,    0,    10    },
//     {    0,    0,    0,    0,    0,    0,    0,    0,    0,    0    }
// };

const int rows=4;

int length[rows][rows]={
    {0, 1, 2, 2},
    {0, 0, 2, 2},
    {0, 0, 0, 2},
    {0, 0, 0, 0}
};

int getNextVertex( bool * set )
//获取下一个要加入集合S的结点：它的前驱结点都在集合S内
{
    for( int i=0; i<rows; i++ ){
        if( set[i] ) continue;
        bool found = true;
        for( int j=0; j<rows; j++ ){
            if( set[j] ) continue;
            if( j == i ) continue;
            if( length[j][i]>0 ){
                found = false;
            }
        }
        if( found ) return i;
    }
    return (-1);
}


int longestPath()
{
    bool inSourceSet[rows];
    for( int i=0; i<rows; i++ ){
        inSourceSet[i] = false;
    }
    inSourceSet[0] = true;

    int maxLength[rows]={0};//记录源结点到每个节点的最长路径长度
    string maxPath[rows];//记录源结点到每个节点的最长路径
    for( int j=1; j<rows; j++ ){
        int curVex = getNextVertex( inSourceSet );
        if( -1 == curVex ) continue;
        cout << " " << curVex << endl;
        int curMaxLen=0;
        int preVex=0;
        for( int i=0; i<rows; i++ ){//计算源结点到当前结点的最长路径长度和经过的结点并记录
            if( !inSourceSet[i] ) continue;
            if( (length[i][curVex] > 0) && (curMaxLen < maxLength[i] + length[i][curVex]) ){
                curMaxLen = maxLength[i] + length[i][curVex];
                preVex = i;
            }
        }
        maxLength[curVex] = curMaxLen;
        inSourceSet[curVex] = true;
        maxPath[curVex] = maxPath[preVex];
        char temp[10];
        sprintf( temp, "%d->", preVex );
        maxPath[curVex] += temp;

        curMaxLen = 0;
        /*cout << "maxLength[i] = ";
        for( int k=0; k<rows; k++ ){
            cout << " " << maxLength[k];
        }
        cout << endl;
        */
    }
    for( int i=0; i<rows; i++ ){
        cout << "Max Length to " << i << ": " << maxLength[i];
        cout << "\tPath :";
        cout << maxPath[i] << i << endl;
    }

    return maxLength[rows-1];//返回到目标结点的最长路径
}

int main( int argc, char * argv[] )
{
    int length = longestPath();
    cout << "Longest path length is " << length << endl;
    return (0);
}