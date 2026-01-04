// Problem: UVA10050 Hartals
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10050
// Create Time: 2025-10-09 11:24:20

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

int T, N, P;
bool days[3655];
int period, ans;

signed main() {
	r(T);
	while (T--) {
		memset(days, 0, sizeof days);
		ans = 0;
		r(N);
		r(P);
		while (P--) {
			r(period);
			for (int i = 1; i <= N; i++)
				if (i % period == 0 && i % 7 != 6 && i % 7 != 0)
					days[i] = 1;
		}
		for (int i = 1; i <= N; i++)
			ans += days[i];
		printf("%d\n",ans);
	}
	return 0;
}