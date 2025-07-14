// Problem: 14:扫雷游戏地雷数计算
// Contest: OpenJudge - NOI - 1.8编程基础之多维数组
// URL: http://noi.openjudge.cn/ch0108/14/
// Create Time: 2025-06-19 21:07:08

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

int n,m;
int a[105][105];
char c;

signed main() {
	r(n); r(m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			cin>>c;
			if(c=='*') {
				for (int p=i-1;p<=i+1;p++)
					for (int q=j-1;q<=j+1;q++)
						a[p][q]++;
				a[i][j]=-1e8;
			}
		}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++)
			if (a[i][j]<0) printf("*");
			else printf("%d",a[i][j]);
		printf("\n");
	}
	return 0;
}