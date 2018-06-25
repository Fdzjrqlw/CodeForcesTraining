#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std ;
const int maxn = 110 ;

int n , g[maxn] ;
int s1 , s2 ;

inline int cmp(const void *a , const void *b){
    return *(int *)a - *(int *)b ;
}

bool check(int s){
    double gr = (double) s / (double) n ;
    if(gr - 4.5 >= 0)
        return true ;
    else 
        return false ; 
}

int main(){

    scanf("%d",&n) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&g[i]) ;
        s2 += g[i] ;
    }

    qsort(&g[1] , n , sizeof(g[1]) , cmp) ;

    if(check(s2)){
        printf("0\n") ;
        return 0 ;
    }

    for(int i = 1 ; i <= n ; ++i){
        s2 -= g[i] ;
        s1 += 5 ;
        if(check(s1 + s2)){
            printf("%d\n" , i) ;
            break ;
        }
    }

    return 0 ;
 
}