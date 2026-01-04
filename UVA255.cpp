// Problem: UVA255 Correct Move
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA255
// Create Time: 2025-03-05 23:22:59

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

int k,q,nxt,rem,f;

signed main() {
	while (scanf("%d%d%d",&k,&q,&nxt)==3) {
		if (k==q) {
			puts("Illegal state");
			continue;
		}
		f=0;
		/*
		if (nxt == k || ((nxt/8 != q/8) && ((q-nxt)%8 != 0))) {
			puts("Illegal move");
			continue;
		}
		*/
		for (int i=q;i<=(q/8+1)*8-1;i++) {
			if (i==k) break;
			if (i==nxt) f=1;
		}
		for (int i=q;i>=(q/8)*8;i--) {
			if (i==k) break;
			if (i==nxt) f=1;
		}
		for (int i=q;i<=63;i+=8) {
			if (i==k) break;
			if (i==nxt) f=1;
		}
		for (int i=q;i>=0;i-=8) {
			if (i==k) break;
			if (i==nxt) f=1;
		}
		if (nxt == k || nxt == q) f=0;
		if (!f) {
			puts("Illegal move");
			continue;
		}
		f=1;
		if (k%8 == 0) {if (nxt==k-8 || nxt==k+8 || nxt==k+1) f=0;}
		else if (k%8 == 7) {if (nxt==k-8 || nxt==k+8 || nxt==k-1) f=0;}
		else if (nxt==k-8 || nxt==k+8 || nxt==k-1 || nxt==k+1) f=0; 
		if (!f) {
			puts("Move not allowed");
			continue;
		}
		rem=4;
		if (k>7) {if ((k-8)/8 == nxt/8) rem--;}
		else rem--;
		if (k<56) {if ((k+8)/8 == nxt/8) rem--;}
		else rem--;
		if (k%8 != 0) {if ((k-1-nxt)%8 == 0) rem--;}
		else rem--;
		if (k%8 != 7) {if ((k+1-nxt)%8 == 0) rem--;}
		else rem--;
		if (rem==0) puts("Stop");
		else puts("Continue");
	}
	return 0;
}