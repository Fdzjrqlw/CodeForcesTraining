#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>

using namespace std ;

const int maxn = 400000 + 100 ;

char s[maxn] ;
int n , k;
int t1[27] , t2[27] , t3[27];

int main(){

    scanf("%d%d",&n,&k) ;

    scanf("%s",s) ;

    for(int i = 0 ; i < n ; ++i){
        t1[s[i] - 'a' + 1] ++ ;
        t2[s[i] - 'a' + 1] ++ ;
    }

    int to = 0 , pos ;
    for(int i = 1 ; i <= 26 ; ++i){
        if(to  + t1[i] >= k) {
            t2[i] = k - to ;
            pos = i ;
            break ;
        }
        to += t1[i] ;
    }

    for (int i = pos + 1 ; i <= 26 ; ++i)
        t2[i] = 0 ;

    for(int i = 0 ; i < n ; ++i){
        t3[s[i] - 'a' + 1] ++ ;
        if(t3[s[i] - 'a' + 1] > t2[s[i] - 'a' + 1]){
            printf("%c",s[i]) ;
        }
    }

    printf("\n") ;

    return 0 ;
}