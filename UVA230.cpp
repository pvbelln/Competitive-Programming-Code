// Problem: UVA230 图书管理系统 Borrowers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA230
// Create Time: 2025-10-30 11:30:22

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

string op;
string bookName, bookAuthor;
int bookCount;

struct node {
	string Name, Author;
	int onShelve;
	bool operator<(const node &a) const {
		//if (a.Author == Author)
		//	return Author < a.Author;
		//return Name < a.Name;
		return (onShelve > a.onShelve) || (onShelve == a.onShelve &&(Author < a.Author || (Author == a.Author && Name < a.Name)));
	}
};

vector<node> book, pending;

int getBookID() {
	for (int i = 0; i < book.size(); i++)
		if (book[i].Name == bookName)
			return i;
}

void shelve() {
	sort(book.begin(), book.end());
	sort(pending.begin(), pending.end());
	for (auto i : pending) {
		bookName = i.Name;
		int bookID = getBookID();
		book[bookID].onShelve = 1;
		sort(book.begin(), book.end());
		bookID = getBookID();
		if (bookID == 0)
			cout << "Put \"" << bookName <<"\" first\n";
		else
			cout << "Put \"" << bookName <<"\" after \"" << book[bookID - 1].Name <<"\"\n";
	}
	puts("END");
	pending.clear();
}

signed main() {
	while (1) {  // read all books
		getline(cin, op);
		if (op == "END")
			break;
		int flag = 0;
		bookCount++;
		bookName = bookAuthor = "";
		for (int i = 0; i < (int)op.length(); i++) {
			if (op[i] == '"') {
				flag ++;
				continue;
			}
			if (flag == 1)
				bookName += op[i];
			else if (flag == 2) {
				i += 3;
				flag ++;
				continue;
			}
			else
				bookAuthor += op[i];
		}
		book.push_back({bookName, bookAuthor, 1});
	}
	while (1) {
		getline(cin, op);
		if (op == "END")
			break;
		if (op[0] == 'S')
			shelve();
		bookName = "";
		int flag = 0;
		for (int i = 0; i < (int)op.length(); i++) {
			if (op[i] == '"') {
				flag ++;
				continue;
			}
			if (flag == 1)
				bookName += op[i];
		}
		int bookID = getBookID();
		if (op[0] == 'B')
			book[bookID].onShelve = 0;
		else if (op[0] == 'R')
			pending.push_back(book[bookID]);
	}
	return 0;
}