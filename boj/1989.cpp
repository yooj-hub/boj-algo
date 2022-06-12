#include<bits/stdc++.h>
#define ll long long int
#define all(x) x.begin(), x.end()
#define MX 101010

using namespace std;

int tree[1<<18];
ll s[1<<17];
int arr[1<<17];
int n;


int get_min_idx(int a, int b){
    if(a == -1) return b;
    if(b==-1) return a;
    if(arr[a] == arr[b]) return min(a,b);
    if(arr[a] > arr[b]) return b;
    return a;
}

int init(int node, int start, int end){
    if(start == end) return tree[node] =start;
    int mid = (start+end)>>1;
    return tree[node] = get_min_idx(init(node*2, start, mid), init(node*2+1, mid+1, end));
}

int query(int node, int start, int end, int left, int right){
    if(start > right || left > end) return -1;
    if(left<= start && end <= right) return tree[node];
    
    return get_min_idx(query(node*2, start, (start+end)/2, left, right), query(node*2+1, (start+end)/2+1, end, left, right));
}

pair<ll, pair<int,int>> solve(int left, int right){
    if(left == right) return {(ll)arr[left] * arr[left], {left, left}};
    int mn_idx = query(1,1,n,left,right);
    pair<ll, pair<int,int>> answer = {(ll)arr[mn_idx]*(s[right]- s[left-1]), {left, right}};
    if(mn_idx-1>=left){
        pair<ll, pair<int,int>> left_result = solve(left, mn_idx-1);
        if(answer.first < left_result.first) swap(answer, left_result);
    }
    if(mn_idx+1<=right){
        pair<ll, pair<int,int>> right_result = solve(mn_idx+1, right);
        if(answer.first < right_result.first)swap(answer, right_result);
    }
    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        s[i] = s[i-1] + arr[i];
    }
    init(1,1,n);
    auto answer = solve(1,n);
    cout << answer.first<<'\n';
    cout << answer.second.first <<' ' << answer.second.second;
    
   
}