CC=gcc
flag=-Wall -g -O

a: a.c
	${CC} ${flag} $< -o $@

strcat:strcat.c
	${CC} ${flag} $<  -o $@

strcmp:strcmp.c
	${CC} ${flag} $< -o $@

strcpy:strcpy.c
	${CC} ${flag} $< -o $@

sort:string_sort.c
	${CC} ${flag} $< -o $@

strlen:strlen.c
	${CC} ${flag} $< -o $@

clean:
	rm -rf *.o a strcat strcmp strcpy  sort strlen
