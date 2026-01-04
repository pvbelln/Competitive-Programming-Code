// Problem: UVA10116 Robot Motion
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10116
// Create Time: 2025-08-23 18:07:48

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

int r,c,s;
char m[15][15];
bool vis[15][15];
int x,y;
int step,loop,bef;
vector<int> trace;

signed main() {
	while (1) {
		r(r); r(c); r(s);
		if (!r) break;
		for (int i=1;i<=r;i++)
			scanf("%s",m[i]+1);
		memset(vis,0,sizeof vis);
		trace.clear();
		x=1; y=s; step=loop=bef=0;
		while (!vis[x][y]) {
			vis[x][y]=1;
			trace.push_back((x-1)*c+y);
			if (m[x][y]=='N') x--;
			else if (m[x][y]=='S') x++;
			else if (m[x][y]=='E') y++;
			else y--;
			step++;
			if (x<1 || y<1 || x>r || y>c) {
				printf("%d step(s) to exit\n",step);
				goto nxt;
			}
		}
		for (bef=1;;bef++)
			if (trace[bef-1]==(x-1)*c+y)
				break;
		bef--;
		printf("%d step(s) before a loop of %d step(s)\n",bef,(int)trace.size()-bef);
		nxt:
		continue;
	}
	return 0;
}