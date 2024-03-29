#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> order; //순서를 저장할 map

int cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return order[a.second] < order[b.second]; //원래 순서 유지
	return a.first > b.first; //빈도 수 기준 내림차순
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;
	map<int, int> m;
	map<int, int>::iterator it;
	vector<pair<int, int>> v;
	vector<int> answer;

	for (int i = 0; i < n; i++)
	{
		int num; cin >> num;
		m[num]++;
		if (order[num] == 0)order[num] = i + 1;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		v.push_back({ it->second, it->first });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].first; j++)
		{
			answer.push_back(v[i].second);
		}
	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
}