#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int d[100001];
	for(int i=1; i*i <n;i++){
		d[i*i] +=1;
		for(int j=1; j*j < i*i; j++){
			d[j * j + i * i]+=1;
		}
	}
	cout << d[n];
}
