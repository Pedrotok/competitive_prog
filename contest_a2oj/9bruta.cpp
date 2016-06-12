#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

ll _sieve_size;
bitset<50000005> bs;
vector<int> primes;

void sieve(ll upperbound){
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2; i <= _sieve_size; i++){
        if(bs[i]){
            for(ll j = i*i; j <= _sieve_size; j+=i)
                bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}
ll Prime(ll N){
    
    ll qnts = 0;
    ll last = 0;
    int aux = sqrt(N);
    
    for (ll i = 2; i <= aux; i++) {
        
        if (!(N % i) && bs[i]) {
            last = i;
            qnts++;
            while (!(N % i)) {
                N /= i;
            }
        }
    }
    if (N > 1) {
        qnts++;
        last = N;
    }
    if (qnts < 2)
        return -1;
    return last;
}

int main(){
    ll n;
    
    sieve(17500003);

    while(scanf("%lld", &n), n) {
        if(n < 0) n*=-1;
        printf("%lld\n", Prime(n));
    }
    
    return 0;
}