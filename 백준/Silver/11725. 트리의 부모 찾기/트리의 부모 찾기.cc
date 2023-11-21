#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];
int p[100001];

int main() {
	int n, N;
	cin >> n;
	N = n;

	n--;
	while (n--) {
		int st, en;
		cin >> st >> en;
		adj[st].push_back(en);
		adj[en].push_back(st);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int curPos = q.front();
		q.pop();

		for (int nx : adj[curPos])
		{

			if(p[curPos] == nx) continue;
			p[nx] = curPos;
			q.push(nx);
		}
	}

	

	for (int i = 2; i <= N; i++)
	{
		cout << p[i] <<"\n";
	}
}