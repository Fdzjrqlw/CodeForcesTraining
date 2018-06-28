#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std ;
const int inf = 0x3f3f3f3f ;
const int maxn = 100010 ;

int n , res ; 
int a[maxn << 1] ;

int main(){

    scanf("%d",&n) ;

    for(int i = 1 ; i <= (n << 1) ; ++i){
        scanf("%d",&a[i]) ;
    }

    for(int i = 1 ; i < n ; ++i){
        int p = a[2 * i - 1] ;
        int pos = 2 * i ;
        for(int j = 2 * i ; j <= 2 * n ; ++j){
            if(a[j] == p){
                pos = j ;
                break ;
            }
        }
        while(pos > 2 * i){
            swap(a[pos] , a[pos - 1]) ;
            pos-- ;
            ++res ;
        }
    }

    printf("%d\n",res) ;

    return 0 ;
}
