// Problem: UVA11507 Bender B. Rodríguez Problem
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA11507
// Create Time: 2025-02-27 22:54:53

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

int L;
char op[5];
int now,dir;
int f[6][6]={{0,0,0,0,0,0},
             {0,0,0,0,0,0},
	         {2,3,1,0,4,5},
             {3,2,0,1,4,5},
             {4,5,2,3,1,0},
             {5,4,2,3,0,1}};

char ans[6][5]={"+x","-x","+y","-y","+z","-z"};
             
/*
+x,-x,+y,-y,+z,-z
 0, 1, 2, 3, 4, 5
*/

signed main() {
	while (scanf("%d",&L)==1 && L) {
		now=0;
		L--;
		while (L--) {
			scanf("%s",op);
			if (op[0]=='N') continue;
			if (op[0]=='+') {
				if (op[1]=='y') dir=2;
				else dir=4;
			}
			else {
				if (op[1]=='y') dir=3;
				else dir=5;
			}
			now=f[dir][now];
		}
		printf("%s\n",ans[now]);
	}
	return 0;
}