#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>

using namespace std ;

const int maxn = 2010 ;

struct Seq {
    int val , pos , used ;
} A[maxn] ;

int n , k , res , m;

vector <int> ans ;

inline int cmp(const void *a , const void *b){
    struct Seq *c = (struct Seq *)a ; 
    struct Seq *d = (struct Seq *)b ;
    if(c->val != d->val)
        return d->val - c->val ;
    else 
        return c->pos - d->pos ;
}

inline int cmp2(const void *a , const void *b){
    struct Seq *c = (struct Seq *)a ; 
    struct Seq *d = (struct Seq *)b ;
    return c->pos - d->pos ;
}


int main(){

    scanf("%d%d",&n , &k) ;

    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&A[i].val) ;
        A[i].pos = i ;
    }

    qsort(&A[1] , n , sizeof(A[1]) , cmp) ;

    for(int i = 1 ; i <= k ; ++i){
        res += A[i].val ; A[i].used = 1 ;
    }

    qsort(&A[1] , n , sizeof(A[1]) , cmp2) ;

    int last_pos = 0 ;

    for(int i = 1 ; i <= n ; ++i){
        if(m + 1 == k)
            break ;
        if(A[i].used == 1){
            ans.push_back(i - last_pos);
            last_pos = i ;
            ++m ;
        }
    }

    ans.push_back(n - last_pos) ;

    printf("%d\n",res) ;

    for(int i = 0 ; i < (int) ans.size() - 1; ++i)
        printf("%d ",ans[i]) ;
    printf("%d\n",ans[ ans.size() - 1]) ;


    return 0 ;

}