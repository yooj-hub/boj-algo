#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;
int n;
double p[20][20];
double d[1<<20];
bool visited[1<<20];

double go(int idx, int state){
    if(idx == n ) return 1.0;
    if(visited[state]) return d[state];
    visited[state] = true;
    double &ret = d[state];

    for(int i=0; i<n; i++){
        if((state &(1<<i)) == 0){
            double tmp = p[idx][i] * go(idx+1, state | (1<<i));
            if(tmp > ret){
                ret = tmp;
            }
        }
    }
    return ret;
}


int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%lf", &p[i][j]);
            p[i][j]*=0.01;
        }
    }

    printf("%.10lf", go(0,0)*100);

    
}