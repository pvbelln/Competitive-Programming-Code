<<<<<<< HEAD
// Problem: UVA11494 Queen
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11494
// Create Time: 2025-07-12 12:54:44

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

int a,b,c,d;

signed main() {
	while (1) {
		r(a); r(b); r(c); r(d);
		if (!a) break;
		if (a==c && b==d) puts("0");
		else if (a==c || b==d || a+b==c+d || a-b==c-d) puts("1");
		else puts("2");
	}
	return 0;
=======
// Problem: UVA11494 Queen
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11494
// Create Time: 2025-07-12 12:54:44

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

int a,b,c,d;

signed main() {
	while (1) {
		r(a); r(b); r(c); r(d);
		if (!a) break;
		if (a==c && b==d) puts("0");
		else if (a==c || b==d || a+b==c+d || a-b==c-d) puts("1");
		else puts("2");
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}