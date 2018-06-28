#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <queue>
#include <cmath>

using namespace std ;
const int inf = 0x3f3f3f3f ;
const int maxn = 300010 ;

int n , r;
long long a[maxn] , s ;

int main(){

    scanf("%d%d",&n,&r) ;

    for(int i = 0 ; i < (1 << n) ; ++i){
        scanf("%lld",&a[i]) ;
        s += a[i] ;
    }

    printf("%lf\n",(double)s / (double)(1 << n)) ;

    for(int i =1 ; i <= r ; ++i){
        int pos ;
        long long c ;
        scanf("%d%lld",&pos , &c) ;
        s -= a[pos] ; s += c ; a[pos] = c ;
        printf("%lf\n",(double)s / (double)(1 << n)) ;
    }

    return 0 ;
}
