<<<<<<< HEAD
// Problem: P1664 每日打卡心情好
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1664
// Create Time: 2025-06-14 14:57:39

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

int n,consec,tot,x,nono;

signed main() {
	r(n);
	while (n--) {
		r(x);
		if (x) {
			if (nono) {
				if (nono>=11) consec=0;
				else consec-=pow(2,nono-1);
				consec=max(consec,0);
				nono=0;
			}
			consec++;
			if (consec<3) tot+=1;
			else if (consec<7) tot+=2;
			else if (consec<30) tot+=3;
			else if (consec<120) tot+=4;
			else if (consec<365) tot+=5;
			else tot+=6;
		}
		else nono++;
		cerr<<consec<<"\n";
	}
	printf("%d\n",tot);
	return 0;
=======
// Problem: P1664 每日打卡心情好
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1664
// Create Time: 2025-06-14 14:57:39

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

int n,consec,tot,x,nono;

signed main() {
	r(n);
	while (n--) {
		r(x);
		if (x) {
			if (nono) {
				if (nono>=11) consec=0;
				else consec-=pow(2,nono-1);
				consec=max(consec,0);
				nono=0;
			}
			consec++;
			if (consec<3) tot+=1;
			else if (consec<7) tot+=2;
			else if (consec<30) tot+=3;
			else if (consec<120) tot+=4;
			else if (consec<365) tot+=5;
			else tot+=6;
		}
		else nono++;
		cerr<<consec<<"\n";
	}
	printf("%d\n",tot);
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}