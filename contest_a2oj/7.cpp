#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

struct pessoa{
    int ano,mes,dia;
    string nome;
    
    bool operator<(const pessoa &p)const{
        if(ano == p.ano){
            if(mes == p.mes)
                return dia < p.dia;
            return mes < p.mes;
        }
        return ano < p.ano;
    }
};

vector<pessoa> v;

int main(){
    int n;
    pessoa aux;
    
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
        cin >> aux.nome >> aux.dia >> aux.mes >> aux.ano;
        v.push_back(aux);
    }
    
    sort(v.begin(),v.end());
    
    cout << v[n-1].nome << "\n";
    cout << v[0].nome << "\n";
    
 
    return 0;
}