#include <iostream>
#include <queue>
using namespace std;

struct cmp{
public:
	bool operator()(int a, int b) 
	{
		if(abs(a) != abs(b)) return abs(a) > abs(b);
		return b < 0 && 0 < a;
	}
};

priority_queue<int, vector<int>, cmp> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;

	while (n--) {
		int x; cin >> x;
		if (x != 0) {
			q.push(x);
		}
		else {
			if(q.empty()){ cout << "0\n";}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
	}

	return 0;
}
