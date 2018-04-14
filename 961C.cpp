#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std ;

const int m = 4 ;
const int maxn = 110 ;

char mat[m + 1][maxn][maxn] ;

int n , result = 0x7f7f7f7f;

int seq[m + 1] , vis[m + 1];

void update(){
    //case 1
    int t1 = 0 , t2 = 0 , c1 , c2 ;

    for (int i = 1 ; i <= m ; ++i){
        for (int j = 1 ; j <= n ; ++j){
            for(int k = 1 ; k <= n ; ++k){
                c1 = 0 ; c2 = 0 ;
                if (i == 3 || i == 4) c1 = 1 ;
                if (i == 2 || i == 4) c2 = 1 ;
                if (((n * c1 + n * c2 + j + k) & 1) != (mat[seq[i]][j][k] - '0'))
                    ++t1 ;
                if (((n * c1 + n * c2 + j + k) & 1) == (mat[seq[i]][j][k] - '0'))
                    ++t2 ;
            }
        }
    }

    result = min(result , t1) ;
    result = min(result , t2) ;


    //case2
}

void dfs(int pos){
    if(pos == m){
        update() ;
        return ;
    }
    for (int i = 1 ; i <= m ; ++i){
        if(!vis[i]){
            vis[i] = true ;
            seq[pos + 1] = i ;
            dfs(pos + 1) ;
            vis[i] = false ;
            seq[pos + 1] = 0 ; 
        }
    }
}

int main(){

    char c ;

    scanf("%d",&n) ;
    c = getchar() ;

    for (int i = 1 ; i < m ; ++i){
        for (int j = 1 ; j <= n ; ++j){
            for (int k = 1 ; k <= n ; ++k){
                mat[i][j][k] = getchar() ;
                //scanf("%c",&mat[i][j][k]) ;
            }
            c = getchar() ;
        }
        c = getchar() ;
    }

    for (int j = 1 ; j <= n ; ++j){
        for (int k = 1 ; k <= n ; ++k){
            mat[m][j][k] = getchar() ;
        }
        c = getchar() ;
    }

    dfs(0) ;

    printf("%d\n",result) ;


    return 0 ;

}