/*
    合法的情况是P是一个置换，因此答案里要计算置换的个数。
    Time complexity O(N)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;

const int maxn = 2 * 100000 + 10 ;

int n , cnt_number;
int p[maxn] , b[maxn] ;
bool vis[maxn] ;
int result , s;

void dfs(int u){
    vis[u] = true ;
    if(!vis[p[u]]){
        dfs(p[u]) ;
    }
}

int main(){

    scanf("%d",&n) ;

    for(int i = 1 ; i <= n ; ++i)
        scanf("%d",&p[i]) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&b[i]) ;
        s += b[i] ;
    }
    if(s & 1)
        result = 0 ;
    else result = 1 ;


    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            //cout << i << endl ;
            ++cnt_number ;
            dfs(i) ;
        }
    }

    if(cnt_number > 1)
        result += cnt_number ;

    printf("%d\n",result) ;

    return 0 ;

}