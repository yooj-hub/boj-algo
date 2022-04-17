#include<iostream>
#include<tuple>
#include<vector>
#define MX 2000000000
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
       	cin.tie(nullptr);
       	cout.tie(nullptr);

	int tc;
	cin >> tc;

	while(tc--){
		int n,m,w;
		cin >> n >> m >> w;
		vector<tuple<int,int,int>> edges;
		vector<int> distance(n+1);
		fill(distance.begin(), distance.end(), MX);
		for(int i=0; i<m;i++){
			int s,e,t;
			cin >> s >> e >> t;
			edges.emplace_back(s,e,t);
			edges.emplace_back(e,s,t);
		}
		for(int i=0; i<w;i++){

			int s,e,t;
			cin >> s >>e >>t;
			edges.emplace_back(s,e,-t);

		}

		int start =1;
		distance[start] = 0;
		bool negativeCycle=false;
		for(int i=1; i<n+1;i++){
			for(int j=0; j<edges.size();j++){
				int current, next, cost;
				tie(current, next, cost) = edges[j];
				if(distance[current] != MX && distance[next] > distance[current]+cost){
					distance[next] = distance[current] + cost;
					if(i== n){
						negativeCycle = true;
						
						
					}
				}

			}
		}
		if(negativeCycle){
			cout<<"YES\n";
		}else cout << "NO\n";

	}

}
