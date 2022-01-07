CC=gcc
flag=-Wall -g -O

pointer1: pointer1.c
	${CC} ${flag} pointer1.c -o pointer1
pointer2: pointer2.c
	${CC} ${flag} pointer2.c -o pointer2

pointer3:pointer3.c
	${CC} ${flag} pointer3.c -o  pointer3

pointer6:pointer6.c
	${CC} ${flag} pointer6.c -o pointer6

pointer7:pointer7.c
	${CC} ${flag} pointer7.c -o pointer7


mcopy:my_copy.c
	${CC} ${flag} my_copy.c -o mcopy

void:voidp.c
	${CC} ${flag} voidp.c -o voidp

clean:
	rm -rf *.o pointer1 pointer2 pointer3 pointer6 pointer7 mcopy voidp
