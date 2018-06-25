#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <sstream>
#include <set>

using namespace std ;

map <long long , string> dict ;
set <long long> record[10] ;

long long n ;
long long ten[11] ;

string toString(long long x){
    ostringstream os ;
    os << x ;
    return os.str() ;
}

int getlen(long long x){
    int t = 0 ;
    while(x){
        x /= 10 ;
        t += 1 ;
    }
    return (max(1 , t)) ;
}

void relax(long long x , string t){
    if(x > n || t.length() >= getlen(x)){
        return ;
    }
    if(dict.count(x) && dict[x].length() <= t.length()){
        return ;
    }
    //更新
    record[dict[x].length()].erase(x) ;
    dict[x] = t ;
    record[t.length()].insert(x) ;
}

string getString(long long x){
    if(dict.count(x)){
        return dict[x] ;
    }
    return toString(x) ;
}

void generatePowers(){
    for(long long x  = 2 ; x * x <= n; ++x){
        long long c = x * x ;
        int p = 2 ;
        while (c  <= n){
            string temp = toString(x) + "^" + toString(p) ;
            relax(c , temp) ;
            c *= x ;
            p += 1 ;
        }
    }
}

void generateMultiplyAndMultiply(int maxlen){
    for(int i = 1 ; i <= maxlen ; ++i){
        for(int j = i ; i + j + 1 <= maxlen ; ++j){
            for(auto x : record[i]){
                for (auto y : record[j]){
                    relax(x * y , getString(x) + "*" + getString(y)) ;
                }
            }
        }
    }
}

void generateMultiplayAndSimple(int maxlen){
    for(int i = 1 ; i <= maxlen ; ++i){
        for(long long x = 1 ; x < ten[maxlen - 1 - i] ; ++x){
            for (auto y : record[i]){
                relax(x * y , getString(y) + "*" + getString(x)) ;
            }
        }
    }
}

void prepare(){
    ten[0] = 1 ;
    for(int i = 1 ; i <= 10 ; ++i)
        ten[i] = 10 * ten[i - 1] ;
    generatePowers() ;
    generateMultiplyAndMultiply(8) ;
    generateMultiplayAndSimple(8) ;
}

string res ;

void relaxres(string t){
    if(t.length() < res.length()){
        res = t ;
    }
}

void check_plus(){
    for(int i = 1 ; i * 2 + 1 < res.length() ; ++i){
        for(long long x = 1 ; x <= ten[i] ; ++x){
            relaxres(getString(x) + "+" + getString(n - x)) ;
            if(n % x == 0){
                relaxres(getString(x) + "*" + getString(n / x)) ;
            }
        }
        for (auto x : record[i]){
            relaxres(getString(x) + "+" + getString(n - x)) ;
            if(n % x == 0){
                relaxres(getString(x) + "*" + getString(n / x)) ;
            }
        }
    }
}

int main(){

    cin >> n ;
    prepare() ;

    res = getString(n) ;

    check_plus() ;
    cout << res << endl ;

    return 0 ;
}
