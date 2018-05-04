/*
    考虑一个置换里的情形：如果置换的长度l为偶数，则该置换贡献l/2，否则贡献l。
    最后求出所有置换贡献的最小公倍数即可。
    Time complexity O(N)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;

const int maxn = 100 + 10 ;

int n , crush[maxn] , l , result , deg[maxn];

vector <int> seq ; 

bool vis[maxn] ;

void dfs(int u){
    ++l ; 
    vis[u] = true ;
    if(!vis[crush[u]]){
        dfs(crush[u]) ;
    }
}

int gcd(int x , int y){
    if(x < y) swap(x , y) ;
    if(x % y == 0)
        return y ;
    return gcd(y , x % y) ;
}

int lcm(int x , int y){
    return x * y / gcd(x , y) ;
}

int main(){

    scanf("%d",&n) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&crush[i]) ;
        deg[crush[i]]++ ;
    }

    for(int i = 1 ; i <= n ; ++i){
        if(deg[i] == 0){
            printf("-1\n") ;
            return 0 ;
        }
    }

    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            l = 0 ;
            dfs(i) ;
            if(l % 2 == 0)
                l /= 2 ;
            seq.push_back(l) ;
        }
    }

    result = seq[0] ;

    for(int i = 1 ; i < seq.size() ; ++i)
        result = lcm(result , seq[i]) ;

    printf("%d\n",result) ;

    return 0 ;

}

