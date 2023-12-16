#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 가능하다면 쉬운 문제부터 풀어야 한다
// 먼저 푸는 것이 좋은 문제가 있는 문제는 먼저 푸는 것이 좋은 문제를 먼저 풀어야 한다

vector<int> adj[32001];
int deg[32001];
int main() {
	int n, m; cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		deg[b]++;
	}

	// q 에 indegree가 0인 값을 넣는다
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		if(deg[i] == 0){pq.push(i);}
	}

	// 작은것을 출력하는 방법
	// q에서 pop을 하고 작은 것 부터 다시 pop 한다
	// 그러려면 priority queue를 사용해야 한다
	while (!pq.empty()) {
		int cur = pq.top(); pq.pop();
		cout << cur << ' ';
		for(int nx : adj[cur])
		{
			deg[nx]--;
			if(deg[nx] == 0)pq.push(nx);
		}
	}
}