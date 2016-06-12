#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

struct tf{
    int id, req;
    double pr;
    char name[100];
    bool operator<(const tf &p) const{
        if(req == p.req){
            if(pr == p.pr)
                return id < p.id;
            return pr < p.pr;
        }
        return req > p.req;
    }
};

tf v[1005];

int main(){
    int n,m,tc = 1,i; 
    
    while(scanf("%d%d", &n,&m) == 2 && n+m){
        if(tc > 1) printf("\n");
        for(i = 0; i < n; i++)
            scanf(" %*[^\n]");
        
        for(i = 0; i < m; i++){
            scanf(" %[^\n] %lf %d", v[i].name, &v[i].pr, &v[i].req);
            for(int j = 0; j < v[i].req; j++) scanf(" %*[^\n]");
//             printf(" %s %lf %d\n", v[i].name, v[i].pr, v[i].req);
            v[i].id = i;
        }
        sort(v,v+m);
        printf("RFP #%d\n%s\n", tc++, v[0].name);
    }
    
 
    return 0;
}