// Problem: Railroad Map
// Contest: Kattis
// URL: https://open.kattis.com/problems/railroad
// Create Time: 2025-12-25 15:56:44

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
//#include<unordered_map>
//#define map unordered_map
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
using namespace std;
/*================*/

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

int T;
int n, m;
int a, b, c;
vector<pair<int, int>> g[10005];
vector<pair<int, pair<int, int>>> remain;
int deg[10005];
set<pair<pair<int, int>, int>> vis;

signed main() {
	r(T);
	while (T--) {
		//cerr << "\n";
		r(n); r(m);
		memset(deg, 0, sizeof deg);
		vis.clear();
		remain.clear();
		for (int i = 1; i <= n; i++)
			g[i].clear();
		while (m--) {
			r(a); r(b); r(c);
			g[a].push_back({b, c});
			g[b].push_back({a, c});
			deg[a]++;
			deg[b]++;
		}
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 2) {
				int u = g[i][0].first, v = g[i][1].first;
				int len = g[i][0].second + g[i][1].second;
				//cerr << "=====\n" << i << " " << u << " " << v << " " << len << "\n++++++\n";
				if (u == v) {
					g[u].push_back({u, len});
					continue;
				}
				g[u].push_back({v, len});
				g[v].push_back({u, len});
				for (int j = 0; j < g[u].size(); j++)
					if (g[u][j].first == i) {
						g[u].erase(g[u].begin() + j);
						break;
					}
				for (int j = 0; j < g[v].size(); j++)
					if (g[v][j].first == i) {
						g[v].erase(g[v].begin() + j);
						break;
					}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 2)
				continue;
			for (auto edge : g[i]) {
				if (deg[edge.first] == 2 || vis.count({{i, edge.first}, edge.second}))
					continue;
				remain.push_back({i, edge});
				vis.insert({{i, edge.first}, edge.second});
				vis.insert({{edge.first, i}, edge.second});
			}
		}
		printf("%d\n", (int)remain.size());
		for (auto edge : remain)
			printf("%d %d %d  \n", edge.first, edge.second.first, edge.second.second);
		printf("\n");
	}
	return 0;
}