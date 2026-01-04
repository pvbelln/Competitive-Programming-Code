// Problem: UVA12614 Earn For Future
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA12614
// Create Time: 2025-02-23 20:01:07

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
int n,a,ans;

signed main() {
	r(T);
	for (int tt=1;tt<=T;tt++) {
		r(n);
		ans=0;
		while (n--) {
			r(a);
			ans=max(ans,a);
		}
		printf("Case %d: %d\n",tt,ans);
	}
	return 0;
}