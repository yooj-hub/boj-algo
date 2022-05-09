#include <bits/stdc++.h>


using namespace std;

#define ll long long int

const int INF = 1e18;




int N, M;
vector<pair<int, int>> V[200001]; 
int Paper[200001];	
int Dist[200001];	
int Back[200001];	
int nowPaper[200001];	

int32_t main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		std::cin >> u >> v >> w;
		V[u].push_back({ v,w });
		V[v].push_back({ u,w });
	}
	int SumPaper = 0;
	for (int i = 1; i <= N; i++)
	{
		Dist[i] = INF;
		nowPaper[i] = -1;
		std::cin >> Paper[i];
		SumPaper += Paper[i];	
	}

	priority_queue<pair<int, int>> Q;
	Q.push({ 0,1 });
	Dist[1] = 0;
	nowPaper[1] = Paper[1];
	Back[1] = 1;

	while (!Q.empty())
	{
		pair<int, int> now = Q.top();
		Q.pop();
		int nowCost = -now.first;
		int nowPont = now.second;

		if (nowCost > Dist[nowPont])
			continue;

		for (int i = 0; i < V[nowPont].size(); i++)
		{
			pair<int, int> next = V[nowPont][i];
			int nextCost = nowCost + next.second;
			int nextPoint = next.first;

			if (Dist[nextPoint] >= nextCost)
			{
				Dist[nextPoint] = nextCost;
				Q.push({ -nextCost,nextPoint });

				if (nowPaper[nextPoint] <= nowPaper[nowPont] + Paper[nextPoint])
				{
					nowPaper[nextPoint] = nowPaper[nowPont] + Paper[nextPoint];
					Back[nextPoint] = nowPont;	
				}
			}
		}
	}

	if (nowPaper[N] == SumPaper)
	{

		stack<int> ans;
		int a = N;
		ans.push(N);
		while (Back[a] != a)
		{
			a = Back[a];
			ans.push(a);
		}

		std::cout << ans.size() << endl;
		while (!ans.empty())
		{
			std::cout << ans.top() << " ";
			ans.pop();
		}
		std::cout << endl;
	}
	else
	{
		std::cout << -1 << endl;
	}
}