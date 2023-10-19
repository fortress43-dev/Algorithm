#include <iostream>
#include <algorithm>
#define INF 100000001
using namespace std;

int arr[100001];

int main() {
	// n 짜리 수열 / 부분합이 s 이상
	int n, goal;

	cin >> n >> goal;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int st = 0;
	int en = 0;
	int sum = arr[st];
	int ans = INF;

	while (en != n) {
		//cout << "st : " << st << " | en : " << en << " | sum : " << sum << " | ans : " << ans << "\n";
		if(sum < goal) { sum += arr[++en]; }
		else { 
			ans = min(ans, en-st+1);
			sum -= arr[st++]; 
		}	
	}
	if(ans == INF) cout << 0;
	else cout << ans;

	return 0;
}


// int 의 담을 수 있는 거 모름