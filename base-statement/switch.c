#include<stdio.h>
int main(){
	int score,grade;
	printf("please put in the students's score: \n");
	scanf("%d",&score);
	printf("The student's score is %d \n",score);
	
	grade=score/10;
	
	switch(grade){
		case 10: printf("%d---A\n",score); break;
		case 9: printf("%d---B\n",score); break;
		case 8: printf("%d---C\n",score); break;
		case 7: printf("%d---D\n",score); break;
		case 6: printf("%d---E\n",score); break;
		case 5: printf("%d---F\n",score); break;
		case 4: printf("%d---G\n",score); break;
		case 3: printf("%d---H\n",score); break;
		case 2: printf("%d---I\n",score); break;
		case 1: printf("%d---G\n",score); break;
		case 0: printf("%d---K\n",score); break;
		default: printf("The score is wrong.\n"); break;
	}
	
	return 0;
}
