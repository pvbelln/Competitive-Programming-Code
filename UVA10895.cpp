// Problem: UVA10895 Matrix Transpose
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10895
// Create Time: 2025-12-23 14:12:26

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

int m, n;
vector<pair<int, int>> g[10005];
vector<int> tmp;

void print() {
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		auto row = g[i];
		if (row.empty()) {
			printf("0\n\n");
			continue;
		}
		printf("%d", (int)row.size());
		for (auto ele : row)
			printf(" %d", ele.first);
		printf("\n");
		bool f = 0;
		for (auto ele : row) {
			if (f)
				printf(" ");
			f = 1;
			printf("%d", ele.second);
		}
		printf("\n");
	}
}

signed main() {
	while (scanf("%d %d", &m, &n) == 2) {
		int maxlen = max(m, n);
		for (int i = 1; i <= maxlen; i++)
			g[i].clear();
		for (int i = 1; i <= m; i++) {
			int elenum, x;
			r(elenum);
			if (!elenum)
				continue;
			tmp.clear();
			for (int j = 0; j < elenum; j++)
				tmp.push_back(read());
			for (int col : tmp) {
				r(x);
				g[col].push_back({i, x});
			}
		}
		print();
	}
	return 0;
}