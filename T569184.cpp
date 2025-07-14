// Problem: T569184 【OI】每日打卡心情好
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T569184
// Create Time: 2025-06-14 15:15:45

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
string s;

signed main() {
	getline(cin,s);
	while (scanf("%d",&x)==1) {
		if (x) {
			if (nono) {
				consec-=pow(2,nono-1);
				consec=max(consec,0);
				nono=0;
			}
			consec++;
		}
		else nono++;
	}
	printf("%d\n",consec);
	return 0;
}