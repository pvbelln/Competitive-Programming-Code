// Problem: UVA114 Simulation Wizardry
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA114
// Create Time: 2025-07-15 20:09:21

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
int cost[55][55];
int val[55][55];
bool obs[55][55];
int wallcost,p;
int x,y,dir,life;
int tot,acc;
int turn[]={3,0,1,2};
int back[]={2,3,0,1};
char faces[]={'>','^','<','v'};

void move() {
	if (dir==0)
		x++;
	else if (dir==1)
		y++;
	else if (dir==2)
		x--;
	else
		y--;
}

bool hitwall(int x,int y) {
	return x==1 || x==m || y==1 || y==n;
}

bool hitbumper(int x,int y) {
	return obs[x][y];
}

signed main() {
	r(m); r(n);
	r(wallcost); r(p);
	while (p--) {
		r(x); r(y);
		val[x][y]=read();
		cost[x][y]=read();
		obs[x][y]=1;
	}
	while (scanf("%d%d%d%d",&x,&y,&dir,&life)==4) {
		tot=0;
		cout<<"============\n";
		while (life>0) {
			cout<<"Life: "<<life<<"\n";
			cout<<"Tot: "<<tot<<"\n";
			for (int i=n;i>0;i--) {
				for (int j=1;j<=m;j++) {
					if (i==y && j==x) cout<<faces[dir];
					else if (hitwall(j,i)) cout<<"#";
					else if (hitbumper(j,i)) cout<<"*";
					else cout<<".";
				}
				cout<<"\n";
			}
			cout<<"\n";
			move();
			life--;
			if (life<=0) break;
			if (hitwall(x,y)) {
				life-=wallcost;
				dir=back[dir];
				move();
				dir=back[dir];
				dir=turn[dir];
			}
			else if (hitbumper(x,y)) {
				life-=cost[x][y];
				tot+=val[x][y];
				dir=back[dir];
				move();
				dir=back[dir];
				dir=turn[dir];
			}
		}
		printf("%d\n",tot);
		acc+=tot;
		cout<<"============\n\n";
	}
	printf("%d\n",acc);
	return 0;
}