// Problem: UVA220 黑白棋 Othello
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA220
// Create Time: 2025-07-16 16:04:21

#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
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
char a[13][13];
char op[7];
bool hasLegalMv,firstEle;
char nowPlayer;

void print() {
	for (int i=1;i<=8;i++)
		printf("%s\n",a[i]+1);
}

bool chk(int x,int y,bool rep,char nowPlayer) {
	bool success=0;
	bool hasOther,finall=0;
	// ↑
	hasOther=success=0;
	for (int i=x-1;i>0;i--) {
		if (a[i][y]=='-') break;
		if (a[i][y]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[i][y]==nowPlayer) {
			success=1;
			if (rep)
				for (int j=x;j>=i;j--)
					a[j][y]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// ↓
	hasOther=success=0;
	for (int i=x+1;i<9;i++) {
		if (a[i][y]=='-') break;
		if (a[i][y]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[i][y]==nowPlayer) {
			success=1;
			if (rep)
				for (int j=x;j<=i;j++)
					a[j][y]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// ←
	hasOther=success=0;
	for (int i=y-1;i>0;i--) {
		if (a[x][i]=='-') break;
		if (a[x][i]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[x][i]==nowPlayer) {
			success=1;
			if (rep)
				for (int j=y;j>=i;j--)
					a[x][j]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// →
	hasOther=success=0;
	for (int i=y+1;i<9;i++) {
		if (a[x][i]=='-') break;
		if (a[x][i]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[x][i]==nowPlayer) {
			success=1;
			if (rep)
				for (int j=y;j<=i;j++)
					a[x][j]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// ↗
	hasOther=success=0;
	for (int i=x-1,j=y+1;i>0 && j<9;i--,j++) {
		if (a[i][j]=='-') break;
		if (a[i][j]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[i][j]==nowPlayer) {
			success=1;
			if (rep)
				for (int p=x,q=y;p>=i && q<=j;p--,q++)
					a[p][q]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// ↖
	hasOther=success=0;
	for (int i=x-1,j=y-1;i>0 && j>0;i--,j--) {
		if (a[i][j]=='-') break;
		if (a[i][j]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[i][j]==nowPlayer) {
			success=1;
			if (rep)
				for (int p=x,q=y;p>=i && q>=j;p--,q--)
					a[p][q]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// ↙
	hasOther=success=0;
	for (int i=x+1,j=y-1;i<9 && j>0;i++,j--) {
		if (a[i][j]=='-') break;
		if (a[i][j]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[i][j]==nowPlayer) {
			success=1;
			if (rep)
				for (int p=x,q=y;p<=i && q>=j;p++,q--)
					a[p][q]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	// ↘
	hasOther=success=0;
	for (int i=x+1,j=y+1;i<9 && j<9;i++,j++) {
		if (a[i][j]=='-') break;
		if (a[i][j]=='W'+'B'-nowPlayer) hasOther=1;
		if (a[i][j]==nowPlayer) {
			success=1;
			if (rep)
				for (int p=x,q=y;p<=i && q<=j;p++,q++)
					a[p][q]=nowPlayer;
			break;
		}
	}
	if (hasOther && success) {
		finall=1;
		if (!rep)
			return 1;
	}
	return finall;
}

void List() {
	firstEle=1;
	hasLegalMv=0;
//	cout<<nowPlayer;
//	cout<<chk(3,5,0,'W')<<"===\n";
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++) {
			if (a[i][j]!='-') continue;
			if (chk(i,j,0,nowPlayer)) {
				if (!firstEle) printf(" ");
				firstEle=0;
				hasLegalMv=1;
				printf("(%d,%d)",i,j);
			}
		}
	if (!hasLegalMv) printf("No legal move.");
	printf("\n");
}

void Move(int x,int y) {
	int B=0, W=0;
	if (chk(x,y,1,nowPlayer)) B=0;
	else {
		nowPlayer='W'+'B'-nowPlayer;
		if (chk(x,y,1,nowPlayer));
	}
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++) {
			if (a[i][j]=='B') B++;
			else if (a[i][j]=='W') W++;
		}
//	cout<<"Black - "<<setw(2)<<B<<" White - "<<setw(2)<<W<<"\n";
	printf("Black - %2d White - %2d\n",B,W);
	nowPlayer='W'+'B'-nowPlayer;
}

signed main() {
	r(T);
	for (int kase=1;kase<=T;kase++) {
		for (int i=1;i<=8;i++)
			scanf("%s",a[i]+1);
		scanf("%s",op);
		nowPlayer=op[0];
		while (scanf("%s",op)==1) {
			if (op[0]=='Q') {
				print();
				if (kase!=T) printf("\n");
				break;
			}
			else if (op[0]=='L') 
				List();
			else if (op[0]=='M')
				Move(op[1]-'0',op[2]-'0');
		}
	}
	return 0;
}