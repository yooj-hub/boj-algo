#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
typedef complex<double> cpx;
const double PI = acos(-1);

void FFT(vector<cpx> &f, cpx w) {
    int n = f.size();
    if (n == 1)
        return;
    vector<cpx> even(n / 2), odd(n / 2);
    for (int i = 0; i < n; ++i) {
        (i % 2 ? odd : even)[i / 2] = f[i];
    }
    FFT(even, w * w);
    FFT(odd, w * w);

    cpx wp(1, 0);

    for (int i = 0; i < n / 2; i++) {
        f[i] = even[i] + wp * odd[i];
        f[i + n / 2] = even[i] - wp * odd[i];
        wp *= w;
    }
}

vector<int> multiply(vector<cpx> a, vector<cpx> b) {
    int n = 1;
    while (n < a.size() + 1 || n < b.size() + 1)
        n *= 2;
    n *= 2;

    a.resize(n);
    b.resize(n);
    vector<cpx> c(n);
    cpx w(cos(2 * PI / n), sin(2 * PI / n));

    FFT(a, w);
    FFT(b, w);

    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }

    FFT(c, cpx(w.real(), -w.imag()));
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        c[i] /= cpx(n, 0);
        ret[i] = (int) round(c[i].real());
        
        // c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string n1;
    string n2;
    cin >> n1 >> n2;
    vector<cpx> a;
    vector<cpx> b;

    for (int i = n1.size() - 1; i >= 0; i--) {
        cpx tmp = cpx(n1[i] - '0', 0);
        a.push_back(tmp);
    }
    for (int i = n2.size() - 1; i >= 0; i--) {
        cpx tmp = cpx(n2[i] - '0', 0);
        b.push_back(tmp);
    }

    vector<int> ret = multiply(a, b);
    int i=0;
    while(i< ret.size()){
        if(ret[i] >=10){
            if(i==ret.size()-1){
                ret.push_back(ret[i]/10);
            }else{
                ret[i+1] += ret[i]/10;
            }
            ret[i]%=10;
        }
        i++;
    }

    reverse(ret.begin(), ret.end());

    bool start = false;

    for(int x : ret){
        if(x) start = true;
        if(start) cout << x;
    }
    if(!start) cout << '0';

    
}