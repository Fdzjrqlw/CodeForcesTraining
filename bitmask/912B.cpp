

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std ;

long long n , k ;

int main(){

    cin >> n >> k ;

    if(k == 1){
        cout << n << endl ;
        return 0 ;
    }

    long long answer = (long long) 1 ;

    for( ; n ; n >>= 1)
        answer <<= 1 ;
    cout << answer - 1 << endl ;

    return 0 ;

}