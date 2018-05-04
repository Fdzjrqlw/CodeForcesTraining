/*
    对比排序好的数列，找环
    Time complexity O(N)
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std ;

const int maxn = 100010 ;

map <int , int> T ;

inline int cmp(const void *a , const void *b){
    return *(int *)a - *(int *)b ;
}

int n ;
int a[maxn] , b[maxn] , vis[maxn] , k;

vector <int> result[maxn] ;

int main(){

    scanf("%d",&n) ;

    for (int i = 1 ; i <= n ; ++i){
        scanf("%d",&a[i]) ;
        T[a[i]] = i ;
        b[i] = a[i] ;
    }

    qsort(&b[1] , n , sizeof(b[1]) , cmp) ;


    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            ++k ;
            int x = i ;
            while(!vis[x]){
                result[k].push_back(x) ;
                vis[x] = 1 ;
                x = T[b[x]] ;
            }
        }
    }

    printf("%d\n",k) ;

    for(int i = 1 ; i <= k ; ++i){
        printf("%d",result[i].size()) ;
        for(int j = 0 ; j < result[i].size() ; ++j)
            printf(" %d",result[i][j]) ;
        printf("\n") ;
    }

    return 0 ;

}