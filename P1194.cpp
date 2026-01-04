// Problem: P1194 买礼物
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1194
// Create Time: 2025-12-18 10:59:48

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

int A, B;
int x, edgeNum;
int fa[505];
struct node {
	int u, v, w;
	bool operator<(const node &a) const {
		return w < a.w;
	}
}edges[250005];

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
		fa[fau] =fav;
		if (cnt == B + 1)
			break;
	}
	return ans;
}

signed main() {
	r(A); r(B);
	for (int i = 1; i <= B; i++)
		for (int j = 1; j <= B; j++) {
			r(x);
			if (x) {
				edges[++edgeNum] = {i, j, x};
//				edges[++edgeNum] = {j, i, x};   注意
			}
		}
	for (int i = 1; i <= B; i++)
		edges[++edgeNum] = {0, i, A};
	sort(edges + 1, edges + edgeNum + 1);
	iota(fa, fa + B + 1, 0);
	printf("%d\n", kruskal());
	return 0;
}