/*
先建树，然后统计每一层的节点个数。若为奇数，则答案+1。
Time complexity O(N)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std ;

const int maxn = 100010 ;

vector <int> depth[maxn] ;

struct Edge {
    int u , v ;
    Edge *next ;
}E[maxn * 2] , *header[maxn] ;

int fa[maxn] , tot , n , result ;


void AddEdge(int u , int v){
    fa[v] = u ;
    E[++tot].u = u ; E[tot].v = v ; E[tot].next = header[u] ; header[u] = &E[tot] ;
}

void dfs(int u , int d){
    depth[d].push_back(u) ;

    for(Edge *e = header[u] ; e ; e = e->next){
        if(fa[u] != e->v){
            dfs(e->v , d + 1) ;
        }
    }
}

int main(){

    scanf("%d",&n) ;

    for (int i = 2 ; i <= n ; ++i){
        int p ;
        scanf("%d",&p) ;
        AddEdge(p , i) ;
    }

    dfs(1 , 0) ;

    for(int i = 0 ; i < n ; ++i)
        if(depth[i].size() & 1)
            ++result ;

    printf("%d\n",result) ;

    return 0 ;

}