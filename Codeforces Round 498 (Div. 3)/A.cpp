#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 1010 ;

int A[maxn] ;

int n ;


int main(){

    scanf("%d",&n) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&A[i]) ; 
        if(A[i] % 2 == 0){
            A[i] -= 1 ;
        }
    }

    for(int i = 1 ; i < n ; ++i)
        printf("%d ",A[i]) ;
    printf("%d\n",A[n]) ;

    return 0 ;

}