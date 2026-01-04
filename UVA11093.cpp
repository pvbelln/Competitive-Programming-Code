// Problem: UVA11093 环形跑道 Just Finish it up
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11093
// Create Time: 2025-11-29 00:15:17

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

#define MAXN 100000

int T;
int N;
int a[2 * MAXN + 5], b[2 * MAXN + 5];
int A[2 * MAXN + 5], B[2 * MAXN + 5];

signed main() {
	r(T);
	for (int _ = 1; _ <= T; _++) {
		r(N);
		int tota, totb, ans = -1;
		tota = totb = 0;
		for (int i = 1; i <= N; i++) {
			r(a[i]);
			a[i + N] = a[i];
			tota += a[i];
		}
		for (int i = 1; i <= N; i++) {
			r(b[i]);
			b[i + N] = b[i];
			totb += b[i];
		}
		for (int i = 1; i <= N * 2; i++) {
			A[i] = A[i - 1] + a[i];
			B[i] = B[i - 1] + b[i];
		}
		
		if (tota < totb) {
			printf("Case %d: Not possible\n", _);
			continue;
		}
		
//		cerr<<"=======\n";
//		for (int i = 1; i <= N * 2; i++)
//			cerr << A[i] <<" "<< B[i] <<"\n";
//		cerr<<"=======\n";
		
		bool flag;
		for (int i = 1; i <= N; i++) {
			flag = 1;
			for (int j = i; j < i + N; j++) {
//				cerr << i << " " << j << " " << A[j] - A[i - 1] << " " << B[j] - B[i - 1] << "\n";
				if (A[j] - A[i - 1] < B[j] - B[i - 1]) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				ans = i;
				break;
			}
		}
		printf("Case %d: Possible from station %d\n", _, ans);
//		cerr << "\n\n";
	}
	return 0;
}