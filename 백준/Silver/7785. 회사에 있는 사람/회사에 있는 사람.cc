#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<string, string, greater<string>> record;

int main() {
	int n; cin>>n;
	for (int i = 0; i < n; i++)
	{
		string workerName; cin >> workerName;
		string inOut; cin >> inOut;
		record[workerName] = inOut;
	}
	
	for (auto a : record)
	{
		if(a.second =="enter") cout << a.first << "\n";
	}
}

// map 선언할 줄 모름