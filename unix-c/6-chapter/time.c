#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

// 打印时间
void print_tm(struct tm *t){
	
	printf("tm_isdst: %d \n",t->tm_isdst);
	printf("tm_yday: %d \n",t->tm_yday);
	printf("tm_wday: %d \n",t->tm_wday);
	printf("tm_year: %d \n",t->tm_year);
	printf("tm_mon: %d \n",t->tm_mon);
	printf("tm_mday: %d \n",t->tm_mday);
	printf("tm_hour: %d \n",t->tm_hour);
	printf("tm_min: %d \n",t->tm_min);
	printf("tm_sec: %d \n",t->tm_sec);

	printf("%04d-%02d-%02d  %02d:%02d:%02d\n", t->tm_year+1900,t->tm_mon+1,t->tm_mday,
												 t->tm_hour, t->tm_min, t->tm_sec);
}

/**
 * 获取时间 并打印
 */
int main(){
	
	time_t ptr ;
	// 获取时间，ptr为一个 1970 到现在的秒值
	time(&ptr);
	printf("%lu \n",ptr);
	
	struct tm *ttm;
	ttm = localtime(&ptr);
	
	print_tm(ttm);


	exit(0);
}
