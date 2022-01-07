#include<stdio.h>

union{
	struct {
		char a :1;
		char b :2;
		char c :3;
	}s;
	char d;

}u;

int main(){
	u.d=6;
	printf("b=%d\n",u.s.b);
	printf("a=%d\n",u.s.a);
	printf("c=%d\n",u.s.c);
	printf("d=%d\n",u.d);

	printf("length:%d\n", sizeof(u));

	return 0;
}
