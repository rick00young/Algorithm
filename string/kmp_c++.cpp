#include "vector"
#include "string"
#include <iostream>

using namespace std;


void make_next(const std::string &p, std::vector<int> &next){
    next.resize(p.size());
    next[0] = -1;

    int i = 0, j = -1;

    while(i != p.size() - 1){
        //这里注意，i==0的时候实际上求的是next[1]的值，以此类推
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            next[i] = j;
            // update
            // 注意这里是++i和++j之后的p[i]、p[j]
            // next[i] = p[i] != p[j] ? j : next[j];
        }else{
            j = next[j];
        }
    }
}

int kmp(const std::string &s, const std::string &p, const int sIndex=0){
    std::vector<int> next(p.size());
    make_next(p, next);//获取next数组,保存在vector中

    // return next[3];

    int i = sIndex, j = 0;
    while(i != s.length() && j != p.length()){
        if(j == -1 || s[i] == p[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }

    cout << "p is: " << p << endl;
    // cout << "next.size() is:" << next.size() << endl;
    cout << endl;


    for (int i = 0; i < next.size(); ++i)
    {
        cout << "next[" << i << "] is: " << next[i] << endl;
    }
    cout << endl;
    cout << "i = " << i << " j = " << j << endl;
    return j == p.length() ? i - j : -1;
}


int main( int argc, char *argv[] ) /* 带参数形式 */
{
    // string T = "aaabaaaab";
    // std::vector<int> next;
    // make_next(T, next);

    // cout << "string = " << T << endl;
    // // cout << "next   = " << next << endl;

    // for (int i = 0; i < next.size(); ++i)
    // {
    //     //code
    //     cout << i << "  string - " << T[i] << "  next = " << next[i]<< endl;
    //     // cout << "next   = " << next[i] << endl;
    // }
    std::string s = "aaabaaaab";
    std::string p = "aabc";

    // std::string s = "abcdacbd";
    // std::string p = "cdacb";
    cout << "s is: " << s << endl;
    cout << kmp(s, p) << endl;
    return 0;
}