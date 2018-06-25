#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std ;

long long n ;

bool check(long long k){
    long long res = n ;
    long long r1 = (long long) 0 ;

    while(res > 0){
        //step1 
        if(res >= k){
            r1 += k ;
            res -= k ; 
        } else {
            r1 += res ;
            res = 0 ; 
            break ;
        }
        //step2 
        res -= (long long)(res / 10) ;
    }
    if(r1 * 2 >= n){
        return true ;
    }
    return false ;
}

int main(){

    cin >> n ;

    long long l = 1 , r = n ;

    while(l < r){
        long long mid = (l + r) >> 1 ;
        if(check(mid)){
            r = mid ;
        } else {
            l = mid + 1 ;
        }
    }

    cout << l << endl ;

    return 0 ;
 
}