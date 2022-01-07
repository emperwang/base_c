CC=gcc
CFLAG=-Wall -g -O

argc: argc.c
	${CC} ${CFLAG}  argc.c  -o argc

variable: variable.c
	${CC} ${CFLAG} variable.c  -o variable

printf:printf.c
	${CC} ${CFLAG} printf.c -o printf

sizeof: sizeof.c
	${CC} ${CFLAG} sizeof.c  -o sizeof

sushu: sushu.c
	${CC} ${CFLAG}  sushu.c  -o sushu

clean:
	rm -f *.o  argc variable printf sizeof sushu

