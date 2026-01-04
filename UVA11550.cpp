// Problem: UVA11550 Demanding Dilemma
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11550
// Create Time: 2025-12-24 00:03:28

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

int T;
int n, m;
bool mat[9][30];
bool connected[9][9];

bool judge() {
	for (int j = 1; j <= m; j++) {
		int tot = 0;
		pair<int, int> conn = {0, 0};
		for (int i = 1; i <= n; i++) {
			if (mat[i][j]) {
				tot++;
				if (!conn.first)
					conn.first = i;
				else
					conn.second = i;
			}
		}
		if (tot != 2)
			return false;
		if (connected[conn.first][conn.second])
			return false;
		connected[conn.first][conn.second] = 1;
	}
	return true;
}

signed main() {
	r(T);
	while (T--) {
		r(n); r(m);
		memset(connected, 0, sizeof connected);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				r(mat[i][j]);
		if (judge())
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}