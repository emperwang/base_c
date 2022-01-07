#include<provider.h>


void provid(){
	printf("this is provid service .. ");
}

/**
static定义,那么此函数只能在此源码中使用 
*/
static void provid2(){
	printf("this is provid2 service .. ");
}