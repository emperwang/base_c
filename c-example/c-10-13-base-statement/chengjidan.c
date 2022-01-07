#include <stdio.h>

void level(int n);

int main(){
	int num = 0;
	printf("Please input your score:\n");
	scanf("%d", &num);
	level(num);

	return 0;
}

void level(int n){
	int flag = 0;
	if(n < 60){
		flag = 1;
	}else if( n >= 60 && n < 80){
		flag = 2;
	}else if (n >= 80 && n < 100){
		flag = 3;
	}else if (n == 100){
		flag = 4;
	}

	switch (flag){
		case 1:
			printf("太差,加油!!!\n");
			break;
		case 2:
			printf("良好.\n");
			break;
		case 3:
			printf("挺优秀.\n");
			break;
		case 4:
			printf("优秀\n");
			break;
		default:
			printf("贼差劲..\n");
			break;
	}
}
