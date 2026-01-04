<<<<<<< HEAD
// Problem: 2048
// Contest: Kattis
// URL: https://open.kattis.com/problems/2048#a0000000002
// Create Time: 2025-06-14 19:25:44

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

int a[5][5];
int dir; //l u r d
vector<int> mem;

void merge(int dir) {
	if (dir==0) {
		for (int i=1;i<=4;i++)
			for (int j=1;j<=3;j++)
				if (a[i][j]==a[i][j+1]) a[i][j]<<=1, a[i][j+1]=0;
	}
	else if (dir==1) {
		for (int j=1;j<=4;j++)
			for (int i=1;i<=3;i++)
				if (a[i][j]==a[i+1][j]) a[i][j]<<=1, a[i+1][j]=0;
	}
	else if (dir==2) {
		for (int i=1;i<=4;i++)
			for (int j=4;j>=2;j--)
				if (a[i][j]==a[i][j-1]) a[i][j]<<=1, a[i][j-1]=0;
	}
	else {
		for (int j=1;j<=4;j++)
			for (int i=4;i>=1;i--)
				if (a[i][j]==a[i-1][j]) a[i][j]<<=1, a[i-1][j]=0;
	}
}

void fall(int dir) {
	if (dir==0) {
		for (int i=1;i<=4;i++) {
			mem.clear();
			for (int j=1;j<=4;j++)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int j=1;j<=4;j++)
				a[i][j]=mem[j-1];
		}
	}
	else if (dir==1) {
		for (int j=1;j<=4;j++) {
			mem.clear();
			for (int i=1;i<=4;i++)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int i=1;i<=4;i++)
				a[i][j]=mem[i-1];
		}
	}
	else if (dir==2) {
		for (int i=1;i<=4;i++) {
			mem.clear();
			for (int j=4;j>=1;j--)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int j=4;j>=1;j--)
				a[i][j]=mem[4-j];
		}
	}
	else {
		for (int j=1;j<=4;j++) {
			mem.clear();
			for (int i=4;i>=1;i--)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int i=4;i>=1;i--)
				a[i][j]=mem[4-i];
		}
	}
}

signed main() {
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			r(a[i][j]);
	r(dir);
	fall(dir);
	merge(dir);
	fall(dir);
	for (int i=1;i<=4;i++) {
		for (int j=1;j<=4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
=======
// Problem: 2048
// Contest: Kattis
// URL: https://open.kattis.com/problems/2048#a0000000002
// Create Time: 2025-06-14 19:25:44

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

int a[5][5];
int dir; //l u r d
vector<int> mem;

void merge(int dir) {
	if (dir==0) {
		for (int i=1;i<=4;i++)
			for (int j=1;j<=3;j++)
				if (a[i][j]==a[i][j+1]) a[i][j]<<=1, a[i][j+1]=0;
	}
	else if (dir==1) {
		for (int j=1;j<=4;j++)
			for (int i=1;i<=3;i++)
				if (a[i][j]==a[i+1][j]) a[i][j]<<=1, a[i+1][j]=0;
	}
	else if (dir==2) {
		for (int i=1;i<=4;i++)
			for (int j=4;j>=2;j--)
				if (a[i][j]==a[i][j-1]) a[i][j]<<=1, a[i][j-1]=0;
	}
	else {
		for (int j=1;j<=4;j++)
			for (int i=4;i>=1;i--)
				if (a[i][j]==a[i-1][j]) a[i][j]<<=1, a[i-1][j]=0;
	}
}

void fall(int dir) {
	if (dir==0) {
		for (int i=1;i<=4;i++) {
			mem.clear();
			for (int j=1;j<=4;j++)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int j=1;j<=4;j++)
				a[i][j]=mem[j-1];
		}
	}
	else if (dir==1) {
		for (int j=1;j<=4;j++) {
			mem.clear();
			for (int i=1;i<=4;i++)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int i=1;i<=4;i++)
				a[i][j]=mem[i-1];
		}
	}
	else if (dir==2) {
		for (int i=1;i<=4;i++) {
			mem.clear();
			for (int j=4;j>=1;j--)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int j=4;j>=1;j--)
				a[i][j]=mem[4-j];
		}
	}
	else {
		for (int j=1;j<=4;j++) {
			mem.clear();
			for (int i=4;i>=1;i--)
				if (a[i][j]) mem.push_back(a[i][j]);
			while (mem.size()<=3) mem.push_back(0);
			for (int i=4;i>=1;i--)
				a[i][j]=mem[4-i];
		}
	}
}

signed main() {
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			r(a[i][j]);
	r(dir);
	fall(dir);
	merge(dir);
	fall(dir);
	for (int i=1;i<=4;i++) {
		for (int j=1;j<=4;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}