#include <iostream>
#include<cstdio>
 
using namespace std;
char num[100000];
char arv[200000];
void produto(int ini, int fim, int p){
    if(ini == fim){
        if(num[ini] < 0){
            arv[p] = -1;
        }
        else if(num[ini] > 0){
            arv[p] = 1;
        }
        else{
            arv[p] = 0;
        }
    }
    else{
        produto(ini, (ini+fim)/2, 2*p);
        produto((ini+fim)/2 + 1, fim, 2*p+1);
        arv[p] = arv[2*p]*arv[2*p+1];
    }
}

int pesquisar(int L, int R, int i, int j, int p) {
    if(j < L || i > R)
        return 1;
    if(L >= i && R <= j){
        return arv[p];
    }
    int left, right;
    left = pesquisar(L, (L+R)/2, i, j, 2*p);
    right = pesquisar((L+R)/2 + 1, R, i, j, 2*p+1);
    return left*right;

}

void update(int L, int R, int pos, int num, int p){
    if(L == R){
        if(num < 0){
            arv[p] = -1;
        }
        else if(num > 0){
            arv[p] = 1;
        }
        else{
            arv[p] = 0;
        }
    }
    else if(pos <= (L+R)/2){
        update(L, (L+R)/2, pos, num, 2*p);
        arv[p] = arv[2*p]*arv[2*p+1];
    }
    else{
        update((L+R)/2+1, R, pos, num, 2*p+1);
        arv[p] = arv[2*p]*arv[2*p+1];
    }
        
}

int main() {
    int N, K, i, x, y, resp, ini, fim;
    char c;
    while(scanf("%d %d", &N, &K) == 2){
        for(i = 0; i < N; i++)
            scanf("%d", &num[i]);
        produto(0, i-1, 1);
        ini = 0;
        fim = i-1;
        for(i = 0; i < K; i++){
            scanf(" %c %d %d", &c, &x, &y);
            if(c == 'C'){
                update(ini, fim, x-1, y, 1);
            }
            else{
                resp = pesquisar(ini, fim, x-1, y-1, 1);
                if(resp == -1)
                    cout << "-";
                else if(resp == 1)
                    cout << "+";
                else
                    cout << "0";
            }
        }
        cout << endl;
        
    }
    
    return 0;
}
