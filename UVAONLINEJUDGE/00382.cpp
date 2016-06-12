#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,i,a,t;

    printf("PERFECTION OUTPUT\n");
    while(scanf("%d", &n),n){
        if(n < 0) n*=-1;
        int sum = 0;
        for(i = 2; i*i <= n; i++){
            if((n%i) == 0){
                sum += i;
                if(n/i != i) sum += n/i;
            }
        }
        if(n > 1) sum++;
        printf("%5d  %s\n",n, (sum==n?"PERFECT":(sum>n?"ABUNDANT":"DEFICIENT")));
    }
    printf("END OF OUTPUT\n");

	return 0;
}
