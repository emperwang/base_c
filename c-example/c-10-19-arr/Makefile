CC=gcc
flag=-Wall -g -O

arrtest: arrtest.c
	${CC} ${flag} arrtest.c -o arrtest

numbase:num_base.c
	${CC} ${flag} $< -o $@

arrplus:arrplus.c
	${CC} ${flag}  $< -o $@

showscore: showscore.c
	${CC} ${flag} $< -o $@

arr_reverse:arr_reverse.c
	${CC} ${flag} $< -o $@

arr:arr.c
	${CC} ${flag} $< -o $@

pointer2:pointer2.c
	${CC} ${flag} $< -o $@

charp:char_pointer.c
	${CC} ${flag} $< -o $@

clean:
	rm -rf *.o arrtest numbase  arrplus showscore arr_reverse arr pointer2 charp
