#include <iostream>
using namespace std;

int n;
int one, minusOne, zero;
int map[2200][2200];

void Paper(int x, int y, int size) {
	bool same = true;

	for (int i = y; i < y+size; i++){ // 각분면 탐색
		for (int j = x; j < x+size; j++){ 
			if(map[i][j] != map[y][x]){same = false; break;} // 원소 하나라도 다르면 false
		}
		if(!same){break;} // 이미 false 면 그 뒤는 계산 필요 X
	}

	if (!same) {
		int nxSize = size/3;
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				Paper(x + i*nxSize, y + j*nxSize, nxSize); // 각 부분을 재귀
			}
		}
	}
	else { // 모두 같은 경우
		if(map[y][x] == 1) one++;
		else if(map[y][x] == -1) minusOne++;
		else zero++;
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin>> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin>>map[i][j];
		}
	}
	Paper(0,0,n);
	cout << minusOne  <<'\n';
	cout << zero	  <<'\n';
	cout << one		  <<'\n';

	return 0;
}