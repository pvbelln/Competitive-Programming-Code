// Problem: Ab Initio
// Contest: Kattis
// URL: https://open.kattis.com/problems/abinitio?tab=metadata
// Create Time: 2025-12-24 16:51:59

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
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

int V, E, Q;
int x, y, op;
bool T, C;  // C = 1 表示 g 中记录的是补图
const int MOD = 1000000007;
bool g[4005][4005];

signed main() {
	r(V); r(E); r(Q);
	while (E--) {
		r(x); r(y);
		g[x][y] = 1;
	}
	while (Q--) {
		r(op);
		if (op == 1) {
			for (int i = 0; i < V; i++) {
				g[i][V] = C;
				g[V][i] = C;
			}
			V++;
		}
		else if (op == 2 || op == 4) {
			r(x); r(y);
			if (T)
				swap(x, y);
			g[x][y] = 1 - g[x][y];
		}
		else if (op == 3) {
			r(x);
			for (int i = 0; i < V; i++)
				g[i][x] = g[x][i] = C;
		}
		else if (op == 5) {
			T ^= 1;
		}
		else if (op == 6) {
			C ^= 1;
		}
	}
	printf("%d\n", V);
	long long res;
	long long com7, tmp;
	int cnt;
	for (int i = 0; i < V; i++) {
		com7 = 1;
		res = 0;
		cnt = 0;
		for (int j = 0; j < V; j++) {
			if (i == j) continue;
			if ((T && g[j][i] != C) || (!T && g[i][j] != C)) {
				tmp = (com7 * j) % MOD;
				res += tmp;
				res %= MOD;
				com7 *= 7;
				com7 %= MOD;
				cnt++;
			}
		}
		printf("%d %d\n", cnt, (int)res);
	}
	return 0;
}