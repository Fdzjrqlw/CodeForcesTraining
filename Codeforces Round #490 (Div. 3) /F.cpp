#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std ;

const int maxn = 500 + 10 ;

int n , k , answer ;
int h[11] ;


int dp[maxn][maxn * 10] ;

map <int , int> card ;
map <int , int> fav ;
vector <int> people ;

int main(){

    scanf("%d%d",&n,&k) ;

    for(int i = 1 ; i <= n * k ; ++i){
        int c ;
        scanf("%d",&c) ;
        card[c]++ ;
    }

    for(int i = 1 ; i <= n ; ++i){
        int f ;
        scanf("%d",&f) ;
        fav[f]++ ;
        if(fav[f] == 1){
            people.push_back(f) ;
        }
    }

    for(int i = 1 ; i <= k ; ++i)
        scanf("%d",&h[i]) ;

    for (int p = 0 ; p < people.size() ; ++p){
        int nn = fav[people[p]] , mm = card[people[p]] ;
        for(int i = 1 ; i <= nn ; ++i){
            for(int j = 0 ; j <= mm ; ++j){
                for(int l = 0 ; l <= min(k , j) ; ++l){
                    dp[i][j] = max(dp[i][j] , dp[i - 1][j - l] + h[l]) ;
                }
            }
        }
        answer += dp[nn][mm] ;
    }

    printf("%d\n",answer) ;

    return 0 ;
}