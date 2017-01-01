#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

const double PI = acos(-1);
const double EPS = 1e-7;

pair<double,double> p[100];

double det(pair<double,double> A, pair<double,double> B, pair<double,double> C){
	return A.ff*B.ss + A.ss*C.ff + B.ff*C.ss - (C.ff*B.ss + C.ss*A.ff + B.ff*A.ss);
}

double dist(pair<double,double> A, pair<double,double> B){
	double aux = A.ff-B.ff, aux2 = A.ss-B.ss;
	return sqrt(aux*aux + aux2*aux2);
}

int main(){
	int n;
	double raio;

	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++){
			scanf("%lf%lf", &p[i].ff, &p[i].ss);
		}
		scanf("%lf", &raio);

		bool deu_certo = 0, sair = 0;;
		pair<double,double> O[2];
		for(int i = 0; i < n && !deu_certo && !sair; i++){
			for(int j = i+1; j < n && !deu_certo && !sair; j++){
				if(dist(p[j], p[i]) > 2*raio){
					sair = 1;
					break;
				}
				int lim = 1;
				if(fabs(dist(p[j],p[i]) - raio) <= EPS){
					O[0].ff = (p[j].ff + p[i].ff)/2;
					O[0].ss = (p[j].ss + p[i].ss)/2;

				}
				else{
					double d2 = (p[i].ff - p[j].ff) * (p[i].ff - p[j].ff) + (p[i].ss - p[j].ss) * (p[i].ss - p[j].ss);
			        double det = raio * raio / d2 - 0.25;

			        double h = sqrt(det);

			        O[0].ff = (p[i].ff + p[j].ff) * 0.5 + (p[i].ss - p[j].ss) * h;
			        O[0].ss = (p[i].ss + p[j].ss) * 0.5 + (p[j].ff - p[i].ff) * h;

			        O[1].ff = (p[i].ff + p[j].ff) * 0.5 - (p[i].ss - p[j].ss) * h;
			        O[1].ss = (p[i].ss + p[j].ss) * 0.5 - (p[j].ff - p[i].ff) * h;

			        lim = 2;
				}
				for(int l = 0; l < lim; l++){
					bool ok = 1;
					for(int k = 0; k < n; k++){
						if(dist(O[l], p[k]) > raio){
							ok = 0;
							break;
						}
					}
					if(ok) deu_certo = 1;
				}
			}
		}

		if(!deu_certo || raio == 0.0) printf("There is no way of packing that polygon.\n");
		else printf("The polygon can be packed in the circle.\n");
	}

	return 0;
}