#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

class UnionFind {
private: vector <int> p, rank;
public:
    UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main(){
    
    
    while (1) {
    int qnt = 0;
        int i = 0;
        int a, b;
        
        UnionFind v(100005);
        
        while(scanf("%d", &a) == 1 && a != -1){
            scanf("%d", &b);
            i = 1;
           
            if (v.isSameSet(a, b)) {
                qnt++;
            } else {
                v.unionSet(a, b);
            }
        }
        if (i == 0)
            break;
        printf("%d\n", qnt);
    }
    
 
    return 0;
}