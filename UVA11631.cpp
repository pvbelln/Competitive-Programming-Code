// Problem: UVA11631 Dark roads
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11631
// Create Time: 2025-12-18 16:37:22

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

int m, n;
int tot;
int fa[200005];
struct node {
	int u, v, w;
	bool operator<(const node &a) const {
		return w < a.w;
	}
}edges[400005];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int kruskal() {
	int cnt = 1, tot = 0;
	for (auto i : edges) {
		int fau = find(i.u);
		int fav = find(i.v);
		if (fau == fav)
			continue;
		tot += i.w;
		fa[fau] = fav;
		cnt++;
		if (cnt == m)
			break;
	}
	return tot;
}

signed main() {
	while (1) {
		r(m); r(n);
		if (!m)
			break;
		int x, y, z;
		tot = 0;
		for (int i = 0; i < n * 2; i++) {
			r(x); r(y); r(z);
			edges[i] = {x, y, z};
			edges[++i] = {y, x, z};
			tot += z;
		}
		sort(edges, edges + n * 2);
		iota(fa, fa + m, 0);
		printf("%d\n", tot - kruskal());
	}
	return 0;
}