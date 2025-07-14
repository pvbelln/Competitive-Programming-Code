// Problem: P1719 最大加权矩形
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1719
// Create Time: 2025-04-23 22:56:16

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

int n,a,ans=-1e9,now;
int sum[125][125];

signed main() {
	r(n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) {
			r(a);
			sum[i][j]=sum[i][j-1]+a;
		}
	for (int L=1;L<=n;L++)
		for (int R=L;R<=n;R++) {
			now=0;
			for (int i=1;i<=n;i++) {
				now+=sum[i][R]-sum[i][L-1];
				now=max(now,0);
				ans=max(ans,now);
			}
			//cout<<ans<<"\n";
		}
	printf("%d\n",ans);
	return 0;
}