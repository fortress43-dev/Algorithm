#include <iostream>
#include <vector>

using namespace std;

//vector < vector <int> > map(N + 1, vector <int>(N + 1, 0));
// 이중백터를 쓸 경우에는 임시 백터를 넣어줘야 두번째 백터에 접근 가능

bool visited[101];

bool DiretedGraph(int curPos, int& destiny, vector<vector<int>>& road)
{
	
	if (curPos == destiny) // 목적지라면 true
	{
		return true; 
		visited[curPos] = false;
	} 

	if (visited[curPos]) return false; // 방문한 곳이라면
	visited[curPos] = true;			   // 현재 노드 방문처리

	
	for (int nxtPos : road[curPos]) {		// 현재 도로에 연결된 도로 
		if(!DiretedGraph(nxtPos, destiny, road)){return false;}
	}

	visited[curPos] = false;
	return true; // 이 문제에서는 무조건 목적지에 도착하므로 
}

 
int main() {
	int n; cin >> n;

	vector<vector<int>> road;
	for (int i = 0; i < n+1; i++){
		vector<int> tmpVec;
		road.push_back(tmpVec);
	}

	// 노드 정보 갱신
	for (int i = 1; i < n; i++){ // 맵정보 업데이트
		int nxtRoadCnt;				// 도착지점 n 은 연결점이 없어서 안 넣어줌
		cin >> nxtRoadCnt;
		for (int j = 0; j < nxtRoadCnt; j++){
			int nxtRoad; cin >> nxtRoad;
			road[i].push_back(nxtRoad);
		}
	}
	//cout << "roadMax : " << road[n][0];

	if(DiretedGraph(1, n, road)) cout << "NO CYCLE";
	else cout << "CYCLE";

	return 0;
}