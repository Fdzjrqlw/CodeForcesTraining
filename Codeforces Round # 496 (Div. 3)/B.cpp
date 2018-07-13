

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std ;
const int maxn = 200000 + 5 ;

int l1 , l2 , res ;

char s1[maxn] , s2[maxn] ;

int main(){

    scanf("%s",s1) ;
    scanf("%s",s2) ;

    l1 = strlen(s1) ;
    l2 = strlen(s2) ;

    int res = l1 + l2 ;

    for(int i = 1 ; i <= min(l1 , l2) ; ++i){
        if(s1[l1 - i] != s2[l2 - i]){
            break ;
        }
        res -= 2 ;
    }

    printf("%d\n",res) ;

    return 0 ;
}