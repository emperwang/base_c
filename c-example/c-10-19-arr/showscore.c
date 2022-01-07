#include <stdio.h>

/*三个学生，四门功课，求平均成绩；打印第n个学生的成绩*/
void average(int *,int);
void show_n(int (*p)[4], int n);

int main(){
	int arr[3][4] = {
		{99,98,97,96},
		{96,97,98,99},
		{98,96,97,99}
	};
	average(*arr,12);
	show_n(arr,2);

	return 0;
}

void average(int *p,int n){
	int i;
	float sum=0.0;
	for(i=0;i<n;i++){
		sum += *(p+i);
	}
	printf("the average is:%f\n",sum/n);
}

void show_n(int (*p)[4], int n){
	int i =0;
	printf("the %d student's scores is :",n);
	for(i=0;i<4;i++){
		printf("%d\t",*(*(p+n)+i));
	}

	printf("\n");
}

