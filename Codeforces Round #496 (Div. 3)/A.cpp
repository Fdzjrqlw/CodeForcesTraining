

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std ;

vector <int> res ; 

int n ; 

int main(){
    scanf("%d",&n) ;

    int t = 0 ;

    for(int i = 1 ; i <= n ; ++i){
        int x ;
        scanf("%d",&x) ;
        if(x == 1){
            if(t != 0){
                res.push_back(t) ;
            }
            t = 1 ;
        } else {
            t = max(t , x) ; 
        }
    }
    res.push_back(t) ;

    printf("%d\n",(int) res.size()) ;

    for(int i = 0 ; i < (int) res.size() - 1 ; ++i)
        printf("%d ", res[i]) ;
    printf("%d\n" , res[(int)res.size() - 1]) ;

    return 0 ;
}