#include "iostream"
#include "algorithm"

using namespace std;

int A[20001];
int B[20001];


int main() {
	int t; cin >> t;
	while (t--) {
		int ans = 0;
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> B[i];
		}

		sort(A, A + n);
		sort(B, B + m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (B[j] < A[i]) {
					ans++;
				}
				else {
					break;
				}
			}
		}

		cout << ans << "\n";
	}

	
	return 0;
}