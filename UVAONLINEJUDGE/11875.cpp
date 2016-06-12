#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,i,a,tc=1,t;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int ans;
        int ind = ((n+1)>>1) - 1;
        for(i = 0; i < n; i++){
            scanf("%d", &a);
            if(ind == i) ans = a;
        }
        printf("Case %d: %d\n", tc++, ans);
    }

	return 0;
}
