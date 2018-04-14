

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std ;

typedef long long LL ;
const int maxn = 200010 ;

int n , k , x ;
int a[maxn] , pre[maxn] , sub[maxn] ;

LL result ;


int main(){

    scanf("%d%d%d",&n,&k,&x) ;

    LL y = (LL) 1 ;

    for(int i = 1 ; i <= k ; ++i){
        y = y * (LL)x ;
    }


    pre[0] = 0 ; sub[n + 1] = 0 ;

    for(int i = 1 ; i <= n ; ++i)
        scanf("%d",&a[i]) ;

    for(int i = 1 ; i <= n ; ++i){
        pre[i] = pre[i - 1] | a[i] ;
    }

    for(int i = n ; i >= 1 ; --i){
        sub[i] = sub[i + 1] | a[i] ;
    }

    for(int i = 1 ; i <= n ; ++i){
        LL t = 0 ;
        t = ((LL) a[i] * (LL) y) | ((LL) pre[i - 1]) | ((LL) sub[i + 1]) ;
        if(t > result)
            result = t ;
    }
    
    cout << result << endl ;

    return 0 ;

}