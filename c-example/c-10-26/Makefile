CC=gcc
flag=-Wall -g -O

args:args.c
	${CC} ${flag} $^ -o $@

srand: srand.c
	${CC} ${flag} $^ -o $@

qsort:qsort.c
	${CC} ${flag} $^ -o $@

clean:
	rm -rf *.o  args srand qsort
