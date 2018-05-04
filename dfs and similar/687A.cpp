/*
    二分图染色判定。
    Time complexity O(N + M)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;
const int maxn = 100010 + 10 ;


int n , m , tot , col[maxn] ;
bool vis[maxn] , flag; 

struct Edge {
    int u , v ;
    Edge *next ; 
}E[maxn * 4] , *header[maxn] ;

void AddEdge(int u , int v){
    E[++tot].u = u ; E[tot].v = v ; E[tot].next = header[u] ; header[u] = &E[tot] ;
    E[++tot].u = v ; E[tot].v = u ; E[tot].next = header[v] ; header[v] = &E[tot] ;
}

void dfs(int u , int color){
    vis[u] = true ; col[u] = color ;
    for(Edge *e = header[u] ; e ; e = e->next){
        if(!vis[e->v]){
            dfs(e->v , 1 - color) ;
        } else {
            if(col[e->v] != 1 - color){
                flag = true ; return ;
            }
        }
    }
}

vector <int> ans[2] ;

int main(){

    scanf("%d%d",&n,&m) ;
    for(int i = 1 ; i <= m ; ++i){
        int u , v ;
        scanf("%d%d",&u , &v) ;
        AddEdge(u , v) ;
    }

    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            dfs(i , 0) ;
        }
    }
    if(flag){
        printf("-1\n") ;
        return 0 ;
    }
    for(int i = 1 ; i <= n ; ++i)
        ans[col[i]].push_back(i) ;

    printf("%d\n",ans[0].size()) ;
    if(ans[0].size() != 0){
        printf("%d",ans[0][0]) ;
        for(int i = 1 ; i < ans[0].size() ; ++i)
            printf(" %d",ans[0][i]) ;
        printf("\n") ;
    }

    printf("%d\n",ans[1].size()) ;
    if(ans[1].size() != 0){
        printf("%d",ans[1][0]) ;
        for(int i = 1 ; i < ans[1].size() ; ++i)
            printf(" %d",ans[1][i]) ;
        printf("\n") ;
    }

    return 0 ;



}