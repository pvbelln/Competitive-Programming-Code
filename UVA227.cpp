// Problem: UVA227 谜题 Puzzle
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA227
// Create Time: 2025-07-16 18:59:14

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

int a[8][8];
char op;
int x,y;
int puzz;

bool Move() {
	if (op=='A') {
		if (x==1) return 0;
		a[x][y]=a[x-1][y];
		a[x-1][y]=' ';
		x--;
	}
	else if (op=='B') {
		if (x==5) return 0;
		a[x][y]=a[x+1][y];
		a[x+1][y]=' ';
		x++;
	}
	else if (op=='R') {
		if (y==5) return 0;
		a[x][y]=a[x][y+1];
		a[x][y+1]=' ';
		y++;
	}
	else if (op=='L') {
		if (y==1) return 0;
		a[x][y]=a[x][y-1];
		a[x][y-1]=' ';
		y--;
	}
	else return 0;
/*	
	cout<<"====\n";
	cout<<op<<"\n";
	for (int i=1;i<=5;i++) {
			for (int j=1;j<=5;j++) {
				if (j>1) printf(" ");
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	cout<<"====\n";
*/	
	return 1;
}

void print(bool succ) {
	if (puzz!=1) printf("\n");
	printf("Puzzle #%d:\n",puzz);
	if (!succ) puts("This puzzle has no final configuration.");
	else {
		for (int i=1;i<=5;i++) {
			for (int j=1;j<=5;j++) {
				if (j>1) printf(" ");
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	}
}

signed main() {
	bool succc;
	while (1) {
		succc=1;
		puzz++;
		a[1][1]=getchar();
		if (a[1][1]=='Z') break;
		a[1][2]=getchar();
		a[1][3]=getchar();
		a[1][4]=getchar();
		a[1][5]=getchar();
		getchar();
		for (int i=2;i<=5;i++)
			for (int j=1;j<=5;j++) {
				a[i][j]=getchar();
				if (j==5 && a[i][j]=='\n') {
					a[i][j]=' ';
					continue;
				}
				if (j==5) getchar();
			}
		for (int i=1;i<=5;i++)
			for (int j=1;j<=5;j++)
				if (a[i][j]==' ')
					x=i, y=j;
/*		
	cout<<"====\n";
	cout<<op<<"\n";
	for (int i=1;i<=5;i++) {
			for (int j=1;j<=5;j++) {
				if (j>1) printf(" ");
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	cout<<"====\n";
*/		
		while (1) {
			op=getchar();
			if (op=='\n') continue;
			else if (op=='0') break;
			if (!succc) continue;
			else {
				if (!Move()) succc=0, print(0);
			}
		}
		if (succc) print(1);
		getchar();
	}
	return 0;
}