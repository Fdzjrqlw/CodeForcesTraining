#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 200010 ;

vector <int> G[maxn] ;

int n , q ;

int L[maxn] , R[maxn] , seq[maxn] , dfn;

void Dfs(int u , int fa){
    L[u] = ++dfn ; seq[dfn] = u ;
    for(int i = 0 ; i < (int) G[u].size() ; ++i){
        int v = G[u][i] ;
        if(v == fa) continue ;
        Dfs(v , u) ;
    }
    R[u] = dfn ;
}

int main(){

    scanf("%d%d",&n,&q) ;

    for(int i = 2 ; i <= n ; ++i){
        int fa ;
        scanf("%d",&fa) ;
        G[fa].push_back(i) ;
    }

    Dfs(1 , 0) ;

    for(int i = 1 ; i <= q ; ++i){
        int u , k ;
        scanf("%d%d",&u,&k) ;
        if(R[u] - L[u] + 1 < k){
            printf("-1\n") ;
        } else printf("%d\n",seq[L[u] + k - 1]) ;
    }


    return 0 ;

}