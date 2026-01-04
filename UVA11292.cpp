// Problem: UVA11292 Dragon of Loowater
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11292
// Create Time: 2025-06-03 23:12:33

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

int n,m,tot,p;
int dragon[20005],sol[20005];

signed main() {
	while (scanf("%d%d",&n,&m)==2 && (n||m)) {
		for (int i=1;i<=n;i++) r(dragon[i]);
		for (int i=1;i<=m;i++) r(sol[i]);
		sort(dragon+1,dragon+1+n);
		sort(sol+1,sol+1+m);
		dragon[n+1]=1e9;
		tot=0; p=1;
		for (int i=1;i<=m;i++) {
			if (sol[i]>=dragon[p]) {
				tot+=sol[i];
				p++;
			}
		}
//		cerr<<p<<"\n";
		if (p<=n) puts("Loowater is doomed!");
		else printf("%d\n",tot);
	}
	return 0;
}