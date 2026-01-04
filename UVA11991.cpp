// Problem: UVA11991 Easy Problem from Rujia Liu?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11991
// Create Time: 2025-12-18 17:16:55

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

int n, m;
int x, y;
vector<int> pos[1000005];

signed main() {
	while (scanf("%d%d", &n, &m) == 2) {
		for (auto i : pos)
			i.clear();
		for (int i = 1; i <= n; i++)
			pos[read()].push_back(i);
		while (m--) {
			r(x); r(y);
			if (x > pos[y].size()) {
				puts("0");
				continue;
			}
			printf("%d\n", pos[y][x - 1]);
		}
	}
	return 0;
}