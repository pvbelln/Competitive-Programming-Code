// Problem: UVA12239 Bingo!
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12239
// Create Time: 2025-07-15 19:56:13

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

int n,b;
int a[95];
bool found[95];
bool okay;

signed main() {
	while (1) {
		r(n); r(b);
		okay=1;
		if (!n) break;
		memset(found,0,sizeof found);
		for (int i=1;i<=b;i++)
			r(a[i]);
		for (int i=1;i<=b;i++)
			for (int j=i;j<=b;j++)
				found[abs(a[i]-a[j])]=1;
		for (int i=0;i<=n;i++)
			if (!found[i]) {
				okay=0;
				break;
			}
		if (okay) puts("Y");
		else puts("N");
	}
	return 0;
}