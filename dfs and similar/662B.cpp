/*
    注意到每个点至多改变一次，如果固定最后图的颜色，那么对于每个联通块，只需要随机枚举一个点是否改变，然后验证是否满足条件即可。
    Time complexity O(N + M)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;
const int maxn = 100000 + 10 ;

int n , tot , m , f[2] , l[2];
vector <int> seq[2] ;
vector <int> result[2] ;
bool vis[maxn] , v[maxn][2] , ct[maxn][2] ;

struct Edge {
    int u , v , r ;
    Edge *next ; 
}E[maxn * 4] , *header[maxn] ;

void AddEdge(int u , int v , int r){
    E[++tot].u = u ; E[tot].v = v ; E[tot].r = r ; E[tot].next = header[u] ; header[u] = &E[tot] ;
    E[++tot].u = v ; E[tot].v = u ; E[tot].r = r ; E[tot].next = header[v] ; header[v] = &E[tot] ;
}

void dfs(int u , int color , int change , int t){
    vis[u] = true ; v[u][t] = true ; ct[u][t] = change ;
    if(change){
        l[t]++; seq[t].push_back(u) ;
    }
    for(Edge *e = header[u] ; e ; e = e->next){
        if(!v[e->v][t]){
            if(e->r == color){
                dfs(e->v , color , change , t) ; 
            } else dfs(e->v , color , 1 - change , t) ;
        } else {
            if(e->r == color && ct[e->v][t] != change){
                f[t] = 1 ; return ;
            }
            if(e->r != color && ct[e->v][t] == change){
                f[t] = 1 ; return ;
            }
        }
    }
}

int Solve(int color){
    int answer = 0 ;
    memset(vis , 0 , sizeof(vis)) ;
    memset(v , 0 , sizeof(v)) ;

    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            f[0] = f[1] = 0 ;
            l[0] = l[1] = 0 ;
            seq[0].clear() ; seq[1].clear() ;
            dfs(i , color , 0 , 0) ;
            dfs(i , color , 1 , 1) ;
            if(f[0] && f[1]){
                return -1 ;
            }
            if(f[0] && !f[1]){
                answer += l[1] ;
                for(int j = 0 ; j < seq[1].size() ; ++j)
                    result[color].push_back(seq[1][j]) ;
                //result[color].insert(result[color].end() , seq[1].begin() , seq[1].end()) ;
            } else if(!f[0] && f[1]){
                for(int j = 0 ; j < seq[0].size() ; ++j)
                    result[color].push_back(seq[0][j]) ;
                //result[color].insert(result[color].end() , seq[0].begin() , seq[0].end()) ;
                answer += l[0] ;
            } else {
                if(l[0] < l[1]){
                    for(int j = 0 ; j < seq[0].size() ; ++j)
                        result[color].push_back(seq[0][j]) ;
                    //result[color].insert(result[color].end() , seq[0].begin() , seq[0].end()) ;
                } else {
                    for(int j = 0 ; j < seq[1].size() ; ++j)
                        result[color].push_back(seq[1][j]) ;
                    //result[color].insert(result[color].end() , seq[1].begin() , seq[1].end()) ;
                }
                answer += min(l[0] , l[1]) ;
            }
        }
    }
    return answer ;
}

int main(){

    scanf("%d%d",&n,&m) ;

    for(int i = 1 ; i <= m ; ++i){
        int u , v , r ;
        char c ;
        scanf("%d%d %c",&u,&v,&c) ;
        if(c == 'R') r = 1 ;
        else r = 0 ;
        AddEdge(u , v , r) ;
    }  
    int ret0 = -1 , ret1 = -1 ;
    ret0 = Solve(0) ; ret1 = Solve(1) ;
    if(ret0 == -1 && ret1 == -1){
        printf("-1\n") ;
        return 0 ;
    }
    if(ret0 == -1){
        ret0 = n + 1 ;
    } 
    if(ret1 == -1){
        ret1 = n + 1 ;
    }

    if(ret0 < ret1){
        printf("%d\n",ret0) ; 
        if(ret0 != 0){
            printf("%d",result[0][0]) ;
            for(int i = 1 ; i < result[0].size() ; ++i)
                printf(" %d",result[0][i]) ;
            printf("\n") ;
        }
    } else {
        printf("%d\n",ret1) ;
        if(ret1 != 0){
            printf("%d",result[1][0]) ;
            for(int i = 1 ; i < result[1].size() ; ++i)
                printf(" %d",result[1][i]) ;
            printf("\n") ;
        }
        
    }

    return 0 ;

}

