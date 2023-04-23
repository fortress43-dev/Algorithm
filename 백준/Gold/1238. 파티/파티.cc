#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 1e9
#define pii pair<int,int>
using namespace std;

vector<pii> graph[MAX];
int dst[MAX], ans[MAX];
int n, m, x, s, e, t;

void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq; //거리, 노드
	pq.push(make_pair(0, start));
	dst[start] = 0;
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++){
			int nxt = graph[now][i].first;
			int nCost = graph[now][i].second;

			if (cost + nCost < dst[nxt]) {
				dst[nxt] = cost + nCost;
				pq.push(make_pair(cost + nCost, nxt));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;

	for (int i = 0; i <= n; i++)
	{
		dst[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> t; 
		graph[s].push_back(make_pair(e, t));
	}

	//i to x
	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dst[j] = INF;
		}
		dijkstra(i);
		ans[i] = dst[x];
	}

	for (int i = 1; i <= n; i++) dst[i] = INF;

	dijkstra(x);

	for (int i = 1; i <= n; i++){
		ans[i] += dst[i];
	}

	cout << *max_element(ans + 1, ans + n + 1);

	return 0;
}