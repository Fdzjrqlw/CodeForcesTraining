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

const int maxn = 200010 ;

char s[maxn] ;
int len ;

stack <int> gs ;

int main(){

    scanf("%[^\n]s",s) ;
    len = strlen(s) ;


    for(int i = 0 ; i < len ; ){

        if(s[i] == ' ') {
            ++i ; continue ;
        }

        if(s[i] == '-'){
            //读入负数
            if((i + 1 < len) && (s[i + 1] >= '0' && s[i + 1] <= '9')){
                int x = 0 ;
                ++i ;
                while(i < len && (s[i] >= '0' && s[i] <= '9')){
                    x = x * 10 + (s[i] - '0') ;
                    ++i ;
                }
                x = x * (-1) ;
                gs.push(x) ;
                continue ;
            }
        }

        if(s[i] >= '0' && s[i] <= '9'){
            int x = 0 ;
            while(i < len && s[i] != ' '){
                x = x * 10 + (s[i] - '0') ;
                ++i ;
            }
            gs.push(x) ;
            continue ;
        }

        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            if(gs.empty()){
                printf("Error!\n") ;
                return 0 ;
            }
            int y = gs.top() ; gs.pop() ;
            if(gs.empty()){
                printf("Error!\n") ;
                return 0 ;
            }
            int x = gs.top() ; gs.pop() ;
            int z ;
            cout  << x << " " << y << endl ;
            if(s[i] == '+'){
                z = x + y ;
            } else if(s[i] == '-'){
                z = x - y ;
            } else if(s[i] == '*'){
                z = x * y ;
            } else if(s[i] == '/'){
                z = x / y ;
            }
            gs.push(z) ;
            ++i ;
        }
    }

    if(gs.empty()){
        printf("Error\n") ;
        return 0 ;
    }

    int res = gs.top() ; gs.pop() ;
    printf("%d\n",res) ;


    return 0 ;
}
