#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std ;

int A , B , C , N ;
int AB ;

int main(){

    cin >> A  >> B >> C  >> N ;

    if(A < C){
        printf("-1\n") ;
        return 0 ;
    }
    if(B < C){
        printf("-1\n") ;
        return 0 ;
    }

    AB = A + B - C ;
    if(AB < N){
        printf("%d\n", N - AB) ;
    } else printf("-1\n") ;
    return 0 ;
 
}