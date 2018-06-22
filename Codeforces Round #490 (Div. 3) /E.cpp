#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std ;

const int maxn = 5000 + 100 ;

int n , m , s , ans ;

struct Edge {
    int u , v ;
    Edge *next ;
} E[maxn] , *header[maxn] ;

stack <int> gstack ;

bool instack[maxn] ;

int DFN[maxn] , LOW[maxn] ;
int belg[maxn] , num[maxn] ;

int tot , tag , scc ;
void add_edge(int u , int v){
    E[++tot].u = u ; E[tot].v = v ;  E[tot].next = header[u] ; header[u] = &E[tot] ;
}

int indegree[maxn] ;

void tarjan(int u){ 
    DFN[u] = LOW[u] = ++tag ;
    gstack.push(u) ;
    instack[u] = true ;
    for(Edge *e = header[u] ; e ; e = e->next){
        if(!DFN[e->v]){
            tarjan(e->v) ;
            LOW[u] = min(LOW[u] , LOW[e->v]) ;
        } else if(instack[e->v]){
            LOW[u] = min(LOW[u] , DFN[e->v]) ;
        }
    }
    if(LOW[u] == DFN[u]){
        instack[u] = false ;
        belg[u] = ++scc ;
        while(gstack.top() != u){
            int v = gstack.top() ; gstack.pop() ;
            belg[v] = scc ; instack[v] = false ;
        }
        gstack.pop() ;
    }
}

int main(){

    scanf("%d%d%d",&n,&m,&s) ;

    for(int i = 1 ; i <= m ; ++i){
        int u , v ;
        scanf("%d%d",&u,&v) ;
        add_edge(u , v) ;
    }

    for(int i = 1  ; i <= n ; ++i){
        if(!DFN[i]){
            tarjan(i) ;
        }
    }

    for(int i = 1 ; i <= m ; ++i){
        int u = E[i].u ; 
        int v = E[i].v ;
        if(belg[u] != belg[v]){
            ++indegree[belg[v]] ;
        }
    }

    for(int i = 1 ; i <= scc ; ++i){
        if(indegree[i] == 0 && i != belg[s]){
            ++ans ;
        }
    }

    printf("%d\n",ans) ; 

    return 0 ;

}