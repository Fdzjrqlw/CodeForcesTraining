#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 20 + 10 ;

long long k , a[maxn][maxn] ;

int n , m ;

map <long long , long long> mp[maxn][maxn][2] ;
long long res ;

void dfs_next(int x , int y , long long s){
    if(x + y == (n + m + 2) / 2){
        mp[x][y][0][s]++ ;
        return ;
    }
    if(y < m){
        dfs_next(x , y + 1 , s ^ a[x][y + 1]) ;
    }
    if(x < n){
        dfs_next(x + 1 , y , s ^ a[x + 1][y]) ;
    }
}

void dfs_pre(int x , int y , long long s){
    if(x + y == (n + m + 2) / 2){
        mp[x][y][1][s]++ ;
        return ;
    }
    s = s ^ a[x][y] ;
    if(x > 1){
        dfs_pre(x - 1 , y , s) ;
    } 
    if(y > 1){
        dfs_pre(x , y - 1 , s) ;
    }
}

int main(){


    scanf("%d%d%lld",&n,&m,&k) ;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%lld",&a[i][j]) ;
        }
    }

    dfs_next(1 , 1 , a[1][1]) ;
    dfs_pre(n , m , 0) ;

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if((i + j) == ((n + m + 2) / 2)){
                for (auto &t : mp[i][j][0]){
                    if(mp[i][j][1].find(k ^ t.first) != mp[i][j][1].end()){
                        res += t.second * mp[i][j][1][k ^ t.first] ;
                    }
                }
            }
        }
    }

    printf("%lld\n",res) ;


    
    return 0 ;

}