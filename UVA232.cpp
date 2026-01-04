// Problem: UVA232 纵横字谜的答案 Crossword Answers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA232
// Create Time: 2025-07-21 21:29:22

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

int r,c;
char a[15][15];
int x[15][15];
int cnt;

void num() {
	int now=0;
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			if ((a[i-1][j]=='*' || a[i][j-1]=='*') && a[i][j]!='*')
				x[i][j]=++now;
}

void print(int pos,int x,int y,bool dir) { //1: >; 0: v
	if (dir) {
		printf("%3d.",pos);
		while (isalpha(a[x][y])) {
			putchar(a[x][y]);
			y++;
		}
		putchar('\n');
	}
	else {
		printf("%3d.",pos);
		while (isalpha(a[x][y])) {
			putchar(a[x][y]);
			x++;
		}
		putchar('\n');
	}
}

signed main() {
	while (1) {
		r(r);
		if (!r) break;
		r(c);
		memset(x,0,sizeof x);
		for (int i=1;i<=r;i++)
			scanf("%s",a[i]+1);
		for (int i=0;i<=c+1;i++)
			a[0][i]=a[r+1][i]='*';
		for (int i=0;i<=r+1;i++)
			a[i][0]=a[i][c+1]='*';
		if (cnt) printf("\n");
		printf("puzzle #%d:\nAcross\n",++cnt);
		num();
		for (int i=1;i<=r;i++)
			for (int j=1;j<=c;j++)
				if (x[i][j] && a[i][j-1]=='*')
					print(x[i][j],i,j,1);
		printf("Down\n");
		for (int i=1;i<=r;i++)
			for (int j=1;j<=c;j++)
				if (x[i][j] && a[i-1][j]=='*')
					print(x[i][j],i,j,0);
	}
	return 0;
}