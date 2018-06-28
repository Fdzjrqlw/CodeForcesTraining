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
#include <stack>

using namespace std ;
const int maxL = 1100 ;

int n , k , res , tot ;

int g[5][maxL] ;

struct Node {
    int car , x , y ;
} ;

vector <Node> result ;

stack <int> gs ;

int loc[maxL][3] ;
int dict[maxL] ;
int antidict[maxL][3] ;

pair <int,int> next_move(int x , int y){
    int xx , yy ;
    if(x == 2 && y > 1){
        xx = x ; yy = y - 1 ;
    } else if(x == 2 && y == 1){
        xx = 3 ; yy = 1 ;
    } else if(x == 3 && y < n){
        xx = 3 ; yy = y + 1 ;
    } else if(x == 3 && y == n){
        xx = 2 ; yy = n ;
    }
    return make_pair(xx , yy) ;
}

pair <int,int> last_move(int x , int y){
    int xx , yy ;
    if(x == 2 && y < n){
        xx = x ; yy = y + 1 ;
    } else if(x == 2 && y == n){
        xx = 3 ; yy = n ;
    } else if(x == 3 && y == 1){
        xx = 2 ; yy = 1 ;
    } else if(x == 3 && y > 1){
        xx = 3 ; yy = y - 1 ;
    }
    return make_pair(xx , yy) ;
}

bool check(){
    for(int i = 2 ; i <= 3 ; ++i)
        for(int j = 1 ; j <= n ; ++j)
            if(g[i][j] != 0)
                return true ;
    return false ;
}


int main(){

    scanf("%d%d",&n,&k) ;

    for(int i = 1 ; i <= 4 ; ++i)
        for(int j = 1 ; j <= n ; ++j)
            scanf("%d",&g[i][j]) ;


    for(int i = 1 ; i <= n ; ++i){
        if(g[2][i] != 0){
            if(g[1][i] == g[2][i]){
                Node t ;
                t.car = g[2][i] ;
                t.x = 1 ; t.y = i ;
                result.push_back(t) ;
                g[1][i] = g[2][i] = 0 ;
                ++res ;
            }
        }
    }

    for(int i = 1 ; i <= n ; ++i){
        if(g[3][i] != 0){
            if(g[3][i] == g[4][i]){
                Node t ;
                t.car = g[3][i] ;
                t.x = 4 ; t.y = i ;
                result.push_back(t) ;
                g[3][i] = g[4][i] = 0 ;
                ++res ;
            }
        }
    }

    for(int i = 2 ; i <= 3 ; ++i)
        for(int j = 1 ; j <= n ; ++j)
            if(g[i][j] != 0){
                loc[g[i][j]][0] = i ;
                loc[g[i][j]][1] = j ;
                gs.push(g[i][j]) ;
            }

    if(gs.size() == 2 * n){
        printf("-1\n") ;
        return 0 ;
    }

    while(check()){
        for(int i = 1 ; i <= n ; ++i){
            if(g[2][i] != 0){
                if(g[1][i] == g[2][i]){
                    Node t ;
                    t.car = g[2][i] ;
                    t.x = 1 ; t.y = i ;
                    result.push_back(t) ;
                    g[1][i] = g[2][i] = 0 ;
                    ++res ;
                }
            }
        }

        for(int i = 1 ; i <= n ; ++i){
            if(g[3][i] != 0){
                if(g[3][i] == g[4][i]){
                    Node t ;
                    t.car = g[3][i] ;
                    t.x = 4 ; t.y = i ;
                    result.push_back(t) ;
                    g[3][i] = g[4][i] = 0 ;
                    ++res ;
                }
            }
        }

        //
        int nx = 0 , ny = 0;
        for(int i = 2 ; i <= 2 ; ++i){
            for(int j = 2 ; j <= n ; ++j){
                if(g[i][j - 1] == 0){
                    nx = i ; ny = j ;
                }
            }
        }
        for(int i = 3 ; i <= 3 ; ++i){
            for(int j = 1 ; j < n ; ++j){
                if(g[i][j + 1] == 0){
                    nx = i ; ny = j ;
                }
            }
        }
        if(g[3][1] == 0){
            nx = 2 ; ny = 1 ;
        }
        if(g[2][n] == 0){
            nx = 3 ; ny = n ;
        }

        for(int i = 1 ; i < 2 * n ; ++i){
            if(g[nx][ny] != 0){
                ++res ;
                pair <int,int> np = next_move(nx , ny) ;
                Node t ;
                t.car = g[nx][ny] ;
                g[nx][ny] = 0 ;
                g[np.first][np.second] = t.car ;
                t.x = np.first ; t.y = np.second ;
                loc[t.car][0] = np.first ; loc[t.car][1] = np.second ;
                result.push_back(t) ;
            }
            pair <int , int> lp = last_move(nx , ny) ;
            nx = lp.first ; ny = lp.second ;
        }
    }

    cout << result.size() << endl ;

    for(int i = 0 ; i < result.size() ; ++i){
        Node t = result[i] ;
        printf("%d %d %d\n",t.car , t.x , t.y) ;
    }



    return 0 ;
}
