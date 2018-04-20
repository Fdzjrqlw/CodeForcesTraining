

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std ;
const int maxlen = 10 ;

int n ;
int val ;
char op ;
int ones , zeros ;

int main(){

    scanf("%d",&n) ;
    char c ;
    c = getchar() ;
    ones = 1023 ;
    zeros = 0 ;

    for(int i = 1 ; i <= n ; ++i){
        op = getchar() ;
        scanf("%d",&val) ;
        if(op == '^'){
            ones = ones ^ val ; zeros = zeros ^ val ;
        } else if(op == '|'){
            ones = ones | val ; zeros = zeros | val ;
        } else if(op == '&'){
            ones = ones & val ; zeros = zeros & val ;
        }

        c = getchar() ;
    }

    int or_number = ((zeros) ^ (~ones)) & 1023 ;
    int xor_number = (~ones) & 1023 ;

    printf("2\n") ;
    printf("| %d\n",or_number) ;
    printf("^ %d\n",xor_number) ;

    return 0 ; 

}

/*
暴力做法 按位考虑
*/

/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std ;
const int maxlen = 10 ;

int n ;
int bits[maxlen][2] ;
int result[maxlen][2] , answer[2];
char op[500010] ;
int val[500010] ;
int seq[maxlen] ;

int main(){

    scanf("%d",&n) ;
    char c ;
    c = getchar() ;

    memset(bits , 0 , sizeof(bits)) ;

    for(int i = 1 ; i <= n ; ++i){
        c = getchar() ;
        scanf("%d",&val[i]) ;
        op[i] = c ;

        c = getchar() ;
    }

    for(int i = 0 ; i < maxlen ; ++i)
        bits[i][1] = 1 ;

    for(int i = 1 ; i <= n ; ++i){
        int x = val[i] ;
        int l = 0;
        for(int j = 0 ; j < maxlen ; ++j)
            seq[j] = 0 ;
        for( ; x ; x >>= 1, ++l)
            seq[l] = x & 1 ;

        for(int j = 0 ; j < maxlen ; ++j){
            if(op[i] == '|'){
                bits[j][0] |= seq[j] ; bits[j][1] |= seq[j] ;
            } else if(op[i] == '^'){
                bits[j][0] ^= seq[j] ; bits[j][1] ^= seq[j] ;
            } else if(op[i] == '&'){
                bits[j][0] &= seq[j] ; bits[j][1] &= seq[j] ;
            }
        }
        
    }

    for(int i = 0 ; i < maxlen ; ++i){
        if(bits[i][0] == 1 && bits[i][1] == 1){
            result[i][0] = 1 ; result[i][1] = 0 ;
        }
        if(bits[i][0] == 0 && bits[i][1] == 1){
            result[i][0] = 0 ; result[i][1] = 0 ;
        }
        if(bits[i][0] == 0 && bits[i][1] == 0){
            result[i][0] = 1 ; result[i][1] = 1 ;
        }
        if(bits[i][0] == 1 && bits[i][1] == 0){
            result[i][0] = 0 ; result[i][1] = 1 ;
        }
    }



    printf("2\n") ;
    for(int j = 0 ; j < 2 ; ++j){
        answer[j] = 0 ;
        for(int i = 0 ; i < maxlen ; ++i){
            answer[j] += (1 << i) * result[i][j] ;
        }
    }

    printf("| %d\n",answer[0]) ;
    printf("^ %d\n",answer[1]) ;

    return 0 ;

}*/
