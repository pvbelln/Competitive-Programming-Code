<<<<<<< HEAD
// Problem: UVA10409 Die Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10409
// Create Time: 2025-07-14 11:30:19

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

int k;
int U,N,W,u,n,w;
char op[10];

signed main() {
	while (1) {
		r(k);
		if (!k) break;
		U=1; N=2; W=3;
		while (k--) {
			scanf("%s",op);
			if (op[0]=='n') {
				u=7-N;
				n=U;
				U=u;
				N=n;
			}
			else if (op[0]=='e') {
				u=W;
				w=7-U;
				U=u;
				W=w;
			}
			else if (op[0]=='s') {
				u=N;
				n=7-U;
				U=u;
				N=n;
			}
			else  {
				u=7-W;
				w=U;
				U=u;
				W=w;
			}
		}
		printf("%d\n",U);
	}
	return 0;
=======
// Problem: UVA10409 Die Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10409
// Create Time: 2025-07-14 11:30:19

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

int k;
int U,N,W,u,n,w;
char op[10];

signed main() {
	while (1) {
		r(k);
		if (!k) break;
		U=1; N=2; W=3;
		while (k--) {
			scanf("%s",op);
			if (op[0]=='n') {
				u=7-N;
				n=U;
				U=u;
				N=n;
			}
			else if (op[0]=='e') {
				u=W;
				w=7-U;
				U=u;
				W=w;
			}
			else if (op[0]=='s') {
				u=N;
				n=7-U;
				U=u;
				N=n;
			}
			else  {
				u=7-W;
				w=U;
				U=u;
				W=w;
			}
		}
		printf("%d\n",U);
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}