// Problem: UVA13026 Search the Khoj
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA13026
// Create Time: 2025-10-30 11:15:23

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

int T, n;
char s[1005][15];
char ans[15];

signed main() {
	r(T);
	for (int kk = 1; kk <= T; kk++) {
		printf("Case %d:\n", kk);
		r(n);
		for (int i = 1; i <= n; i++)
			scanf("%s", s[i]);
		scanf("%s", ans);
		int len = strlen(ans);
		for (int i = 1; i <= n; i++) {
			if (strlen(s[i]) != len)
				continue;
			int now = 0;
			for (int j = 0; j < len; j++) {
				if (s[i][j] != ans[j])
					now++;
			}
			if (now <= 1)
				printf("%s\n",s[i]);
		}
	}
	return 0;
}