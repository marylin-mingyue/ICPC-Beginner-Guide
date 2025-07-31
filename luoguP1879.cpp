#include <bits/stdc++.h>
using namespace std;

/*农场主 John 新买了一块长方形的新牧场，这块牧场被划分成 M 行 N 列 (1≤M≤12,1≤N≤12)，每一格都是一块正方形的土地。
 *John 打算在牧场上的某几格里种上美味的草，供他的奶牛们享用。
遗憾的是，有些土地相当贫瘠，不能用来种草。并且，奶牛们喜欢独占一块草地的感觉，
于是 John 不会选择两块相邻的土地，也就是说，没有哪两块草地有公共边。、
John 想知道，如果不考虑草地的总块数，那么，一共有多少种种植方案可供他选择？（当然，把新牧场完全荒废也是一种方案）

输入格式
第一行：两个整数 M 和 N，用空格隔开。
第 2 到第 M+1 行：每行包含 N 个用空格隔开的整数，描述了每块土地的状态。第 i+1 行描述了第 i 行的土地，
所有整数均为 0 或 1 ，是 1 的话，表示这块土地足够肥沃，0 则表示这块土地不适合种草。

输出格式
一个整数，即牧场分配总方案数除以 1e8的余数。
https://www.luogu.com.cn/problem/P1879
*/
int MAXN=1e8;
int grid [12][12];
int dp [12][1<<12];
int m,n;
bool find_s (int &s, int j) {
    return (s & (1<<(n-1-j)));
}
//这个用来把1改成0
int modify (int s, int j) {
   return s^(1<<(n-1-j));
}
int f (int i,int s);
int dfs (int i, int j, int s, int ss) {
    if (j==n) return f(i+1,ss);
    int ans=dfs(i,j+1,s,ss);
    if (grid[i][j]==1 && !find_s(s,j) && (j==0 || !find_s(ss,j-1)))
        ans=(ans+dfs(i,j+1,s,modify(ss,j)))%MAXN;
    return ans;
}
int f (int i,int s) {
    if (i==m) return 1;
    if (dp[i][s]!=-1) return dp[i][s];
    int ans=dfs(i,0,s,0);
    dp[i][s]=ans;
    return ans;
}

int main() {
    cin>>m>>n;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin>>grid[i][j];
        }
    }
    for (int i=0;i<12;i++) {
        for (int j=0;j<(1<<12);j++) dp[i][j]=-1;
    }
    int ans= f(0,0);
    cout<<ans<<endl;
}
