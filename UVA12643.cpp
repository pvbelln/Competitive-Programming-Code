<<<<<<< HEAD
#include<cstdio>
int n,i,j;
int main() {
	while (scanf("%d%d%d",&n,&i,&j)==3) {
		i--;
		j--;
		printf("%d\n",32-__builtin_clz(i^j));
	}
	return 0;
=======
#include<cstdio>
int n,i,j;
int main() {
	while (scanf("%d%d%d",&n,&i,&j)==3) {
		i--;
		j--;
		printf("%d\n",32-__builtin_clz(i^j));
	}
	return 0;
>>>>>>> cde37808a4e84b5a0f4eff8a64ee2de25180a978
}