CC= gcc
cur=$(shell pwd)
flag=-Wall -g -O -I$(cur)
sources=$(wildcard *.c)
obj=$(patsubst %.c,%.o,$(sources))
objs=*.o

echo:
	@echo $(sources)
	@echo $(obj)

all: $(obj) main

$(obj):%.o:%.c
	${CC} ${flag} -c $^ -o $@

main: $(objs)
	${CC} -o $@ $^

clean:
	rm -rf *.o main
