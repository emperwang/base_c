#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>

static void pr_times(clock_t, struct tms *, struct tms *);
static void do_cmd(char *);

// 打印退出状态
void pre_exit(int status){
	if(WIFEXITED(status)){
		printf("normal termination , exit status=%d\n", WEXITSTATUS(status));
	}else if(WIFSIGNALED(status)){
		printf("abnormal termination, signal number=%d , %s\n",WTERMSIG(status),
		#ifdef WCOREDUMP
			WCOREDUMP(status)?"core file generated":"");
		#else
			"");
		#endif
	}else if(WIFSTOPPED(status)){
			printf("child stopped, signal number =%d\n", WSTOPSIG(status));
			}
}

int main(int argc, char *argv[]){
	int i;
	setbuf(stdout, NULL);

	if(argc < 2){
		printf("usage: %s cmd\n", argv[0]);
		exit(0);
	}

	for(i=1; i<argc; i++){
		do_cmd(argv[1]); // prcess cmd
	}
	exit(0);
}

// 记录开始时间，执行命令，记录结束时间
static void do_cmd(char *cmd){ // execute and time the cmd
	struct tms tmsstart, tmsend;

	clock_t start,end;
	int status = 0;

	printf("\ncommand:%s\n", cmd);
	if((start = times(&tmsstart)) == -1){ // starting value
		perror("starting time error\n");
	}

	if((status == system(cmd)) < 0){ // execute command
		perror("execute cmd error\n");
	}

	if((end = times(&tmsend)) == -1){ // ending value; times返回值为墙上时钟时间
		perror("ending time error");
	}

	pr_times(end-start, &tmsstart, &tmsend);
	pre_exit(status);
}

// 打印使用的时间
static void pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend){
	static long clktck = 0;
	if(clktck == 0) { // fetch clock ticks per second first time
		if((clktck = sysconf(_SC_CLK_TCK))<0){ // 每秒对应的clk数
			perror("sysconf error");
		}
	}
	printf(" real:%7.2f\n", real/(double)clktck);
	printf(" user:%7.2f\n",(tmsend->tms_utime - tmsstart->tms_utime)/(double)clktck);
	printf(" sys:%7.2f\n",(tmsend->tms_stime - tmsstart->tms_stime)/(double)clktck);
	printf(" child user:%7.2f\n",(tmsend->tms_cutime - tmsstart->tms_cutime) /(double)clktck);
	printf(" child sys:%7.2f\n", (tmsend->tms_cstime - tmsstart->tms_cstime) / (double)clktck);
}
