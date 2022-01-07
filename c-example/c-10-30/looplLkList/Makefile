CC=gcc
cur=$(shell pwd)
flag=-Wall -g -O -I$(cur)
sources=$(wildcard *.c)
obj=$(patsubst %.c, %.o, $(sources))
#objs=*.o


all: $(obj)  main

echo:
	@echo $(sources)
	@echo $(obj)
	@echo $(objs)

$(obj):%.o:%.c
	${CC} ${flag} -c $^ -o $@

main: $(obj)
	${CC} -o $@ $^

clean:
	rm -rf *.o main
