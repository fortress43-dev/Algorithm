#include "iostream"
using namespace std;
int m,n;
int visited[10];
int arr[10];

void f(int depth) {
	// 종료조건
	if (depth == m) {
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0) {
			visited[i] = 1;
			arr[depth] = i;
			f(depth + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n;
	cin >> m;

	f(0);
	return 0;
}