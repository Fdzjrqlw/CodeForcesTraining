#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 200010 ;

char a[maxn] , b[maxn] ;
 
int n , res ;

int h[27] ;

int Calc(char a1 , char a2 , char b1 , char b2){
    //cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl ;
    if(b1 == b2){
        if(a1 == b1){
            if(a2 == a1){
                return 0 ;
            } else return 1 ;
        } else {
            if(a2 == a1){
                return 0 ;
            } else {
                return 1 ;
            }
        }
    } else {
        if(a1 == b1){
            if(a2 == b2){
                return 0 ;
            } else return 1 ;
        } else {
            if(a1 == b2){
                if(a2 == b1){
                    return 0 ;
                } else return 1 ;
            } else {
                if((a2 == b1) || (a2 == b2)){
                    return 1 ;
                } else return 2 ;
            }
        }
    }
}

int main(){

    scanf("%d\n",&n) ;

    scanf("%s",&a[1]) ;

    scanf("%s",&b[1]) ;

    if(n % 2 == 0){
        for(int i = 1 ; i <= (n / 2) ; ++i){
            res += Calc(a[i] , a[n - i + 1] , b[i] , b[n - i + 1]) ;
        }
    } else {
        if(a[(n + 1) / 2] != b[(n + 1) / 2])
            ++res ;
        for(int i = 1 ; i < (n + 1) / 2 ; ++i){
            res += Calc(a[i] , a[n - i + 1] , b[i] , b[n - i + 1]) ;
            //cout << Calc(a[i] , a[n - i + 1] , b[i] , b[n - i + 1]) << endl ;
        }
    }

    printf("%d\n",res) ;

    return 0 ;

}