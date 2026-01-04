// Problem: P2800 又上锁妖塔
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2800
// Create Time: 2025-07-03 12:20:57

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

int n;
int a[1000005],f[1000005];

signed main() {
	r(n);
	for (int i=1;i<=n;i++) {
		r(a[i]);
		if (i<3) continue;
		f[i]=min(f[i-1]+a[i],min(f[i-2]+a[i-1],f[i-3]+a[i-2]));
	}
	printf("%d\n",f[n]);
	return 0;
}