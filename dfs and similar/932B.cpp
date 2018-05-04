/*
先预处理所有的g(i),然后计算答案为k的前缀和。
查询O(1)
Time complexity O(10*N)
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std ;
const int maxn = 1000000 ;

int q , l , r , k ;
int g[maxn + 10] , s[maxn + 10][10];

int func(int x){
    int t = 1 ;
    while(x){
        if(x % 10 != 0){
            t = t * (x % 10) ;
        }
        x /= 10 ;
    }
    return t ;
}


void init(){
    for(int i = 1 ; i <= maxn ; ++i){
        if(i < 10){
            g[i] = i ;
        } else {
            g[i] = g[func(i)] ;
        }
    }
    for(int i = 1 ; i <= maxn ; ++i){
        for(int l = 1 ; l <= 9 ; ++l){
            if(g[i] == l){
                s[i][l] = s[i - 1][l] + 1 ;
            } else s[i][l] = s[i - 1][l] ;
        }
    }
}

int main(){

    scanf("%d",&q) ;

    init() ;

    for(int i = 1 ; i <= q ; ++i){
        scanf("%d%d%d",&l,&r,&k) ;

        printf("%d\n",s[r][k] - s[l - 1][k]) ;
    }

    return 0 ;

}