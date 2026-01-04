// Problem: UVA10279 Mine Sweeper
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10279
// Create Time: 2025-07-12 16:19:19

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

int T,f,lose,cnt;
int n;
char a[15][15],b[15][15];

signed main() {
	r(T);
	while (T--) {
		r(n);
		for (int i=0;i<=10;i++)
			for (int j=0;j<=10;j++)
				a[i][j]=' ';     //IMPORTANT!
		for (int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		for (int i=1;i<=n;i++)
			scanf("%s",b[i]+1);
		lose=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (a[i][j]=='*' && b[i][j]=='x') {
					lose=1;
					break;
				}
		if (f) printf("\n");
		f=1;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (lose)
					if (a[i][j]=='*') {
						printf("*");
						continue;
					}
				if (b[i][j]=='x') {
					cnt=0;
					for (int p=i-1;p<=i+1;p++)
						for (int q=j-1;q<=j+1;q++)
							if (a[p][q]=='*')
								cnt++;
					printf("%d",cnt);
				}
				else printf(".");
			}
			printf("\n");
		} 
	}
	return 0;
}