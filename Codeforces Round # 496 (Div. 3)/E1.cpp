
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 200000 + 5 ;

int n , m , A[maxn] , B[maxn] , pos ;
long long res ;

map <int , int> T ;


int main(){

    scanf("%d%d",&n,&m) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&A[i]) ;
        if(A[i] > m){
            B[i] = 1 ; 
        } else if(A[i] < m){
            B[i] = -1 ;
        }
        if(A[i] == m){
            pos = i ;
        }
    }

    int S = 0 ;
    T[S]++ ;

    for(int i = 1 ; i <= n ; ++i){
        S += B[i] ;

        if(pos <= i){
            res = res + T[S] + T[S - 1] ;
        } else {
            T[S] ++ ;
        }
    }

    cout << res << endl ;



    return 0 ;
}
