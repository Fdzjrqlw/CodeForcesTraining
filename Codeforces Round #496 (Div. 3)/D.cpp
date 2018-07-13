
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 200000 + 5 ;

int dp[maxn] , pre[maxn] , n ;
int mod[4] ;

char s[maxn] ;


int main(){

    scanf("%s",&s[1]) ;

    n = strlen(&s[1]) ;

    int sum = 0 ;

    memset(pre , -1 , sizeof(pre)) ;
    memset(mod , -1 , sizeof(mod)) ;
    mod[0] = 0 ;

    for(int i = 1 ; i <= n ; ++i){
        sum = (sum + (s[i] - '0') % 3) % 3 ;
        pre[i] = mod[sum] ;
        mod[sum] = i ;
    }

    // for(int i = 1 ; i <= n ; ++i){
    //     cout << s[i] - '0' << " " << pre[i] << endl ;
    // }

    for(int i = 1 ; i <= n ; ++i){
        dp[i] = max(dp[i - 1] , dp[i]) ;
        if((s[i] - '0') % 3 == 0){
            dp[i] = max(dp[i] , dp[i - 1] + 1) ;
        }
        if(pre[i] != -1){
            dp[i] = max(dp[i] , dp[pre[i]] + 1) ;
        }
    }

    printf("%d\n",dp[n]) ;

    return 0 ;
}
