// Problem: UVA11496 Musical Loop
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11496
// Create Time: 2025-10-16 11:26:37

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

int N;
int H[10005];

signed main() {
	while (1) {
		r(N);
		if (!N) break;
		for (int i = 1; i <= N; i++)
			r(H[i]);
		H[N + 1] = H[1];
		H[0] = H[N];
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if ((H[i] - H[i - 1]) * (H[i] - H[i + 1]) > 0)
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}