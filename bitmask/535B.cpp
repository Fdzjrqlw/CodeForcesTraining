
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std ;

int n ;

long long two[64] ;
int seq[64] ;

int main(){
    cin >> n ;

    int result = 0 , l = 0 ;

    int x = n ;
    for( ; x ; x /= 10) {
        seq[++ l] = x % 10 ;
    }

    two[0] = 1 ;

    for(int i = 1 ; ; ++i){
        two[i] = two[i - 1] <<  1 ;
        if(two[i] > n)
            break ;
    }

    x = n ;
    
    for(int i = l ; i >= 1 ; --i){
        if(seq[i] == 7){
            result = result + two[i - 1] ;
        }
    }


    result = result + two[l] - 1 ;

    cout << result << endl ; 

    return 0 ;
}