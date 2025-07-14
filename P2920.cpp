// Problem: P2920 [USACO08NOV] Time Management S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2920
// Create Time: 2025-07-10 13:42:09

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
struct node {
	int dur,bef;
}a[1005];
int L,R,mid,ans;

bool chk(int x) {
	int now=x;
	for (int i=1;i<=n;i++) {
		now+=a[i].dur;
		if (now>a[i].bef) return 0;
	}
	return 1;
}

signed main() {
	r(n);
	for (int i=1;i<=n;i++) {
		r(a[i].dur); r(a[i].bef);
	}
	sort(a+1,a+n+1,[](node a,node b) {
		return a.bef<b.bef;
	});
	R=1000000;
	while (L<=R) {
		mid=(L+R)/2;
		if (chk(mid)) {
			L=mid+1;
			ans=mid;
		}
		else R=mid-1;
	}
	if (!chk(ans)) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}