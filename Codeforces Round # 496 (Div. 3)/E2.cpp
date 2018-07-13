
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 200000 + 5 ;

int n , m , A[maxn] , B[maxn] , pos , C[maxn * 3] ;
long long res ;

map <int , int> T ;

long long calc(int t){
    long long res = 0 ;
    memset(C , 0 , sizeof(C)) ;
    for(int i = 1 ; i <= n ; ++i){
        if(A[i] >= t){
            B[i] = 1 ;
        } else B[i] = -1 ;
    }

    int cnt = 0 , s = 0 ;
    C[0 + (n + 1)] = 1 ;

    for(int i = 1 ; i <= n ; ++i){
        if(B[i] == 1){
            cnt += C[s + (n + 1)] ;
            res += (long long) cnt ;
            ++s ;
            C[s + (n + 1)]++ ;
            
        } else {
            s-- ;
            cnt = cnt - C[s + (n + 1)] ;
            res += (long long) cnt ;
            C[s + (n + 1)]++ ;
        }
    }

    return res ;

}


int main(){

    scanf("%d%d",&n,&m) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&A[i]) ;
    }

    cout << calc(m) - calc(m + 1) << endl ;
    
    return 0 ;
}
