<<<<<<< HEAD
// Problem: Mud Puddles
// Contest: POJ - USACO 2007 December Silver
// URL: http://poj.org/problem?id=3626
// Create Time: 2025-05-03 18:50:30

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
//#define getchar getchar_unlocked
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

bool v[1005][1005];
int x,y,n,a,b,nx,ny,ns,nxtx,nxty;
struct node {
	int x,y,step;
};
queue<node> q;

signed main() {
	r(x); r(y); r(n);
	x+=501; y+=501;
	while (n--) {
		r(a); r(b);
		v[a+501][b+501]=1;
	}
	q.push((node){501,501,0});
	while (q.size()) {
		node now=q.front();
		q.pop();
		nx=now.x; ny=now.y; ns=now.step;
		if (nx==x && ny==y) {
			printf("%d\n",ns);
			break;
		}
		if (v[nx][ny]) continue;
		v[nx][ny]=1;
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
				if ((i||j)&&(i*j==0)) {
					nxtx=nx+i, nxty=ny+j;
					if (nxtx>0 && nxty>0 && nxtx<=1001 && nxty<=1001)
						q.push((node){nxtx,nxty,ns+1});
				}
	}
	return 0;
=======
// Problem: Mud Puddles
// Contest: POJ - USACO 2007 December Silver
// URL: http://poj.org/problem?id=3626
// Create Time: 2025-05-03 18:50:30

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
//#define getchar getchar_unlocked
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

bool v[1005][1005];
int x,y,n,a,b,nx,ny,ns,nxtx,nxty;
struct node {
	int x,y,step;
};
queue<node> q;

signed main() {
	r(x); r(y); r(n);
	x+=501; y+=501;
	while (n--) {
		r(a); r(b);
		v[a+501][b+501]=1;
	}
	q.push((node){501,501,0});
	while (q.size()) {
		node now=q.front();
		q.pop();
		nx=now.x; ny=now.y; ns=now.step;
		if (nx==x && ny==y) {
			printf("%d\n",ns);
			break;
		}
		if (v[nx][ny]) continue;
		v[nx][ny]=1;
		for (int i=-1;i<=1;i++)
			for (int j=-1;j<=1;j++)
				if ((i||j)&&(i*j==0)) {
					nxtx=nx+i, nxty=ny+j;
					if (nxtx>0 && nxty>0 && nxtx<=1001 && nxty<=1001)
						q.push((node){nxtx,nxty,ns+1});
				}
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}