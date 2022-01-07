cc=gcc
cur=$(shell pwd)
flag=-Wall -g -O -I$(cur)

sources=$(wildcard *.c)
obj=$(patsubst %.c, %.o, $(sources))

all: $(obj) main

$(obj):%.o:%.c
	${cc} ${flag} -c $^ -o $@

main: $(obj)
	${cc} -o $@ $^

clean:
	rm -rf *.o  main
