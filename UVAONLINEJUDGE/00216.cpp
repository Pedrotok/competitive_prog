#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

#define mp make_pair
#define ff first
#define ss second

using namespace std;

int x[10], y[10];
bool used[10];
vector<int> nb, nb_ans;
double ans;

double dist(int i, int j){
    double a1 = x[j]-x[i], a2 = y[j]-y[i];
    return (16 + sqrt(a1*a1+a2*a2));
}

void backtrack(int cnt, double tot, int n){
    if(cnt == n){
        if(tot < ans){
            ans = tot;
            nb_ans = nb;
        }
        return ;
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        used[i] = 1;
        double aux = tot;
        if(!nb.empty()) aux+=dist(nb.back(), i);
        nb.push_back(i);
        backtrack(cnt+1, aux, n);
        nb.pop_back();
        used[i] = 0;
    }
}

int main(){
    int i,n,tc=1;

    while(scanf("%d", &n),n){
        for(i = 0; i < n; i++)
            scanf("%d%d", &x[i], &y[i]), used[i] = 0;
        ans = 1e9;
        backtrack(0,0,n);
        printf("**********************************************************\n");
        printf("Network #%d\n", tc++);
        for(i = 0; i < n-1; i++){
            int i1 = nb_ans[i], i2 = nb_ans[i+1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",x[i1],y[i1],x[i2],y[i2],dist(i1,i2));
        }

        printf("Number of feet of cable required is %.2lf.\n", ans);
    }

	return 0;
}
