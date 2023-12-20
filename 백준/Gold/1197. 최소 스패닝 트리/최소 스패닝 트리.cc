#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

 vector<int> p(10005,-1);

 int find(int x) {
	// if this seach id first time
	 if (p[x] < 0) return x;
	 return p[x] = find(p[x]);
 }

 // return whether both is in same group
 bool is_diff_group(int u, int v) {
	 u = find(u); v = find(v);
	 if(u==v) return 0;
	 //if(p[u] == p[v]) p[u]--;
	 if(p[u] < p[v]) p[v] = u;
	 else p[u] = v;
	 return 1;
 }

 int v, e;
 tuple<int,int, int> edge[100005];

int main() {
	 ios:: sync_with_stdio(0);
	 cin.tie(0);

	int v, e; cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		// get info from Input
		// save it in tuple with cost var ahead
		int a, b, cost;
		cin >> a >> b>> cost;
		edge[i] = {cost, a, b};
	}

	// sort with edge's cost
	sort(edge, edge + e);
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		tie(cost, a, b) = edge[i];
		// if a, b is in same group
		if(!is_diff_group(a,b)) continue;
		ans += cost;
		cnt ++;
		// if edge cnt equal with v-1 
		// it is min length tree
		if(cnt == v-1) break;
	}
	cout << ans;
}               