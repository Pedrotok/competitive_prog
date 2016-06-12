#include <bits/stdc++.h>

bool dist(double x, double y, double a, double b, double dis) {
    return sqrt((x - a) * (x - a) + (y - b) * (y - b)) < dis;
}

int main(){
    int n, m;
    double a;
    
    scanf("%d %lf",&n, &a);
    
    while (n!= 0 && a != 0) {
        m = 0;
        for (int i = 0; i < n; i++) {
            double x, y;
            scanf("%lf %lf", &x, &y);
            
            if (dist(x, y, 0, 0, a) && dist(x, y, a, 0, a) && dist(x, y, 0, a, a) &&dist(x, y, a, a, a)) {
                m++;
            }
        }
        
        printf("%.5lf\n", m * a * a / n);
        
        scanf("%d %lf",&n, &a);
    }
    
 
    return 0;
}