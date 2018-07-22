#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 200010 ;

long long A[maxn] ;

int n ;
long long res ;

long long s1 , s2 ;
 

int main(){

    cin >> n ;

    for(int i = 1 ; i <= n ; ++i)
        cin >> A[i] ;

    int l = 0 , r = n + 1 ;
    for ( ; l < r ; ){
        if(s1 < s2){
            ++l; 
            if(l == n + 1) 
                break ;
            s1 = s1 + A[l] ;
        } else {
            --r ; 
            if(r == 0)
                break ;
            s2 = s2 + A[r] ;
        }
        if((l < r) && (s1 == s2)){
            res = s1 ;
        }
    }

    cout << res << endl ;

    return 0 ;

}