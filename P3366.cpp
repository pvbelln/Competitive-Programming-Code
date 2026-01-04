// Problem: P3366 【模板】最小生成树
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3366
// Create Time: 2025-12-16 15:16:51

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
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

int n, m;
int ans;
int fa[5005];
struct node {
	int u, v, w;
	bool operator< (const node& x) const {
		return w < x.w;
	}
}edges[200005];
 
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int kruskal() {
	int cnt = 1;
	for (auto i : edges) {
		int fau = find(i.u);
		int fav = find(i.v);
		if (fau == fav)
			continue;
		ans += i.w;
		fa[fau] = fav;
		cnt ++;
		if (cnt == n)
			break;
	}
	return cnt;
}

signed main() {
	r(n); r(m);
	for (int i = 0; i < m; i++) {
		edges[i] = {read(), read(), read()};
	}
	sort(edges, edges + m);
	iota(fa, fa + n, 0);
	if (kruskal() < n)
		puts("orz");
	else
		printf("%d\n", ans);
	return 0;
}