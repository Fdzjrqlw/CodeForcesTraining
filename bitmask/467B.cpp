
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std ;

const int maxm = 1010 ;

int n , m , k , result ;
int state[maxm] ;
int final_state ;

int main(){
    cin >> n >> m >> k ;

    for(int i = 1; i <= m ; ++i)
        cin >> state[i] ;

    cin >> final_state ;

    for(int i = 1 ; i <= m ; ++i)
        state[i] = state[i] ^ final_state ;

    for(int i = 1 ; i <= m ; ++i){
        int s = state[i] , t = 0;
        for( ; s ; s >>= 1){
            if(s & 1)
                ++t ;
        }
        if(t <= k)
            ++result ;
    }
    cout << result << endl ;
    return 0 ;

}