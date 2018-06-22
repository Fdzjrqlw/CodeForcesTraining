#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>
#include <set>

using namespace std ;

const int maxn = 200000 + 100 ;

long long a[maxn] ;
int c[maxn] ;

int n , m , d ;

long long ans ; 

set <int> tree ;

int main(){

    scanf("%d%d",&n,&m) ;
    d = n / m ;

    for(int i = 1 ; i <= n ; ++i)
        scanf("%lld",&a[i]) ;

    for(int i = 0 ; i < 2 * m ; ++i)
        tree.insert(i) ;

    for(int i = 1 ; i <= n ; ++i){
        set <int> ::iterator it = tree.lower_bound(a[i] % m) ;
        int x = *it ; 
        ans = ans + (long long )(x  - a[i] % m) ;
        a[i] = a[i] + (long long)(x - a[i] % m) ;
        int r = a[i] % m ;
        c[r] ++ ;
        if(c[r] >= d){
            tree.erase(r) ; tree.erase(r + m) ;
        }
    }

    printf("%lld\n",ans) ;

    for(int i = 1 ; i < n ; ++i)
        printf("%lld ",a[i]) ;
    printf("%lld\n",a[n]) ;

    return 0 ;

}