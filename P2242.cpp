// Problem: P2242 公路维修问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2242
// Create Time: 2025-06-20 20:00:21

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
#define int long long
using namespace std;
/*================*/

inline int read() {
	char c=getchar();int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}

#define r(a) (a)=read()

int n,m,x,pre,tot;
int a[15005];

signed main() {
	r(n); r(m);
	r(pre); n--;
	for (int i=1;i<=n;i++) {
		r(x);
		a[i]=x-pre;
		pre=x;
//		cerr<<a[i]<<"\n";
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n-m+1;i++)
		tot+=a[i];
	tot+=m;
	printf("%lld\n",tot);
	return 0;
}