// Problem: UVA647 Chutes and Ladders
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA647
// Create Time: 2025-09-13 10:05:25

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

int moves[1005];
int dest[105];
int bonus[105];  //1: halt, 2: again
int pos[10],miss[10],win[10];
int x,y,moveCnt,playerNum;

void dbg() {
	for (int i=1;i<=playerNum;i++)
		cerr<<pos[i]<<" ";
	cerr<<"\n";
}

int play() {
	int nowPlayer=1,winNum=0;
	memset(pos,0,sizeof pos);
	memset(miss,0,sizeof miss);
	memset(win,0,sizeof win);
	for (int i=1;i<=moveCnt;i++) {
		if (nowPlayer>playerNum)
			nowPlayer=1;
		if (miss[nowPlayer]) {
//			dbg();
			miss[nowPlayer]=0;
			i--;
			continue;
		}
		if (pos[nowPlayer]+moves[i]>=100 && (!win[nowPlayer])) {
//			dbg();
			if (pos[nowPlayer]+moves[i]==100)
				winNum++, win[nowPlayer]=1; 
			nowPlayer++;
			continue;
		}
		pos[nowPlayer]+=moves[i];
		if (dest[pos[nowPlayer]])
			pos[nowPlayer]=dest[pos[nowPlayer]];
//		dbg();
		if (int k=bonus[pos[nowPlayer]]) {
			if (k==1) miss[nowPlayer]=1, nowPlayer++;
		}
		else nowPlayer++;
	}
	return winNum;
}

signed main() {
	while (1) {
		r(x);
		if (x) moves[++moveCnt]=x;
		else break;
	}
	while (1) {
		r(playerNum);
		if (!playerNum) break;
		memset(dest,0,sizeof dest);
		memset(bonus,0,sizeof bonus);
		while (1) {
			r(x); r(y);
			if (!(x+y)) break;
			dest[x]=y;
		}
		while (1) {
			r(x);
			if (!x) break;
			if (x<0) bonus[-x]=1;
			else bonus[x]=2;
		}
		printf("%d\n",play());
		cerr<<"\n\n";
	}
	return 0;
}