// Problem: UVA10363 Tic Tac Toe
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10363
// Create Time: 2025-09-18 10:51:46

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

int T;
char s[5][5];
int xCount, oCount;

bool win(char c) {
	for (int i=1;i<=3;i++) {
		if (s[i][1]==c && s[i][2]==c && s[i][3]==c) return true;
		if (s[1][i]==c && s[2][i]==c && s[3][i]==c) return true;
	}
	if (s[1][1]==c && s[2][2]==c && s[3][3]==c) return true;
	if (s[1][3]==c && s[2][2]==c && s[3][1]==c) return true;
	return false;
}

signed main() {
	r(T);
	while (T--) {
		xCount=oCount=0;
		for (int i=1;i<=3;i++)
			scanf("%s",s[i]+1);
		for (int i=1;i<=3;i++)
			for (int j=1;j<=3;j++) {
				if (s[i][j]=='X') xCount++;
				else if (s[i][j]=='O') oCount++;
			}
		if (oCount>xCount || xCount-oCount>1) {
			puts("no");
			continue;
		}
		else if (xCount-oCount==1) {
			if (win('O'))
				puts("no");
			else
				puts("yes");
		}
		else if (xCount==oCount) {
			if (win('X'))
				puts("no");
			else
				puts("yes");
		}
	}
	return 0;
}