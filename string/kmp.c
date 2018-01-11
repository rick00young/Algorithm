#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//未实验,切记

void make_next(const char P[], int next[]){
    int k;//最大对称长度
    int m= strlen(P);//模版字符串长度
    next[0] = 0;//模版字符串的第一个字符的最大对称值必为0;
    for (int q = 1, k = 0; q < m; ++q)
    //for循环，从第二个字符开始，依次计算每一个字符对应的next值
    {
        //在前一个位置的k不为0，但是却不相等，那么减少k，
        //重新寻找与P[q]相等的位置，让下面的if来增加k
        while(k > 0 && P[q] != P[k]){
            //while循环是整段代码的精髓所在，
            //k将循环递减，值得注意的是next[k]<k总是成立
            k = next[k-1];
        }
        //如果相等，那么最大相同前后缀长度加1
        if(P[q] == P[k])
            k++;//增加k的唯一方式
        next[q] = k;
    }
}


int kmp(const char S[], const char P[], int next[]){
    int n, m;
    n = strlen(S);
    m = strlen(P);
    int next[m];
    for (int i = 0, q = 0; i < n; ++i){
        while(q > 0 && P[q] != S[i])
            q = next[q - 1];
        if(P[q] == S[i])
            q++;
        if (q == m){
            return i-m+1;
        }
    }

    return -1;
}

int main( int argc, char *argv[] ) /* 带参数形式 */
{
    char s[] = "aaabaaaab";
    char p[] = "aabcaab";
    int next[7];
    make_next(p, next);
    for (int i = 0; i < 7; ++i)
    {
        /* code */
        printf("i: %d -- %c -- %d\n", i, p[i], next[i]);
    }
    return 0;
}