<<<<<<< HEAD
// Problem: UVA10196 Check The Check
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10196
// Create Time: 2025-06-29 19:44:59

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

vector<pair<int,int>> pos[13];
// 1P 2N 3B 4R 5Q 6K 7p 8n 9b 10r 11q 12k
char a[10][10],tmp[10][10];
bool isEmpty,case_end;
int stat; //0:no  1:white  2:black
string pieces=" PNBRQKpnbrqk";
int Game;
int kdirx[]={-2,-1,1,2,2,1,-1,-2};
int kdiry[]={1,2,2,1,-1,-2,-2,-1};
int nx,ny;

void print() {
	for (int i=1;i<=8;i++) {
		for (int j=1;j<=8;j++)
			cout<<a[i][j];
		cout<<"\n";
	}
	cout<<"\n";
}

void finall(int stat) {
	if (stat==1)
		printf("Game #%d: white king is in check.\n",Game);
	else if (stat==2)
		printf("Game #%d: black king is in check.\n",Game);
	else
		printf("Game #%d: no king is in check.\n",Game);
	case_end=true;
}

int isking(char c,char attacker) {
	if (c=='K' && attacker>='a' && attacker<='z') finall(1);
	else if (c=='k' && attacker>='A' && attacker<='Z') finall(2);
	return case_end;
}

int decode(char c) {
	return pieces.find(c);
}

void init() {
	for (int i=1;i<13;i++)
		pos[i].clear();
	Game++;
}

bool parse() {
	isEmpty=true;
	case_end=false;
	for (int i=1;i<=8;i++)
		scanf("%s",a[i]+1);
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++)
			if (isalpha(a[i][j])) {
				isEmpty=false;
				pos[decode(a[i][j])].push_back({i,j});
				tmp[i][j]=a[i][j];
			}
	return isEmpty;
}

void check() {
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++) {
			
			if (a[i][j]=='R' || a[i][j]=='r') {  //Rook
				for (int p=i-1;p>0;p--) {  //↑
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=i+1;p<9;p++) {  //↓
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=j-1;p>0;p--) {  //←
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
				for (int p=j+1;p<9;p++) {  //→
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
			}
			
			else if (a[i][j]=='b' || a[i][j]=='B') {  //Bishop
				for (int p=1;p<=min(i-1,j-1);p++) {  //↖
					if (isking(a[i-p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j-p])) a[i-p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(i-1,8-j);p++) {  //↗
					if (isking(a[i-p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j+p])) a[i-p][j+p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,j-1);p++) {  //↙
					if (isking(a[i+p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j-p])) a[i+p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,8-j);p++) {  //↘
					if (isking(a[i+p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j+p])) a[i+p][j+p]='#';
					else break;
				}				
			}
			
			else if (a[i][j]=='P') {  //Pawn
				if (isking(a[i-1][j+1],a[i][j])) goto END;
				if (!isalpha(a[i-1][j+1])) a[i-1][j+1]='#';
				if (isking(a[i-1][j-1],a[i][j])) goto END;
				if (!isalpha(a[i-1][j-1])) a[i-1][j-1]='#';
			}
			
			else if (a[i][j]=='p') {
				if (isking(a[i+1][j+1],a[i][j])) goto END;
				if (!isalpha(a[i+1][j+1])) a[i+1][j+1]='#';
				if (isking(a[i+1][j-1],a[i][j])) goto END;
				if (!isalpha(a[i+1][j-1])) a[i+1][j-1]='#';
			}
			
			else if (a[i][j]=='q' || a[i][j]=='Q') {  //Queen
				for (int p=1;p<=min(i-1,j-1);p++) {  //↖
					if (isking(a[i-p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j-p])) a[i-p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(i-1,8-j);p++) {  //↗
					if (isking(a[i-p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j+p])) a[i-p][j+p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,j-1);p++) {  //↙
					if (isking(a[i+p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j-p])) a[i+p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,8-j);p++) {  //↘
					if (isking(a[i+p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j+p])) a[i+p][j+p]='#';
					else break;
				}
				for (int p=i-1;p>0;p--) {  //↑
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=i+1;p<9;p++) {  //↓
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=j-1;p>0;p--) {  //←
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
				for (int p=j+1;p<9;p++) {  //→
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
			}
			
			else if (a[i][j]=='n' || a[i][j]=='N') {  //Knight
				for (int p=0;p<8;p++) {
					nx=i+kdirx[p];
					ny=j+kdiry[p];
					if (nx<1 || nx>8 || ny<1 || ny>8) continue;
					if (isking(a[nx][ny],a[i][j])) goto END;
				}
			}
		}
	finall(0);
	END:
	return;
}



signed main() {
	while (1) {
		init();
		if (parse()) break;
		check();
	//	print();
	}
	return 0;
=======
// Problem: UVA10196 Check The Check
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA10196
// Create Time: 2025-06-29 19:44:59

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

vector<pair<int,int>> pos[13];
// 1P 2N 3B 4R 5Q 6K 7p 8n 9b 10r 11q 12k
char a[10][10],tmp[10][10];
bool isEmpty,case_end;
int stat; //0:no  1:white  2:black
string pieces=" PNBRQKpnbrqk";
int Game;
int kdirx[]={-2,-1,1,2,2,1,-1,-2};
int kdiry[]={1,2,2,1,-1,-2,-2,-1};
int nx,ny;

void print() {
	for (int i=1;i<=8;i++) {
		for (int j=1;j<=8;j++)
			cout<<a[i][j];
		cout<<"\n";
	}
	cout<<"\n";
}

void finall(int stat) {
	if (stat==1)
		printf("Game #%d: white king is in check.\n",Game);
	else if (stat==2)
		printf("Game #%d: black king is in check.\n",Game);
	else
		printf("Game #%d: no king is in check.\n",Game);
	case_end=true;
}

int isking(char c,char attacker) {
	if (c=='K' && attacker>='a' && attacker<='z') finall(1);
	else if (c=='k' && attacker>='A' && attacker<='Z') finall(2);
	return case_end;
}

int decode(char c) {
	return pieces.find(c);
}

void init() {
	for (int i=1;i<13;i++)
		pos[i].clear();
	Game++;
}

bool parse() {
	isEmpty=true;
	case_end=false;
	for (int i=1;i<=8;i++)
		scanf("%s",a[i]+1);
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++)
			if (isalpha(a[i][j])) {
				isEmpty=false;
				pos[decode(a[i][j])].push_back({i,j});
				tmp[i][j]=a[i][j];
			}
	return isEmpty;
}

void check() {
	for (int i=1;i<=8;i++)
		for (int j=1;j<=8;j++) {
			
			if (a[i][j]=='R' || a[i][j]=='r') {  //Rook
				for (int p=i-1;p>0;p--) {  //↑
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=i+1;p<9;p++) {  //↓
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=j-1;p>0;p--) {  //←
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
				for (int p=j+1;p<9;p++) {  //→
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
			}
			
			else if (a[i][j]=='b' || a[i][j]=='B') {  //Bishop
				for (int p=1;p<=min(i-1,j-1);p++) {  //↖
					if (isking(a[i-p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j-p])) a[i-p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(i-1,8-j);p++) {  //↗
					if (isking(a[i-p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j+p])) a[i-p][j+p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,j-1);p++) {  //↙
					if (isking(a[i+p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j-p])) a[i+p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,8-j);p++) {  //↘
					if (isking(a[i+p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j+p])) a[i+p][j+p]='#';
					else break;
				}				
			}
			
			else if (a[i][j]=='P') {  //Pawn
				if (isking(a[i-1][j+1],a[i][j])) goto END;
				if (!isalpha(a[i-1][j+1])) a[i-1][j+1]='#';
				if (isking(a[i-1][j-1],a[i][j])) goto END;
				if (!isalpha(a[i-1][j-1])) a[i-1][j-1]='#';
			}
			
			else if (a[i][j]=='p') {
				if (isking(a[i+1][j+1],a[i][j])) goto END;
				if (!isalpha(a[i+1][j+1])) a[i+1][j+1]='#';
				if (isking(a[i+1][j-1],a[i][j])) goto END;
				if (!isalpha(a[i+1][j-1])) a[i+1][j-1]='#';
			}
			
			else if (a[i][j]=='q' || a[i][j]=='Q') {  //Queen
				for (int p=1;p<=min(i-1,j-1);p++) {  //↖
					if (isking(a[i-p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j-p])) a[i-p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(i-1,8-j);p++) {  //↗
					if (isking(a[i-p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i-p][j+p])) a[i-p][j+p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,j-1);p++) {  //↙
					if (isking(a[i+p][j-p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j-p])) a[i+p][j-p]='#';
					else break;
				}
				for (int p=1;p<=min(8-i,8-j);p++) {  //↘
					if (isking(a[i+p][j+p],a[i][j])) goto END;
					if (!isalpha(a[i+p][j+p])) a[i+p][j+p]='#';
					else break;
				}
				for (int p=i-1;p>0;p--) {  //↑
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=i+1;p<9;p++) {  //↓
					if (isking(a[p][j],a[i][j])) goto END;
					if (!isalpha(a[p][j])) a[p][j]='#';
					else break;
				}
				for (int p=j-1;p>0;p--) {  //←
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
				for (int p=j+1;p<9;p++) {  //→
					if (isking(a[i][p],a[i][j])) goto END;
					if (!isalpha(a[i][p])) a[i][p]='#';
					else break;
				}
			}
			
			else if (a[i][j]=='n' || a[i][j]=='N') {  //Knight
				for (int p=0;p<8;p++) {
					nx=i+kdirx[p];
					ny=j+kdiry[p];
					if (nx<1 || nx>8 || ny<1 || ny>8) continue;
					if (isking(a[nx][ny],a[i][j])) goto END;
				}
			}
		}
	finall(0);
	END:
	return;
}



signed main() {
	while (1) {
		init();
		if (parse()) break;
		check();
	//	print();
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}