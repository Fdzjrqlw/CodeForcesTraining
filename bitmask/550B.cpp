
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std ;
const int maxn = 16 ;

int result = 0 ;

int n , x , l , r ;
int c[maxn] ;
int two[maxn] ;
int state[maxn] ;

bool check(int s){

    memset(state , 0 , sizeof(state)) ;

    int len = 0 , m = 0 ;
    int minc = 0x7f7f7f7f , maxc = 0;
    
    for( ; s ; s >>= 1){
        state[++len] = s & 1 ;
        if((s & 1) == 1){
            ++m ;
            minc = min(c[len] , minc) ;
            maxc = max(c[len] , maxc) ;
        }
    }

    if(m < 2)
        return false ;
    if(maxc - minc < x)
        return false ;

    long long sum = (long long) 0 ;
    for(int i = 1 ; i <= len ; ++i){
        sum = sum + (long long) c[i] * (long long) state[i] ;
    }
    if((sum > (long long)r) || (sum < (long long) l))
        return false ;


    return true ;
}

int main(){

    scanf("%d%d%d%d",&n,&l,&r,&x) ;

    for(int i = 1 ; i <= n ; ++i)
        scanf("%d",&c[i]) ;

    // sort(c + 1 , c + n + 1) ;
    two[0] = 1 ;

    for(int i = 1 ; i <= n ; ++i)
        two[i] = two[i - 1] << 1 ;

    for(int i = 1 ; i < two[n] ; ++i){
        if(check(i)){
            ++result ;
        }
    }

    printf("%d\n",result) ;

    return 0 ;

}
