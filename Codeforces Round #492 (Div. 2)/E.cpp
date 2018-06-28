#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <queue>
#include <cmath>

using namespace std ;
const int inf = 0x3f3f3f3f ;
const int maxn = 300010 ;

struct Points {
    long long x , y ;
    int id ;
}p[maxn] , state ;

int n , m , fa[maxn] , root ;
int ans[maxn] ;

queue <Points> que ;

struct Edge {
    int u , v ; 
    Edge *next ;
} E[maxn] , *header[maxn] ;

int tot ;

void AddEdge(int u , int v){
    E[++tot].v = v ; E[tot].u = u ; E[tot].next = header[u] ; header[u] = &E[tot] ;
}

bool check(long long x1 , long long y1 , long long x2 , long long y2){
    long long inp = x1 * x2 + y1 * y2 ;
    double outp = sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2) ;
    // cout << inp - outp/2 << endl ;
    // cout << inp + outp << endl ;
    // printf("%lld %lf\n",inp , outp) ;
    if(((double) inp + outp/2 <= 1e-2) && ((double) inp + outp >= -1e-2))
        return true ;
    return false ;
}

void generate(){
    Points p1 = que.front() ; que.pop() ;
    Points p2 = que.front() ; que.pop() ;
    Points p3 = que.front() ; que.pop() ;

    if(check(p1.x , p1.y , p2.x , p2.y)){
        Points newp ;
        newp.x = p1.x + p2.x ;
        newp.y = p1.y + p2.y ;
        newp.id = ++m ;
        fa[p1.id] = newp.id ; fa[p2.id] = newp.id ;
        ans[p1.id] = 1 ; ans[p2.id] = 1 ;
        que.push(newp) ; que.push(p3) ;
        return ;
    } else if(check(p1.x , p1.y , -1 * p2.x , -1 * p2.y)){
        Points newp ;
        newp.x = p1.x - p2.x ;
        newp.y = p1.y - p2.y ;
        newp.id = ++m ;
        fa[p1.id] = newp.id ; fa[p2.id] = newp.id ;
        ans[p1.id] = 1 ; ans[p2.id] = -1 ;
        que.push(newp) ; que.push(p3) ;
        return ;
    } else if(check(p1.x , p1.y , p3.x , p3.y)){
        Points newp ;
        newp.x = p1.x + p3.x ;
        newp.y = p1.y + p3.y ;
        newp.id = ++m ;
        fa[p1.id] = newp.id ; fa[p3.id] = newp.id ;
        ans[p1.id] = 1 ; ans[p3.id] = 1 ;
        que.push(newp) ; que.push(p2) ;
        return ;
    } else if(check(p1.x , p1.y , -1 * p3.x , -1 * p3.y)){
        Points newp ;
        newp.x = p1.x - p3.x ;
        newp.y = p1.y - p3.y ;
        newp.id = ++m ;
        fa[p1.id] = newp.id ; fa[p3.id] = newp.id ;
        ans[p1.id] = 1 ; ans[p3.id] = -1 ;
        que.push(newp) ; que.push(p2) ;
        return ;
    } else if(check(p2.x , p2.y , p3.x , p3.y)){
        Points newp ;
        newp.x = p2.x + p3.x ;
        newp.y = p2.y + p3.y ;
        newp.id = ++m ;
        fa[p2.id] = newp.id ; fa[p3.id] = newp.id ;
        ans[p2.id] = 1 ; ans[p3.id] = 1 ;
        que.push(newp) ; que.push(p1) ;
        return ;
    } else if(check(p2.x , p2.y  , -1 * p3.x , -1 * p3.y)){
        Points newp ;
        newp.x = p2.x - p3.x ;
        newp.y = p2.y - p3.y ;
        newp.id = ++m ;
        fa[p2.id] = newp.id ; fa[p3.id] = newp.id ;
        ans[p2.id] = 1 ; ans[p3.id] = -1 ;
        que.push(newp) ; que.push(p1) ;
        return ;
    } 
    return ;
}

void Dfs(int u , int op){
    ans[u] = ans[u] * op ;
    for(Edge *e = header[u] ; e ; e = e->next){
        Dfs(e->v , ans[u]) ;
    }
}

int main(){

    long long limit = (long long) 1500000 ;
    scanf("%d",&n) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld%lld",&p[i].x,&p[i].y) ;
        p[i].id = i ;
        que.push(p[i]) ;
    }
    if(n == 1){
        printf("1\n") ;
        return 0 ;
    }

    m = n ;

    while(que.size() > 2){
        generate() ;
    }

    if(que.size() == 2){
        Points p1 = que.front() ; que.pop() ;
        Points p2 = que.front() ; que.pop() ;
        if((p1.x + p2.x) * (p1.x + p2.x) + (p1.y + p2.y) * (p1.y + p2.y) <= limit * limit){
            fa[p1.id] = ++m ; fa[p2.id] = m ;
            ans[p1.id] = 1 ; ans[p2.id] = 1 ;
        } else {
            fa[p1.id] = ++m ; fa[p2.id] = m ;
            ans[p1.id] = 1 ; ans[p2.id] = -1 ;
        }
    }


    ans[m] = 1 ;

    root = m ;

    for(int i = 1 ; i <= m ; ++i){
        if(fa[i] != 0){
            AddEdge(fa[i] , i ) ;
        }
    }

    Dfs(m , 1) ;

    for(int i = 1 ; i < n ; ++i)
        printf("%d ",ans[i]) ;
    printf("%d\n",ans[n]) ;

    return 0 ;
}
