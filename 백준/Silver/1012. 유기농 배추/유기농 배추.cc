
#include <iostream>
#include <cstring>
#include <stack>
#define pii pair<int,int>
#define X first
#define Y second

using namespace std;

int map[2500][2500];
int dx[] {1,-1,0,0};
int dy[] {0,0,-1,1};

//pii searchPoint {0,0};

int areaCnt;
bool endDfs = false;

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		// 가로, 세로, 배추의 갯수
		int m, n, k;
		cin >> m >> n >> k;

		stack<pii> stk; 
		// 시작점을 넣어준다

		// 맵 정보갱신
		for (int i = 0; i < k; i++){
			int x, y; cin >> x >> y;
			map[y][x] = 1;
			if(i == 0) stk.push(make_pair(x,y));
		}


		// 하나의 케이스가 끝나는 조건
		// 검색하고 있는 포인트가 끝에 도달했는가
		while (!endDfs) {

			// 스택이 빌 때까지 반복
			while (!stk.empty())
			{
				// 새로운 노드를 스택에서 뽑는다
				// visited 체크를 해준다
				pii curPos = stk.top();
				stk.pop();
				map[curPos.Y][curPos.X] = -1;

				// 4방향을 탐색한다
				for (int i = 0; i < 4; i++) {
					int nx = curPos.X + dx[i];
					int ny = curPos.Y + dy[i];
					
					// 예외처리
					// visited = continue
					// map out = continue
					if (map[ny][nx] == -1) continue;
					if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

					// 1을 발견하면 stack 에 넣어준다
					if (map[ny][nx] == 1){ stk.push(make_pair(nx, ny)); } 
				}
			}
			// 하나의 영역 끝남
			// 영역 카운트 증가

			areaCnt++;

			// 다음 영역찾기
			// 다음탐색포인트를 찾았으면 빠져나간다 
			
			bool foundPoint = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if(map[i][j] == 1){
						stk.push(make_pair(j,i));
						foundPoint = true;
						break;
					}
					if (i == n - 1 && j == m - 1) {endDfs = true;}
				}
				if(foundPoint)break;
			}
			// 하나의 영역 끝
		}
		// 하나의 테스트 케이스 끝남
		// 결과를 출력하고 결과를 초기화
		cout << areaCnt <<'\n';
		areaCnt = 0;
		endDfs = false;

		// 맵 초기화
		memset(map, 0, sizeof(map));
		
	}
	
	return 0;

}
