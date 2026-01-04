// Problem: UVA10284 Chessboard in FEN
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10284
// Create Time: 2025-07-11 21:18:50

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

char a[10][10];
char fen[200];
int nowRow,nowCol,fenLen;
int kdirx[]={-2,-1,1,2,2,1,-1,-2};
int kdiry[]={1,2,2,1,-1,-2,-2,-1};
int nx,ny;
int ans;

void check() {
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++) {
			
			if (a[i][j]=='R' || a[i][j]=='r') {  //Rook
				for (int p=i-1;p>0;p--) {  //↑
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=i+1;p<9;p++) {  //↓
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=j-1;p>0;p--) {  //←
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
				for (int p=j+1;p<9;p++) {  //→
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
			}
			
			else if (a[i][j]=='b' || a[i][j]=='B') {  //Bishop
				for (int p=1;p<=min(i-1,j-1);p++) {  //↖
					if (!isalpha(a[i-p][j-p])) a[i-p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(i-1,8-j);p++) {  //↗
					if (!isalpha(a[i-p][j+p])) a[i-p][j+p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,j-1);p++) {  //↙
					if (!isalpha(a[i+p][j-p])) a[i+p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,8-j);p++) {  //↘
					if (!isalpha(a[i+p][j+p])) a[i+p][j+p]='#';
					else break;
				}				
			}
			
			else if (a[i][j]=='P') {  //Pawn
				if (!isalpha(a[i-1][j+1])) a[i-1][j+1]='#';
				if (!isalpha(a[i-1][j-1])) a[i-1][j-1]='#';
			}
			
			else if (a[i][j]=='p') {
				if (!isalpha(a[i+1][j+1])) a[i+1][j+1]='#';
				if (!isalpha(a[i+1][j-1])) a[i+1][j-1]='#';
			}
			
			else if (a[i][j]=='q' || a[i][j]=='Q') {  //Queen
				for (int p=1;p<=min(i-1,j-1);p++) {  //↖
					if (!isalpha(a[i-p][j-p])) a[i-p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(i-1,8-j);p++) {  //↗
					if (!isalpha(a[i-p][j+p])) a[i-p][j+p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,j-1);p++) {  //↙
					if (!isalpha(a[i+p][j-p])) a[i+p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,8-j);p++) {  //↘
					if (!isalpha(a[i+p][j+p])) a[i+p][j+p]='#';
					else break;
				}
				for (int p=i-1;p>0;p--) {  //↑
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=i+1;p<9;p++) {  //↓
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=j-1;p>0;p--) {  //←
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
				for (int p=j+1;p<9;p++) {  //→
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
			}
			
			else if (a[i][j]=='n' || a[i][j]=='N') {  //Knight
				for (int p=0;p<8;p++) {
					nx=i+kdirx[p];
					ny=j+kdiry[p];
					if (nx<1 || nx>8 || ny<1 || ny>8) continue;
					if (isalpha(a[nx][ny])) continue;
					a[nx][ny]='#';
				}
			}
			
			else if (a[i][j]=='K' || a[i][j]=='k') {  //King
				for (int p=i-1;p<=i+1;p++)
					for (int q=j-1;q<=j+1;q++)
						if (!isalpha(a[p][q]))
							a[p][q]='#';
			}
		}
	return;
}

void testFen() {
	for (int i=1;i<=8;i++) {
		for (int j=1;j<=8;j++)
			cout<<a[i][j];
		cout<<"\n";
	}
	cout<<"\n";
}

signed main() {
	while (scanf("%s",fen+1)!=EOF) {
		fenLen=strlen(fen+1);
		fen[0]='/';
		nowRow=0;
		for (int i=1;i<=8;i++)
			for (int j=1;j<=8;j++)
				a[i][j]='.';
		for (int i=0;i<fenLen+1;i++) {
			if (fen[i]=='/')
				nowRow++, nowCol=0;
			else if (isdigit(fen[i]))
				nowCol+=fen[i]-'0';
			else
				nowCol++,
				a[nowRow][nowCol]=fen[i];
		}
		check();
//		testFen();
		ans=0;
		for (int i=1;i<=8;i++)
			for (int j=1;j<=8;j++)
				if (a[i][j]=='.')
					ans++;
		printf("%d\n",ans);
	}
	return 0;
}