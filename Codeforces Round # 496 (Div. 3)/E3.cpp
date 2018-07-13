
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
int T[maxn * 3] ;

int lowbit(int x){
    return x & (-x) ;
}

int query(int x){
    int sum = 0 ;
    for ( ; x ; x -= lowbit(x)){
        sum += T[x] ;
    }
    return sum ;
}

void update(int x , int c){
    for( ; x <= n + n + 1 ; x += lowbit(x))
        T[x] += c ;
}

long long calc(int t){
    long long res = 0 ;
    memset(T , 0 , sizeof(T)) ;
    for(int i = 1 ; i <= n ; ++i){
        if(A[i] >= t){
            B[i] = 1 ;
        } else B[i] = -1 ;
    }

    update(0 + n + 1 , 1) ;
    int s = 0 ;

    for(int i = 1 ; i <= n ; ++i){
        s += B[i] ;
        res = res + (long long) query(s - 1 + n + 1 ) ;
        update(s + n + 1 , 1) ;
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
