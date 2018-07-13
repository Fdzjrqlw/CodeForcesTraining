
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 120000 + 5 ;

int n , m , res ;
long long A[maxn] , maxa;
long long two[maxn] ;

map <int , int> T ;  

int main(){

    cin >> n ;

    for(int i = 1 ; i <= n ; ++i){
        cin >> A[i] ;
        maxa = max(maxa , A[i]) ;
        T[A[i]]++ ;
    }

    two[0] = (long long) 1 ;
    for(int i = 1 ; ; ++i){
        two[i] = two[i - 1] << 1 ;
        if(two[i] > maxa * 2)
            break ;
        m = i + 1 ;
    }

    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            if(two[j] > A[i]){
                if(T.find(two[j] - A[i]) != T.end()){
                    if((T[two[j] - A[i]] >= 2) || (A[i] * 2 != two[j])){
                        ++res ;
                        break ;
                    }
                }
            }
        }
    }

    cout << n - res << endl ;

    return 0 ;

}