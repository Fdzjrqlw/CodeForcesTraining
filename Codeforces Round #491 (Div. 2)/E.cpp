#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std ;
const int maxn = 110 ;

long long n ;
long long res ;
long long fac[maxn] ;

int num[11] , ans[11] ;

void calc(){
    int x = 0 ;
    for(int i = 0 ; i <= 9 ; ++i)
        x = x + ans[i] ;
    if(ans[0] > 0){
        for(int i = 1 ; i <= 9 ; ++i){
            if(ans[i] == 0)
                continue ;
            long long t = fac[x - 1] ;
            for(int j = 0 ; j <= 9 ; ++j){
                if(i != j)
                    t /= fac[ans[j]] ;
                else 
                    t /= fac[ans[j] - 1] ;
            }
            res += t ;
        }
    } else {
        long long t = fac[x] ;
        for(int i = 1 ; i <= 9 ; ++i){
            t /= fac[ans[i]] ;
        }
        res += t ;
    }
    
}

void dfs(int dep){
    if(dep == 10){
        for(int i = 0 ; i <= 9 ; ++i){
            if(num[i] != 0 &&  ans[i] < 1){
                return ;
            }
        }
        calc() ;
        // for(int i = 0 ; i <= 9 ; ++i){
        //     cout << i << " "<< ans[i] << endl ;
        // }
        // cout  << endl ;
        return ;
    }
    if(num[dep] == 0){
        dfs(dep + 1) ;
        return ;
    }
    ans[dep] = 1 ;
    for(int i = 1 ; i <= num[dep] ; ++i){
        ans[dep] = i ;
        dfs(dep + 1) ;
        ans[dep] = 1 ;
    }
    return ;
}

int main(){

    fac[0] = 1 ; 
    fac[1] = 1 ;
    for(int i = 2 ; i <= 20 ; ++i)
        fac[i] = fac[i - 1] * (long long) i ;

    cin >> n ;

    while(n){
        num[n % 10]++ ;
        n /= 10 ;
    }


    dfs(0) ;

    printf("%lld\n",res) ;

    return 0 ;
 
}