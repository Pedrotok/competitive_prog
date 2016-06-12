#include <bits/stdc++.h>

using namespace std;

int main(){
    int d[1001];
    
    memset(d, -1, sizeof d);
    
    for(int i = 1; i <= 1000; i++){
        int sum = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0)
                sum += j;
        }
        if(sum <= 1000) d[sum] = i;
    }
    int n, t = 1;

    while(scanf("%d", &n) == 1, n){
        printf("Case %d: %d\n", t++, d[n]);
    }
    
    
    return 0;
}