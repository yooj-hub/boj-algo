#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()

using namespace std;
const int mod = 1000;
struct Matrix {
    int n;
    vector<vector<int>> value;

    Matrix(int size) {
        n = size;
        value = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            value[i][i] = 1;
        }
    }

    Matrix operator*(Matrix &other) {
        Matrix ret = *new Matrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ret.value[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    ret.value[i][j] += ((value[i][k]%mod) * (other.value[k][j]%mod))%mod;
                    ret.value[i][j]%=mod;
                }
            }
        }
        return ret;
    }
};

Matrix solve(Matrix &x, ll b, int &a) {
    if (b == 0)
        return Matrix(a);
    if (b & 1) {
        Matrix tmp = solve(x, b - 1, a);
        return x * tmp;
    }
    Matrix tmp = solve(x, b / 2, a);
    return tmp * tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll b;
    cin >> n >> b;
    Matrix x = Matrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x.value[i][j];
        }
    }
    Matrix ans = solve(x, b, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans.value[i][j] << ' ';
        }
        cout << '\n';
    }
}