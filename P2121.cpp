// Problem: P2121 拆地毯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2121
// Create Time: 2025-12-18 11:15:47

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

int n, m, K;
int edgeNum;
int x, y, z;
int fa[100005];
struct node {
	int u, v, w;
	bool operator<(const node &a) const {
		return w > a.w;
	}
}edges[200005];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int kruskal() {
	int cnt = 1, ans = 0;
	for (auto i : edges) {
		int fau = find(i.u);
		int fav = find(i.v);
		if (fau == fav)
			continue;
		cnt++;
		ans += i.w;
		fa[fau] = fav;
		if (cnt == K + 1)
			break;
	}
	return ans;
}

signed main() {
	r(n); r(m); r(K);
	for (int i = 0; i < m; i++) {
		r(x); r(y); r(z);
		edges[edgeNum++] = {x, y, z};
		edges[edgeNum++] = {y, x, z};
	}
	sort(edges, edges + edgeNum);
	iota(fa, fa + n, 0);
	printf("%d\n", kruskal());
	return 0;
}