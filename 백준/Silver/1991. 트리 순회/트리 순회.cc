#include <iostream>
#include <vector>
#include <map>
using namespace std;

int lc[100];
int rc[100];

void ForwardSearch(int curPos) {
	cout << (char)('A' + curPos);
	if(lc[curPos]) ForwardSearch(lc[curPos]);
	if(rc[curPos]) ForwardSearch(rc[curPos]);
}

void MidSearch(int curPos) {
	if (lc[curPos]) MidSearch(lc[curPos]);
	cout << (char)('A' + curPos);
	if (rc[curPos]) MidSearch(rc[curPos]);
}

void BackwardSearch(int curPos) {
	if (lc[curPos]) BackwardSearch(lc[curPos]);
	if (rc[curPos]) BackwardSearch(rc[curPos]);
	cout << (char)('A' + curPos);
}

int main() {
	
	int n; cin >> n;

	while (n--) { // 트리만들기
		char p, c1, c2; cin >> p >> c1 >> c2;
		int ptoi  = p - 'A';
		int ctoi1 = c1 - 'A';
		int ctoi2 = c2 - 'A';
		if(c1 != '.') lc[ptoi] = ctoi1;
		if(c2 != '.') rc[ptoi] = ctoi2;
	}


	// 전위순회
	ForwardSearch(0); cout << "\n";
	MidSearch(0); cout << "\n";
	BackwardSearch(0); cout << "\n";
	// 중위순회
	
	// 후위순회
	

}