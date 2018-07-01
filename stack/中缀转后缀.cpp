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

stack <char> gs ;

int main(){

    scanf("%[^\n]s",s) ;
    len = strlen(s) ;

    for(int i = 0 ; i < len ; ){
        //cout  << s[i] << " " << endl ;
        if(s[i] == ' '){
            ++i ;
            continue ;
        }
        if(s[i] == '-'){
            if(i + 1 < len && (s[i + 1] >= '0' && s[i + 1] <= '9')){
                int x = 0 ;
                ++i ;
                while (i < len && (s[i] >= '0' && s[i] <= '9')){
                    x = x * 10 + (s[i] - '0') ;
                    ++i ;
                }
                x = x * (-1) ;
                printf("%d ",x) ;
                continue ;
            }
        }
        if(s[i] >= '0' && s[i] <= '9'){
            int x = 0 ;
            while(i < len && (s[i] >= '0' && s[i] <= '9')){
                x = x * 10 + (s[i] - '0') ;
                ++i ;
            }
            printf("%d ",x) ;
            continue ;
        }
        if(s[i] == '('){
            ++i ;
            gs.push('(') ;
            continue ;
        }
        if(s[i] == '+' || s[i] == '-'){
            while(!gs.empty()){
                char op = gs.top() ;
                if(op == '+' || op == '-' || op == '*' || op == '/'){
                    gs.pop() ;
                    printf("%c ", op) ;
                } else {
                    break ;
                }
            }
            gs.push(s[i]) ;
            ++i ;
            continue ;
        }
        if(s[i] == '/' || s[i] == '*'){
            while(!gs.empty()){
                char op = gs.top() ;
                if(op == '*' || op == '/'){
                    gs.pop() ;
                    printf("%c ", op) ;
                } else {
                    break ;
                }
            }
            gs.push(s[i]) ;
            ++i ;
            continue ;
        }
        if(s[i] == ')'){
            while(!gs.empty()){
                char op = gs.top() ;
                if(op != '('){
                    printf("%c ",op) ;
                    gs.pop() ;
                } else {
                    gs.pop() ; break ;
                }
            }
            ++i ;
            continue ;
        }
    }

    while(!gs.empty()){
        char op = gs.top() ; gs.pop() ;
        printf("%c ",op) ;
    }

    return 0 ;
}
