#include <bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define BRONZE 0
#define SILVER 1
#define GOLD 2
#define PLATINUM 3
#define DIAMOND 4
using namespace std;
int rnk[5];

int get_rank(char c) {
    if (c == 'B')
        return BRONZE;
    else if (c == 'S')
        return SILVER;
    else if (c == 'G')
        return GOLD;
    else if (c == 'P')
        return PLATINUM;
    else
        return DIAMOND;
}
int d[36][50001];
int n;
string s;
int go(int prev, int idx, int val) {
    if (idx == 0) {
        int target = get_rank(s[idx]);
        if (target == DIAMOND) {
            d[0][rnk[target]] = rnk[target];
            go(rnk[target], idx + 1, d[0][rnk[target]]);
        } else {
            d[0][rnk[target + 1] - 1] = rnk[target + 1] - 1;
            go(rnk[target + 1] - 1, idx + 1, d[idx][rnk[target + 1] - 1]);
        }
    } else {
        if (d[idx][prev] != -1)
            if (d[idx][prev] > val)
                return d[idx][prev];
        int target = get_rank(s[idx]);
        if(idx != n-1){
            int next_rank= get_rank(s[idx]);
            
            
        }else{

        }

    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= 4; i++) {
        cin >> rnk[i];
    }
    cin >> s;
}