// Problem: UVA340 猜数字游戏的提示 Master-Mind Hints
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA340
// Create Time: 2025-07-12 13:47:49

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

int n,Game;
int a[1005],cnta[10],cntb[10],b;
int ans1,ans2;

signed main() {
	while (scanf("%d",&n)==1 && n) {
		memset(cnta,0,sizeof cnta);
		printf("Game %d:\n",++Game);
		for (int i=1;i<=n;i++) {
			r(a[i]);
			cnta[a[i]]++;
		}
		while (1) {
			ans1=ans2=0;
			memset(cntb,0,sizeof cntb);
			for (int i=1;i<=n;i++) {
				r(b);
				cntb[b]++;
				if (b==a[i]) ans1++;
			}
			if (!b) break;
			for (int i=1;i<=9;i++)
				ans2+=min(cnta[i],cntb[i]);
			printf("    (%d,%d)\n",ans1,ans2-ans1);
		}
	}
	return 0;
}