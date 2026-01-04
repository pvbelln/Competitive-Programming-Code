// Problem: Flying Safely
// Contest: Kattis
// URL: https://open.kattis.com/problems/flyingsafely
// Create Time: 2025-12-25 11:25:45

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<numeric>
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
int n, m, u, v;

signed main() {
	r(T);
	while (T--) {
		r(n); r(m);
		while (m--) {
			r(u); r(v);
		}
		printf("%d\n", n - 1);
	}
	return 0;
}

// MST: 连通图生成树的边数为 n - 1