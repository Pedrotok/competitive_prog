#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,r,i,tc=1;

    while(scanf("%d%d", &r,&n),n+r){
        if(n*26+n< r){
            printf("Case %d: impossible\n",tc++);
            continue;
        }
        printf("Case %d: %d\n", tc++, (r-1)/n);
    }

	return 0;
}
