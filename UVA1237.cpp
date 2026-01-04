// Problem: UVA1237 Expert Enough?
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA1237
// Create Time: 2025-03-01 23:51:13

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
int n,q,x,cnt;
char ans[25];
bool f;
struct node {
	char name[25];
	int L,R;
}car[10005];

signed main() {
	r(T);
	while (T--) {
		memset(ans,0,sizeof ans);
		if (f) printf("\n");
		f=1;
		r(n);
		for (int i=1;i<=n;i++) {
			scanf("%s",car[i].name);
			r(car[i].L); r(car[i].R);
		}
		random_shuffle(car+1,car+1+n);
		r(q);
		while (q--) {
			r(x);
			cnt=0;
			for (int i=1;i<=n;i++)
				if (car[i].L<=x && car[i].R>=x) {
					cnt++;
					if (cnt>=2) break;
					strcpy(ans,car[i].name);
				}
			if (cnt==1) printf("%s\n",ans);
			else printf("UNDETERMINED\n");
		}
	}
	return 0;
}