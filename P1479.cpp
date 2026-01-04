// Problem: P1479 宿舍里的故事之五子棋
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1479
// Create Time: 2025-06-15 18:49:56

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

int n,ans;
bool vis[19];
bool a[6][6];

int count() {
	int tmp=0;
	for (int i=1;i<=5;i++) {
		if (a[1][i] && a[2][i] && a[3][i] && a[4][i] && a[5][i]) tmp++;
		if (a[i][1] && a[i][2] && a[i][3] && a[i][4] && a[i][5]) tmp++;
	}
	if (a[1][1] && a[2][2] && a[3][3] && a[4][4] && a[5][5]) tmp++;
	if (a[1][5] && a[2][4] && a[3][3] && a[4][2] && a[5][1]) tmp++;
	return tmp;
}

void dfs(int x,int y,int now) {
	if (x==6 || now==n+1) {
		if (now==n+1)
			vis[count()]=1;
		return;
	}
	if (now+(5-x)*5+(5-y+1)<n) return;
	if (y==6) dfs(x+1,1,now);
	else {
		a[x][y]=1;
		dfs(x,y+1,now+1);
		a[x][y]=0;
		dfs(x,y+1,now);
	}
}

signed main() {
	r(n);
	dfs(1,1,1);
	for (int i=1;i<=15;i++)
    	if (vis[i])
    		ans+=i;
    printf("%d\n",ans);
    return 0;
}

//爆搜+（剪枝）