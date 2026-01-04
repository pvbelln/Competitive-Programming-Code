// Problem: Union-Find
// Contest: Kattis
// URL: https://open.kattis.com/problems/unionfind
// Create Time: 2025-12-18 17:03:39

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

int N, Q;
char op[2];
int x, y, fax, fay;
int fa[1000005];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

signed main() {
	r(N); r(Q);
	iota(fa + 1, fa + N + 1, 1);
	while (Q--) {
		scanf("%s", op);
		r(x); r(y);
		fax = find(x);
		fay = find(y);
		if (op[0] == '=')
			fa[fax] = fay;
		else {
			if (fax == fay)
				puts("yes");
			else
				puts("no");
		}
	}
	return 0;
}