
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>

using namespace std ;

const int maxn = 200000 + 5 ;
const int maxm = 200000 + 5 ;

int n , m , k , t ;
bool visited[maxn] ;
int d[maxn] ;

vector <string> res ;

struct Edge {
    int u , v , id ;
    Edge *next ; 
} E[maxm * 2] , *header[maxn] ;
int tot ;

vector <int> pre[maxn] ;

void AddEdge(int u , int v , int id){
    E[++tot].u = u ; E[tot].v = v ; E[tot].next = header[u] ;  E[tot].id = id ; header[u] = &E[tot] ;
}


char s[maxn] ; 
void Dfs(int u){
    if(t >= k)
        return ;
    if(u == n + 1){
        ++t ;
        res.push_back((string)(s)) ;
        return ;
    }

    for(int i = 0 ; i < pre[u].size() ; ++i){
        s[pre[u][i] - 1] = '1' ;
        Dfs(u + 1) ;
        s[pre[u][i] - 1] = '0' ;
    }
}

queue <int> Q ;

void Bfs(){
    memset(visited , false , sizeof(visited)) ;
    memset(d , 0x7f7f7f7f , sizeof(d)) ;

    d[1] = 0 ;
    visited[1] = true ;
    Q.push(1) ;

    while(!Q.empty()){
        int u = Q.front() ; Q.pop() ;

        for(Edge *e = header[u] ; e ; e = e->next){
            if(!visited[e->v]){
                if(d[e->v] > d[u] + 1){
                    d[e->v] = d[u] + 1 ;
                    visited[e->v] = true ;
                    Q.push(e->v) ;
                }
            }
        }
    }

    for(int u = 2 ; u <= n ; ++u){
        for(Edge *e = header[u] ; e ; e = e->next){
            if(d[u] == d[e->v] + 1){
                pre[u].push_back(e->id) ;
            }
        }
    }

    return ;

}

int main(){

    scanf("%d%d%d",&n,&m,&k) ;

    for (int i = 1 ; i <= m ; ++i){
        int u , v ;
        scanf("%d%d",&u , &v) ;
        AddEdge(u , v , i) ;
        AddEdge(v , u , i) ;
    }

    for(int i = 0 ; i < m ; ++i)
        s[i] = '0' ;

    Bfs() ;

    Dfs(2) ;

    printf("%d\n",(int) res.size()) ;

    for(int i = 0 ; i < (int) res.size() ; ++i)
        cout << res[i] << endl ;

    return 0 ;
}
