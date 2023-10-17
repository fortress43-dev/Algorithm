#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 2000000000
using namespace std;

long long arr[100001];
int ans = INF;

int main() {
	int m,n;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	// 투포인터
	int st = 0;
	int en = 1;
	int gap = 0;

	while (en < n) {
		gap = arr[en] - arr[st];
		if(gap < m) en++;
		else 
		{
			st++;
			ans = min(ans, gap);
		}
	}
	cout << ans;
}
// 절대값 구하는 법 모름