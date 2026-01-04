// Problem: UVA11875 Brick Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11875
// Create Time: 2025-10-16 16:48:14

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
int N, x;

signed main() {
	r(T);
	for (int _ = 1; _ <= T; _++) {
		r(N);
		for (int i = 1; i <= N; i++) {
			r(x);
			if (i == (N + 1) / 2)
				printf("Case %d: %d\n", _, x);
		}
	}
	return 0;
}