#include <iostream>
#include <string>

#define endl "\n"
#define MAX 70

using namespace std;

int n; 
int map[MAX][MAX];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++){
			map[i][j] = s[j] - '0';
		}
	}
}

void Recursion(int x, int y, int size) {
	if(size == 1) {cout << map[x][y]; return; }

	bool onlyZero, onlyOne;
	onlyZero = onlyOne = true;

	for (int i = x; i < x + size; i++){
		for (int j = y; j < y + size; j++){
			if(map[i][j] == 0) onlyOne = false;
			if(map[i][j] == 1) onlyZero = false;
		}
	}

	if(onlyOne)  { cout << 1; return; }
	if(onlyZero) { cout << 0; return; }

	cout << "(";

	int nxSize = size/2;
	Recursion(x			, y			, nxSize);
	Recursion(x			, y + nxSize, nxSize);
	Recursion(x + nxSize, y			, nxSize);
	Recursion(x + nxSize, y + nxSize, nxSize);

	cout << ")";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Input();
	Recursion(0,0,n);

	return 0;
}