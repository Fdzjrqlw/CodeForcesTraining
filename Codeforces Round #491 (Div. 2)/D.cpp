#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std ;
const int maxn = 110 ;


int n ;
char s[maxn] ;
int map[maxn][2] ;
int f[maxn][9] ;

int main(){

    scanf("%s",s) ;
    n = strlen(s) ;

    for(int i = 1 ; i <= n ; ++i)
        if(s[i - 1] == 'X')
            map[i][0] = 1 ;
        else map[i][0] = 0 ;

    scanf("%s",s) ;
    n = strlen(s) ;

    for(int i = 1 ; i <= n ; ++i)
        if(s[i - 1] == 'X')
            map[i][1] = 1 ;
        else map[i][1] = 0 ;

    if(n == 1){
        printf("0\n") ;
        return 0 ;
    }

    memset(f , -1 , sizeof(f)) ;
    if(map[1][0] == 0 && map[1][1] == 0)
        f[1][0] = 0 ;
    if(map[1][0] == 1 && map[1][1] == 0)
        f[1][1] = 0 ;
    if(map[1][0] == 0 && map[1][1] == 1)
        f[1][2] = 0 ;
    if(map[1][0] == 1 && map[1][1] == 1)
        f[1][3] = 0 ;

    for(int i = 2 ; i <= n ; ++i){
        if(map[i][0] == 0 && map[i][1] == 0){
            //不放
            for(int k = 0 ; k < 4 ; ++k){
                if(f[i - 1][k] != -1)
                    f[i][0] = max(f[i - 1][k] , f[i][0]) ;
            }
            //放
            if(f[i - 1][0] != -1)
                f[i][3] = max(f[i][3] , f[i - 1][0] + 1) ;
            if(f[i - 1][2] != -1)
                f[i][3] = max(f[i][3] , f[i - 1][2] + 1) ;
            if(f[i - 1][1] != -1)
                f[i][3] = max(f[i][3] , f[i - 1][1] + 1) ;
            if(f[i - 1][0] != -1)
                f[i][1] = max(f[i][1] , f[i - 1][0] + 1) ;
            if(f[i - 1][0] != -1)
                f[i][2] = max(f[i][2] , f[i - 1][0] + 1) ;
        }
        if(map[i][0] == 1 && map[i][1] == 0){
            //不放
            for(int k = 0 ; k < 4 ; ++k)
                if(f[i - 1][k] != -1)
                    f[i][1] = max(f[i][1] , f[i - 1][k]) ;
            //放
            if(f[i - 1][0] != -1)
                f[i][3] = max(f[i][3] , f[i - 1][0] + 1) ;

        }
        if(map[i][0] == 0 && map[i][1] == 1){
            //不放
            for(int k = 0 ; k < 4 ; ++k)
                if(f[i - 1][k] != -1)
                    f[i][2] = max(f[i][2] , f[i - 1][k]) ;
            //放
            if(f[i - 1][0] != -1)
                f[i][3] = max(f[i][3] , f[i - 1][0] + 1) ;
        }
        if(map[i][1] == 1 && map[i][1] == 1){
            for(int k = 0 ; k < 4 ; ++k)
                if(f[i - 1][k] != -1)
                    f[i][3] = max(f[i][3] , f[i - 1][k]) ;
        }
    }

    int res = 0 ;

    for(int i = 0 ; i < 4 ; ++i)
        res = max(res , f[n][i]) ;

    printf("%d\n",res) ;


    return 0 ;
 
}