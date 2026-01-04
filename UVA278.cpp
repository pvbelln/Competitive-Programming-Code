<<<<<<< HEAD
// Problem: UVA278 Chess
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA278
// Create Time: 2025-06-29 13:54:04

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

int n,x,y;
char s[3];

signed main() {
	r(n);
	while (n--) {
		scanf("%s",s);
		r(x); r(y);
		switch (s[0]) {
			case 'r':
				printf("%d\n",min(x,y));
				break;
			case 'Q':
				printf("%d\n",min(x,y));
				break;
			case 'k':
				printf("%d\n",(x*y+1)/2);
				break;
			case 'K':
				printf("%d\n",((x+1)/2)*((y+1)/2));
		}
	}
	return 0;
=======
// Problem: UVA278 Chess
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA278
// Create Time: 2025-06-29 13:54:04

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

int n,x,y;
char s[3];

signed main() {
	r(n);
	while (n--) {
		scanf("%s",s);
		r(x); r(y);
		switch (s[0]) {
			case 'r':
				printf("%d\n",min(x,y));
				break;
			case 'Q':
				printf("%d\n",min(x,y));
				break;
			case 'k':
				printf("%d\n",(x*y+1)/2);
				break;
			case 'K':
				printf("%d\n",((x+1)/2)*((y+1)/2));
		}
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}