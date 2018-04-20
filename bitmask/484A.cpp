
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std ;
int seq1[65] , seq2[65] ; 
long long two[65] ;

int n ;


long long solve(long long l , long long r){
    if(l == r)
        return l ;
    int l1 = 0 , l2 = 0 ;
    memset(seq1 , 0 , sizeof(seq1)) ;
    memset(seq2 , 0 , sizeof(seq2)) ;

    for(long long x = l ; x ; x >>= 1)
        seq1[++l1] = x & 1 ;
    for(long long y = r ; y ; y >>= 1)
        seq2[++l2] = y & 1 ;

    int pos = 0;
    for(int i = l2 ; i >= 1 ; --i){
        if(seq1[i] != seq2[i]){
            pos = i ; break ;
        }
    }

    for(int i = 1 ; i < pos ; ++i){
        seq1[i] = 1 ;
    }

    long long result = 0 ;
    bool tag = true ;

    for(int i = 1 ; i <= pos ; ++i){
        if(seq2[i] == 0){
            tag = false ; break ;
        }
    }

    if(tag){
        return r ;
    } else {
        for(int i = 1 ; i <= l2 ; ++i){
        result += two[i - 1] *  (long long) seq1[i] ;
        }
    }

    return result ;
}

int main(){
    cin >> n ;

    two[0] = (long long) 1;

    for(int i = 1 ; i <= 64 ; ++i)
        two[i] = two[i - 1] << 1 ;

    long long l , r ;
    for(int i = 1 ; i <= n ; ++i){
        cin >> l >> r ;
        cout << solve(l , r) << endl ;
    }

    return 0 ;
}