

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std ;

const int maxn = 31 ;

int n , L ;
long long result = 0x3f3f3f3f3f3f3f3f;

int c[maxn] , w[maxn];

int main(){

    scanf("%d%d",&n , &L) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&c[i]) ;
    }

    w[1] = 1 ;
    for(int i = 2 ; i <= n ; ++i){
        c[i] = min(c[i] , (c[i - 1] << 1)) ;
        w[i] = w[i - 1] << 1 ;
    }

    long long s = 0 ;

    for(int i = n ; i >= 1 ; --i){
        int m = L / w[i] ;
        s += (long long) m * (long long)c[i] ;
        L -= m * w[i] ;
        if(L == 0){
            result = min(result , s) ;
        } else result = min(result , s + (long long)c[i]) ;

    }

    cout << result << endl ;

    return 0 ;

}