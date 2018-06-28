#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std ;

int n , res ;
int module[6] = {0 , 100 , 20 , 10 , 5 , 1} ;

int main(){

    scanf("%d",&n) ;


    for(int i = 1 ; i <= 5 ; ++i){
        res += n / module[i] ;
        n %= module[i] ;
    }

    printf("%d\n",res) ;



    return 0 ;
}
