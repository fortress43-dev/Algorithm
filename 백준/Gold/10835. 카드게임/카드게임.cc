#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 2000
//틀려서 카피공부한 문제
// dp라고 생각되었는데 나는 2*max카드 수라고 테이블을 생각했음
int N;
int left_card[MAXN + 10];
int right_card[MAXN + 10];
int M[MAXN][MAXN];

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> left_card[i];
	for (int i = 0; i < N; i++)
		cin >> right_card[i];
}
int DP(int left, int right) {
	if (left == N || right == N) return 0;

	if (M[left][right] != -1) return M[left][right];

	M[left][right] = 0;
	// 오른쪽 카드 버리는 경우 -> 오른쪽 카드 만큼 얻음
	if (right_card[right] < left_card[left]) {
		M[left][right] += right_card[right] + DP(left, right + 1);
	}
	else {
		M[left][right] += max(DP(left + 1, right), DP(left + 1, right + 1));// 왼쪽을 버리는 경우와 둘다 버리는 경우 중 큰 값을 가져온다
	}
	return M[left][right];
}
int main() {
	Input();

	memset(M, -1, sizeof(M));
	cout << DP(0, 0);;
	return 0;
}