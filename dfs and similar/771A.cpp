/*
    根据题意，每个联通块应该是一个完全图
    Time complexity O(N + M)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;

const int maxn = 150010 ;

struct Edge {
    int u , v ;
}E[maxn] ;


inline int cmp(const void *a , const void *b){
    struct Edge *c = (struct Edge *)a ; struct Edge *d = (struct Edge *)b ;
    if(c->u != d->u)
        return c->u - d->u ;
    else 
        return c->v - d->v ;
}

int n , m ;
int fa[maxn] ;

void union_set(int u , int v){
    if(rand() & 1){
        fa[u] = v ;
    } else fa[v] = u ;
}

int find_set(int u){
    int anc = u ;
    for ( ; anc != fa[anc] ; anc = fa[anc]) ;
    for (int v = u ; v != anc ; v = u){
        u = fa[v] ;
        fa[v] = anc ;
    }
    return anc ;
}

int cnt[maxn];

int main(){

    scanf("%d%d",&n,&m) ;

    for(int i = 1 ; i <= n ; ++i)
        fa[i] = i ;

    for(int i = 1 ; i <= m ; ++i){
        //int u , v ;
        scanf("%d%d",&E[i].u,&E[i].v) ;
        union_set(find_set(E[i].u) , find_set(E[i].v)) ;
    }

    for(int i = 1 ; i <= n ; ++i){
        cnt[find_set(i)]++ ;
    }

    long long S = 0 ;

    for(int i = 1 ; i <= n ; ++i){
        S += (long long) (cnt[find_set(i)] - 1) * (long long) (cnt[find_set(i)]) ;
        cnt[find_set(i)] = 0;
    }

    if(S != (long long)(m * 2))
        printf("NO\n") ;
    else 
        printf("YES\n") ;

    return 0 ;

}