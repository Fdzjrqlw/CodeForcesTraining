
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std ;

int n ;

int main(){

    int result = 0 ;

    cin >> n ;

    for ( ; n ; n >>= 1)
        if(n & 1)
            ++result ;
    cout << result << endl ;

    return 0 ;

}