#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> s2i;
string i2s[100005];

int main() {
	int n,m; cin >> n >> m;
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= n; i++)
	{
		cin >> i2s[i];
		s2i[i2s[i]] = i;
	}

	while(m--)
	{
		string query; cin >> query;
		if (isdigit(query[0])) {
			cout << i2s[stoi(query)] << '\n';
		}
		else {
			// 숫자면
			cout << s2i[query] << "\n";
		}
	}

	return 0;
}

// value 로 찾기
// 문자인지 숫자인지 판별하기 isdigit