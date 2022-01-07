CC=gcc
CUR=$(shell pwd)
flag=-Wall -g -O -I$(CUR)

sources=$(wildcard  *.c)
OBJ=$(patsubst %.c,%.o, $(sources))
objs=*.o
#objs=linklist.o main.o

all:$(OBJ)  main

echo:
	@echo $(OBJ)
	@echo $(sources)

$(OBJ):%.o:%.c
	${CC} ${flag} -c $^ -o $@

main: 
	${CC} -o $@ $(objs)

clean:
	rm -rf *.o main

