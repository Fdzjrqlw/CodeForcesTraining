#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <vector>

using namespace std ;

const int maxn = 110 ;

vector <int> divisor ;

char s[maxn] ;
int n ;

int main(){

    scanf("%d",&n) ;
    scanf("%s",&s[1]) ;

    for(int i = 1 ; i <= n ; ++i){
        if(n % i == 0)
            divisor.push_back(i) ;
    }

    for(int i = 0 ; i < divisor.size() ; ++i){
        int d = divisor[i] ;
        for(int j = 1 ; j * 2 <= d ; ++j){
            swap(s[j] , s[d + 1 - j]) ;
        }
    }

    printf("%s\n",&s[1]) ;

    return 0 ;
}