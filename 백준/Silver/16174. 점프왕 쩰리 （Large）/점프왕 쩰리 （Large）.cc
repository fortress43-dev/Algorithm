#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int n, vector<vector<int>>& map) {
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(n);
	for (auto& now : visited) {
		for (int i = 0; i < n; i++){
			now.push_back(false);
		}
	}

	q.push(make_pair(0, 0));
	while (!q.empty()) {
		auto curpos = q.front(); q.pop();
		int x = curpos.first, y = curpos.second;
		
		// 목적지에 도착하면
		if (map[x][y] == -1) { cout << "HaruHaru"; return; }
		// 영역을 넘어가지 않으면 가능한 두가지 경우의 수를 q에 넣음
		if (x + map[x][y] < n && !visited[x+map[x][y]][y]) {
			q.push(make_pair(x + map[x][y], y));
			visited[x + map[x][y]][y] = true;
		}
		if (y + map[x][y] < n && !visited[x][y + map[x][y]]) {
			q.push(make_pair(x, y + map[x][y]));
			visited[x][y + map[x][y]] = true;
		}
	}
	cout << "Hing";
}

int main() {
	// 맵정보 초기화
	int n; cin >> n;
	vector<vector<int>> map(n);
	for (auto& now : map) {
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			now.push_back(tmp);
		}
	}
	// BFS시작
	BFS(n, map);


}