// Problem: UVA141 The Spot Game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA141
// Create Time: 2025-07-16 10:59:24

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
#include<unordered_set>
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

int n;
bool a[55][55];
int x,y,nowplayer;
char op[5];
unordered_set<string> st;
bool gameend;

void dbg() {
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++)
			cout<<(int)a[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

void turn() {
	bool tmp[55][55];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			tmp[j][n-i+1]=a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=tmp[i][j];
}

bool chk() {
	string now[5];
	bool ok=0;
	for (int kk=1;kk<=4;kk++) {
		now[kk]="";
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				if (a[i][j]) now[kk]+='1';
				else now[kk]+='0';
			}
//		cout<<now[kk]<<"\n";
		turn();
	}
	for (int i=1;i<=4;i++) {
		if (st.find(now[i]) != st.end())
			return true;
	}
	st.insert(now[1]);
	return false;
}

signed main() {
	while (1) {
		r(n);
		if (!n) break;
		memset(a,0,sizeof a);
		st.clear();
		gameend=0;
		nowplayer=2;
		for (int _=1;_<=2*n;_++) {
			scanf("%d%d%s",&x,&y,op);
			if (gameend) continue;
			if (op[0]=='+') a[x][y]=1;
			else a[x][y]=0;
			if (chk()) {
				gameend=1;
				printf("Player %d wins on move %d\n",nowplayer,_);
			}
			if (nowplayer==1) nowplayer=2;
			else nowplayer=1;
		}
		if (!gameend) puts("Draw");
	}
	return 0;
}