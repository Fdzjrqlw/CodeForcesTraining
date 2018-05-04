/*
    从B->A模拟即可.
    Time complexity O(N)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;

const int maxn = 100 + 10 ;
vector <int> answer ;

int a , b ;

int main(){

    scanf("%d%d",&a , &b) ;

    while(b > a){
        answer.push_back(b) ;
        if((b & 1) == 0){
            b >>= 1; 
        } else {
            if(b % 10 == 1){
                b /= 10 ;
            } else break ;
        }
    }

    if(b != a){
        printf("NO\n") ;
        return 0;
    } 

    printf("YES\n") ;
    printf("%d\n",answer.size() + 1) ;
    printf("%d",a) ;

    for(int i = answer.size() - 1 ; i >= 0 ; --i)
        printf(" %d",answer[i]) ;
    printf("\n") ;

    return 0 ;

}

