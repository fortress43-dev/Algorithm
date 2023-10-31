#include <iostream>
#include <set>
using namespace std;

multiset<int, greater<int>> dataSet;

int main() {
	int t; cin >> t;
	while (t--) {
		
		int k; cin >> k;
		while (k--) {
			char oper; cin >> oper;
			int num; cin >> num;
			if (oper == 'I') dataSet.insert(num);
			else{
				if(dataSet.size() == 0) continue;
				if(num == 1) dataSet.erase(dataSet.begin());
				else if(num == -1) dataSet.erase(prev(dataSet.end()));
			}
			
		}
		if(dataSet.size() > 0) cout << *dataSet.begin() << " " << *prev(dataSet.end()) << "\n";
		else cout << "EMPTY" << "\n";

		dataSet.clear();
	}
}