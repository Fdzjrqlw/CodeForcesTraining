#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>

using namespace std ;

const int maxn = 110 ;

int n , k ;

int A[maxn] , ans ;

int main(){

    scanf("%d%d",&n,&k) ;

    for (int i = 1 ; i <= n ; ++i)
        scanf("%d",&A[i]) ;

    for(int i = 1 ; i <= n ; ++i){
        if(A[i] > k){
            break ;
        }
        ++ans ; A[i] = k + 1 ;
    }

    for(int i = n ; i >= 1 ; -- i){
        if(A[i] > k){
            break ;
        }
        ++ans ; A[i] = k + 1 ;
    }

    printf("%d\n",ans) ;

    return 0 ;

} 