/*

分成4段递归处理，注意出现n>m的情况。
Time complexity O(N)
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std ;
const int maxn = 100010 ;

char str1[] = "What are you doing while sending \"" ;
char str2[] = "\"? Are you busy? Will you send \"" ;
char str3[] = "\"?" ;
char str0[] = "What are you doing at the end of the world? Are you busy? Will you save us?";

long long l[maxn] ;
int l1 , l2 , l3  , m;

void init(){
    l1 = strlen(str1) ;
    l2 = strlen(str2) ;
    l3 = strlen(str3) ;

    l[0] = (long long)strlen(str0) ;

    for ( ; l[m] <= 1e18 ; ++m){
        l[m + 1] = (long long) l1 + l[m] + (long long) l2 + l[m] + (long long) l3 ;
    }

}

char dfs(int n , long long k){
    if(k > l[n] && n <= m){
        return '.' ;
    }
    if(n == 0){
        return str0[k - 1] ;
    }
    if(k <= (long long) l1)
        return str1[k - 1] ;
    k -= l1 ;
    if(k <= l[n - 1] || n > m)
        return dfs(n - 1 , k) ;
    k -= l[n - 1] ;
    if(k <= l2)
        return str2[k - 1] ;
    k -= l2 ;
    if(k <= l[n - 1] || n > m)
        return dfs(n - 1 , k) ;
    k -= l[n - 1] ;
    return str3[k - 1] ;
}

int main(){

    int q , n ; 
    long long k;

    init() ;
    cin >> q ;



    for(int i = 1 ; i <= q ; ++i){
        cin >> n >> k ;

        cout << dfs(n , k);
    }

    cout << endl ;

    return 0 ;

}